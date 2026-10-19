#include <NKNetwork/Protocol/NkConnection.h>
#include <NKTime/NkChrono.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <vector>

using namespace nkentseu;
using namespace nkentseu::net;

constexpr uint16 PORT = 7789;
constexpr int NOMBRE_MESURES = 100;
constexpr double ALPHA = 0.125;
constexpr double SRTT_INITIAL = 100.0;
constexpr int DELAI_CONNEXION_MS = 10000;
constexpr int DELAI_REPONSE_MS = 3000;

// Transforme un entier en tableau d'octets.
void EncoderNumero(uint32 numero, uint8* donnees)
{
    donnees[0] = static_cast<uint8>((numero >> 24) & 0xFF);
    donnees[1] = static_cast<uint8>((numero >> 16) & 0xFF);
    donnees[2] = static_cast<uint8>((numero >> 8) & 0xFF);
    donnees[3] = static_cast<uint8>(numero & 0xFF);
}

// Reconstruit le numéro contenu dans un message.
uint32 DecoderNumero(const uint8* donnees)
{
    return (static_cast<uint32>(donnees[0]) << 24)
         | (static_cast<uint32>(donnees[1]) << 16)
         | (static_cast<uint32>(donnees[2]) << 8)
         | static_cast<uint32>(donnees[3]);
}

