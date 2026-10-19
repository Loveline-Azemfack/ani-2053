#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdint>
#include <cstring>

#include "NKNetwork/Protocol/NkBitStream.h"
#include "NKNetwork/Transport/NkSocket.h"

using namespace nkentseu;
using namespace nkentseu::net;

// Ports utilisés pour distinguer les deux paquets.
constexpr uint16 PORT_COMPLET = 7777;
constexpr uint16 PORT_QUANTIFIE = 7778;

// État du joueur utilisé pour les deux encodages.
struct EtatJoueur
{
    bool vivant = true;
    uint8 numero = 42;
    float32 x = 123.456f;
    float32 y = -78.912f;
    float32 angle = 123.4f;
    int32 sante = 87;
};

// Affiche les tailles d'un paquet.
void AfficherTaille(
    const char* nom,
    const NkBitWriter& writer)
{
    std::cout << nom << '\n';
    std::cout << "  Octets : " << writer.BytesWritten() << '\n';
    std::cout << "  Bits   : " << writer.BitsWritten() << "\n\n";
}

// Écrit les données avec les types complets.
uint32 EncoderComplet(
    const EtatJoueur& joueur,
    uint8* buffer,
    uint32 capacite)
{
    NkBitWriter writer(buffer, capacite);

    writer.WriteU8(joueur.vivant ? 1 : 0);
    writer.WriteU8(joueur.numero);

    writer.WriteF32(joueur.x);
    writer.WriteF32(joueur.y);
    writer.WriteF32(joueur.angle);

    writer.WriteI32(joueur.sante);

    if (writer.IsOverflowed())
    {
        std::cerr << "Erreur : debordement du paquet complet.\n";
        return 0;
    }

    AfficherTaille("Paquet avec types complets :", writer);

    return writer.BytesWritten();
}

// Écrit les données avec les types quantifiés.
uint32 EncoderQuantifie(
    const EtatJoueur& joueur,
    uint8* buffer,
    uint32 capacite)
{
    NkBitWriter writer(buffer, capacite);

    writer.WriteBool(joueur.vivant);
    writer.WriteU8(joueur.numero);

    writer.WriteF32Q(joueur.x, -500.0f, 500.0f, 0.01f);
    writer.WriteF32Q(joueur.y, -500.0f, 500.0f, 0.01f);
    writer.WriteF32Q(joueur.angle, 0.0f, 360.0f, 0.5f);

    writer.WriteInt(joueur.sante, 0, 100);

    if (writer.IsOverflowed())
    {
        std::cerr << "Erreur : debordement du paquet quantifie.\n";
        return 0;
    }

    AfficherTaille("Paquet quantifie :", writer);

    return writer.BytesWritten();
}

// Envoie les deux paquets au récepteur.
int Emettre()
{
    if (NkSocket::PlatformInit() != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Impossible d'initialiser le reseau.\n";
        return 1;
    }

    NkSocket socketEmission;

    if (socketEmission.Create(
            NkAddress::Any(0),
            NkSocket::Type::NK_UDP) != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Impossible de creer le socket d'emission.\n";
        NkSocket::PlatformShutdown();
        return 1;
    }

    EtatJoueur joueur;

    uint8 bufferComplet[256]{};
    uint8 bufferQuantifie[256]{};

    const uint32 tailleComplete = EncoderComplet(
        joueur,
        bufferComplet,
        sizeof(bufferComplet));

    const uint32 tailleQuantifiee = EncoderQuantifie(
        joueur,
        bufferQuantifie,
        sizeof(bufferQuantifie));

    if (tailleComplete == 0 || tailleQuantifiee == 0)
    {
        socketEmission.Close();
        NkSocket::PlatformShutdown();
        return 1;
    }

    const NkAddress destinationComplete =
        NkAddress::Loopback(PORT_COMPLET);

    const NkAddress destinationQuantifiee =
        NkAddress::Loopback(PORT_QUANTIFIE);

    if (socketEmission.SendTo(
            bufferComplet,
            tailleComplete,
            destinationComplete) != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Echec de l'envoi du paquet complet.\n";
        socketEmission.Close();
        NkSocket::PlatformShutdown();
        return 1;
    }

    std::cout << "Paquet complet envoye : "
              << tailleComplete << " octets.\n";

    if (socketEmission.SendTo(
            bufferQuantifie,
            tailleQuantifiee,
            destinationQuantifiee) != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Echec de l'envoi du paquet quantifie.\n";
        socketEmission.Close();
        NkSocket::PlatformShutdown();
        return 1;
    }

    std::cout << "Paquet quantifie envoye : "
              << tailleQuantifiee << " octets.\n";

    socketEmission.Close();
    NkSocket::PlatformShutdown();

    return 0;
}

// Reçoit et relit le paquet encodé avec les types complets.
bool RecevoirComplet(
    NkSocket& socketReception,
    const EtatJoueur& original,
    EtatJoueur& relu,
    uint32& tailleRecue)
{
    uint8 buffer[256]{};
    NkAddress adresseExpediteur;
    tailleRecue = 0;

    const NkNetResult resultat = socketReception.RecvFrom(
        buffer,
        sizeof(buffer),
        tailleRecue,
        adresseExpediteur);

    if (resultat != NkNetResult::NK_NET_OK || tailleRecue == 0)
    {
        std::cerr << "Erreur lors de la reception du paquet complet.\n";
        return false;
    }

    NkBitReader reader(buffer, tailleRecue);

    relu.vivant = reader.ReadU8() != 0;
    relu.numero = reader.ReadU8();

    relu.x = reader.ReadF32();
    relu.y = reader.ReadF32();
    relu.angle = reader.ReadF32();

    relu.sante = reader.ReadI32();

    if (reader.IsOverflowed())
    {
        std::cerr << "Erreur de lecture du paquet complet.\n";
        return false;
    }

    std::cout << "\n=== RECEPTION : TYPES COMPLETS ===\n";
    std::cout << "Taille recue : " << tailleRecue << " octets\n";
    std::cout << "Vivant : " << std::boolalpha << relu.vivant << '\n';
    std::cout << "Numero : " << static_cast<int>(relu.numero) << '\n';
    std::cout << "Position X : " << relu.x << '\n';
    std::cout << "Position Y : " << relu.y << '\n';
    std::cout << "Angle : " << relu.angle << '\n';
    std::cout << "Sante : " << relu.sante << '\n';

    return true;
}

// Reçoit et relit le paquet quantifié.
bool RecevoirQuantifie(
    NkSocket& socketReception,
    const EtatJoueur& original,
    EtatJoueur& relu,
    uint32& tailleRecue)
{
    uint8 buffer[256]{};
    NkAddress adresseExpediteur;
    tailleRecue = 0;

    const NkNetResult resultat = socketReception.RecvFrom(
        buffer,
        sizeof(buffer),
        tailleRecue,
        adresseExpediteur);

    if (resultat != NkNetResult::NK_NET_OK || tailleRecue == 0)
    {
        std::cerr << "Erreur lors de la reception du paquet quantifie.\n";
        return false;
    }

    NkBitReader reader(buffer, tailleRecue);

    relu.vivant = reader.ReadBool();
    relu.numero = reader.ReadU8();

    relu.x = reader.ReadF32Q(-500.0f, 500.0f, 0.01f);
    relu.y = reader.ReadF32Q(-500.0f, 500.0f, 0.01f);
    relu.angle = reader.ReadF32Q(0.0f, 360.0f, 0.5f);

    relu.sante = reader.ReadInt(0, 100);

    if (reader.IsOverflowed())
    {
        std::cerr << "Erreur de lecture du paquet quantifie.\n";
        return false;
    }

    std::cout << "\n=== RECEPTION : PAQUET QUANTIFIE ===\n";
    std::cout << "Taille recue : " << tailleRecue << " octets\n";
    std::cout << "Vivant : " << std::boolalpha << relu.vivant << '\n';
    std::cout << "Numero : " << static_cast<int>(relu.numero) << '\n';
    std::cout << "Position X : " << relu.x << '\n';
    std::cout << "Position Y : " << relu.y << '\n';
    std::cout << "Angle : " << relu.angle << '\n';
    std::cout << "Sante : " << relu.sante << '\n';

    return true;
}