// Attend qu'une connexion soit établie.
bool AttendreConnexion(NkConnectionManager& gestionnaire, bool serveur)
{
    NkChrono chrono;

    while (chrono.Elapsed().milliseconds < DELAI_CONNEXION_MS)
    {
        if (serveur)
        {
            if (gestionnaire.ConnectedPeerCount() > 0)
                return true;
        }
        else
        {
            NkPeerId serveurId{};
            serveurId.value = 1;

            NkConnectionStats statistiques{};
            if (gestionnaire.GetConnectionStats(serveurId, statistiques))
                return true;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return false;
}

// Mode serveur : renvoie chaque message à son expéditeur.
int ExecuterServeur()
{
    NkConnectionManager gestionnaire;

    const NkNetResult resultat = gestionnaire.StartServer(PORT, 1);

    if (resultat != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Erreur : impossible de démarrer le serveur sur le port "
                  << PORT << ".\n";
        return 1;
    }

    std::cout << "Serveur démarré sur le port " << PORT << ".\n";
    std::cout << "En attente du client...\n";

    if (!AttendreConnexion(gestionnaire, true))
    {
        std::cerr << "Délai dépassé : aucun client connecté.\n";
        gestionnaire.Shutdown();
        return 1;
    }

    std::cout << "Client connecté. Écho activé.\n";

    int nombreReponses = 0;
    NkChrono inactivite;

    while (gestionnaire.IsRunning() &&
           nombreReponses < NOMBRE_MESURES)
    {
        NkVector<NkReceiveMsg> messages;
        gestionnaire.DrainAll(messages);

        for (const auto& message : messages)
        {
            if (message.size != sizeof(uint32))
                continue;

            const NkNetResult envoi = gestionnaire.SendTo(
                message.from,
                message.data,
                message.size,
                message.channel);

            if (envoi == NkNetResult::NK_NET_OK)
            {
                ++nombreReponses;
                inactivite.Reset();
                std::cout << "Réponse " << nombreReponses
                          << "/" << NOMBRE_MESURES << "\n";
            }
            else
            {
                std::cerr << "Erreur lors du renvoi du message.\n";
            }
        }

        if (inactivite.Elapsed().milliseconds > 15000)
        {
            std::cerr << "Délai d'inactivité dépassé.\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    // Laisse au client le temps de recevoir la dernière réponse.
    if (nombreReponses == NOMBRE_MESURES)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


    gestionnaire.DisconnectAll("Fin des mesures");
    gestionnaire.Shutdown();

    std::cout << "Serveur arrêté. Réponses envoyées : "
              << nombreReponses << ".\n";

    return nombreReponses == NOMBRE_MESURES ? 0 : 1;
}

// Mode client : effectue les 100 mesures séquentiellement.
int ExecuterClient()
{
    NkConnectionManager gestionnaire;

    const NkNetResult resultat = gestionnaire.Connect(
        NkAddress("127.0.0.1", PORT));

    if (resultat != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Erreur : impossible d'initialiser la connexion.\n";
        return 1;
    }

    std::cout << "Connexion au serveur local sur le port "
              << PORT << "...\n";

    if (!AttendreConnexion(gestionnaire, false))
    {
        std::cerr << "La connexion n'a pas été établie dans le délai prévu.\n";
        gestionnaire.Shutdown();
        return 1;
    }

    NkPeerId serveur{};
    serveur.value = 1;

    std::cout << "Connexion établie. Début des mesures.\n";

    std::vector<double> mesures;
    mesures.reserve(NOMBRE_MESURES);

    for (uint32 numero = 1; numero <= NOMBRE_MESURES; ++numero)
    {
        uint8 donnees[sizeof(uint32)]{};
        EncoderNumero(numero, donnees);

        NkChrono chrono;

        const NkNetResult envoi = gestionnaire.SendTo(
            serveur,
            donnees,
            sizeof(donnees),
            NkNetChannel::NK_NET_CHANNEL_RELIABLE_ORDERED);

        if (envoi != NkNetResult::NK_NET_OK)
        {
            std::cerr << "Échec de l'envoi du message "
                      << numero << ".\n";
            gestionnaire.Shutdown();
            return 1;
        }

        bool reponseRecue = false;
        NkChrono attente;

        while (attente.Elapsed().milliseconds < DELAI_REPONSE_MS)
        {
            NkVector<NkReceiveMsg> messages;
            gestionnaire.DrainAll(messages);

            for (const auto& message : messages)
            {
                if (message.size != sizeof(uint32))
                    continue;

                if (DecoderNumero(message.data) != numero)
                    continue;

                const double duree =
                    chrono.Elapsed().ToMilliseconds();

                mesures.push_back(duree);
                reponseRecue = true;
                break;
            }

            if (reponseRecue)
                break;

            std::this_thread::sleep_for(
                std::chrono::microseconds(100));
        }

        if (!reponseRecue)
        {
            std::cerr << "Délai dépassé pour la réponse "
                      << numero << ".\n";
            gestionnaire.Shutdown();
            return 1;
        }

        std::cout << "Mesure " << numero << "/"
                  << NOMBRE_MESURES << " : "
                  << std::fixed << std::setprecision(6)
                  << mesures.back() << " ms\n";
    }

    NkConnectionStats statistiquesMoteur{};
    const bool statistiquesDisponibles =
        gestionnaire.GetConnectionStats(serveur, statistiquesMoteur);

    gestionnaire.DisconnectAll("Fin des mesures");
    gestionnaire.Shutdown();

    if (mesures.size() != NOMBRE_MESURES)
    {
        std::cerr << "Erreur : les 100 mesures ne sont pas disponibles.\n";
        return 1;
    }

    // Enregistre exactement une mesure numérique par ligne.
    std::ofstream fichierMesures("mesures-rtt.txt");

    if (!fichierMesures)
    {
        std::cerr << "Impossible de créer mesures-rtt.txt.\n";
        return 1;
    }

    fichierMesures << std::fixed << std::setprecision(6);

    for (double mesure : mesures)
        fichierMesures << mesure << '\n';

    fichierMesures.close();

    const double somme =
        [&mesures]()
        {
            double resultat = 0.0;
            for (double valeur : mesures)
                resultat += valeur;
            return resultat;
        }();

    const double moyenne = somme / mesures.size();

    const double minimum =
        *std::min_element(mesures.begin(), mesures.end());

    const double maximum =
        *std::max_element(mesures.begin(), mesures.end());

    // Lissage exponentiel demandé dans l'énoncé.
    double srtt = SRTT_INITIAL;

    for (double mesure : mesures)
        srtt = (1.0 - ALPHA) * srtt + ALPHA * mesure;

    const double rttMoteur = statistiquesDisponibles
        ? statistiquesMoteur.rttMs
        : std::numeric_limits<double>::quiet_NaN();

    const double ecart = statistiquesDisponibles
        ? std::fabs(srtt - rttMoteur)
        : std::numeric_limits<double>::quiet_NaN();

    std::ofstream rapport("rtt.txt");

    if (!rapport)
    {
        std::cerr << "Impossible de créer rtt.txt.\n";
        return 1;
    }

    rapport << std::fixed << std::setprecision(6);
    rapport << "Moyenne : " << moyenne << " ms\n";
    rapport << "Minimum : " << minimum << " ms\n";
    rapport << "Maximum : " << maximum << " ms\n";
    rapport << "Lissée : " << srtt << " ms\n";

    if (statistiquesDisponibles)
        rapport << "Moteur : " << rttMoteur << " ms\n";
    else
        rapport << "Moteur : indisponible\n";

    rapport << "Écart : ";

    if (statistiquesDisponibles)
    {
        rapport << ecart << " ms. L'écart vient de la différence entre "
                << "les mesures applicatives aller-retour et l'estimation "
                << "du moteur, mise à jour dans "
                << "NkConnectionManager::NetThreadLoop, dans "
                << "NkConnection.cpp. Les deux valeurs peuvent différer "
                << "à cause de leur méthode de mesure et de lissage.\n";
    }
    else
    {
        rapport << "impossible à calculer, car les statistiques du moteur "
                << "n'étaient pas disponibles au moment de la lecture. "
                << "La valeur doit être vérifiée après une connexion active.\n";
    }

    rapport.close();

    std::cout << "\nMesures terminées.\n";
    std::cout << "Moyenne : " << moyenne << " ms\n";
    std::cout << "Minimum : " << minimum << " ms\n";
    std::cout << "Maximum : " << maximum << " ms\n";
    std::cout << "Lissée : " << srtt << " ms\n";

    if (statistiquesDisponibles)
        std::cout << "Moteur : " << rttMoteur << " ms\n";
    else
        std::cout << "Moteur : indisponible\n";

    std::cout << "Fichiers créés : mesures-rtt.txt et rtt.txt\n";

    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Utilisation :\n"
                  << "  allerretour.exe serveur\n"
                  << "  allerretour.exe client\n";
        return 0;
    }

    const std::string mode = argv[1];

    if (mode == "serveur")
        return ExecuterServeur();

    if (mode == "client")
        return ExecuterClient();

    std::cerr << "Mode inconnu. Utilisez serveur ou client.\n";
    return 1;
}