// Affiche les écarts entre les valeurs initiales et les valeurs relues.
void AfficherEcarts(
    const EtatJoueur& original,
    const EtatJoueur& reluComplet,
    const EtatJoueur& reluQuantifie)
{
    auto ecart = [](float32 a, float32 b)
    {
        return std::fabs(a - b);
    };

    std::cout << std::fixed << std::setprecision(6);

    std::cout << "\n=== ECARTS OBSERVES ===\n";

    std::cout << "Vivant, paquet complet : "
              << (original.vivant == reluComplet.vivant ? 0 : 1)
              << '\n';

    std::cout << "Vivant, paquet quantifie : "
              << (original.vivant == reluQuantifie.vivant ? 0 : 1)
              << '\n';

    std::cout << "Numero, paquet complet : "
              << std::abs(
                    static_cast<int>(original.numero) -
                    static_cast<int>(reluComplet.numero))
              << '\n';

    std::cout << "Numero, paquet quantifie : "
              << std::abs(
                    static_cast<int>(original.numero) -
                    static_cast<int>(reluQuantifie.numero))
              << '\n';

    std::cout << "X, paquet complet : "
              << ecart(original.x, reluComplet.x) << '\n';

    std::cout << "X, paquet quantifie : "
              << ecart(original.x, reluQuantifie.x) << '\n';

    std::cout << "Y, paquet complet : "
              << ecart(original.y, reluComplet.y) << '\n';

    std::cout << "Y, paquet quantifie : "
              << ecart(original.y, reluQuantifie.y) << '\n';

    std::cout << "Angle, paquet complet : "
              << ecart(original.angle, reluComplet.angle) << '\n';

    std::cout << "Angle, paquet quantifie : "
              << ecart(original.angle, reluQuantifie.angle) << '\n';

    std::cout << "Sante, paquet complet : "
              << std::abs(original.sante - reluComplet.sante) << '\n';

    std::cout << "Sante, paquet quantifie : "
              << std::abs(original.sante - reluQuantifie.sante) << '\n';
}

// Programme récepteur : écoute sur les deux ports UDP.
int Recevoir()
{
    if (NkSocket::PlatformInit() != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Impossible d'initialiser le reseau.\n";
        return 1;
    }

    NkSocket socketComplet;
    NkSocket socketQuantifie;

    if (socketComplet.Create(
            NkAddress::Any(PORT_COMPLET),
            NkSocket::Type::NK_UDP) != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Impossible d'ouvrir le port "
                  << PORT_COMPLET << ".\n";
        NkSocket::PlatformShutdown();
        return 1;
    }

    if (socketQuantifie.Create(
            NkAddress::Any(PORT_QUANTIFIE),
            NkSocket::Type::NK_UDP) != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Impossible d'ouvrir le port "
                  << PORT_QUANTIFIE << ".\n";
        socketComplet.Close();
        NkSocket::PlatformShutdown();
        return 1;
    }

    std::cout << "Recepteur pret.\n";
    std::cout << "En attente des deux paquets UDP...\n";

    const EtatJoueur original{};

    EtatJoueur reluComplet{};
    EtatJoueur reluQuantifie{};

    uint32 tailleComplete = 0;
    uint32 tailleQuantifiee = 0;

    const bool completRecu = RecevoirComplet(
        socketComplet,
        original,
        reluComplet,
        tailleComplete);

    const bool quantifieRecu = RecevoirQuantifie(
        socketQuantifie,
        original,
        reluQuantifie,
        tailleQuantifiee);

    if (completRecu && quantifieRecu)
    {
        AfficherEcarts(original, reluComplet, reluQuantifie);
    }

    socketComplet.Close();
    socketQuantifie.Close();

    NkSocket::PlatformShutdown();

    return completRecu && quantifieRecu ? 0 : 1;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Utilisation :\n";
        std::cout << "  octets.exe emetteur\n";
        std::cout << "  octets.exe recepteur\n";
        return 0;
    }

    if (std::strcmp(argv[1], "emetteur") == 0)
    {
        return Emettre();
    }

    if (std::strcmp(argv[1], "recepteur") == 0)
    {
        return Recevoir();
    }

    std::cerr << "Mode inconnu. Utilisez emetteur ou recepteur.\n";
    return 1;
}