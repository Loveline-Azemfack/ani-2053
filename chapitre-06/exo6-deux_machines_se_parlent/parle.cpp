#include <iostream>
#include <string>
#include <atomic>
#include <thread>
#include <chrono>

#include "NKWindow/NKMain.h"

#include <NKThreading/NkThread.h>
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>
#include <NKThreading/NkFuture.h>
#include <NKThreading/NkThreadPool.h>
#include <NKTime/NkChrono.h>

#include <NKNetwork/NKNetwork.h>
#include <NKNetwork/Protocol/NkConnection.h>

using namespace nkentseu;
using namespace nkentseu::threading;
using namespace nkentseu::time;
using namespace nkentseu::net;

int nkmain(const nkentseu::NkEntryState& state)
{
    // Récupérer les arguments utilisateur.
    const auto args = state.UserArgs();

    if (args.Size() < 1)
    {
        std::cerr << "Utilisation : parle serveur|client [adresse]\n";
        return 1;
    }

    const std::string role = args[0].CStr();

    if (role != "serveur" && role != "client")
    {
        std::cerr << "Role invalide : utilisez serveur ou client.\n";
        return 1;
    }

    // Initialiser le réseau.
    const NkNetResult initResult = NkSocket::PlatformInit();

    if (initResult != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Echec de l'initialisation du reseau : "
                  << NkNetResultStr(initResult) << '\n';
        return 1;
    }

    // Créer le gestionnaire de connexions.
    NkConnectionManager manager;

    std::atomic<bool> connected{false};
    NkPeerId connectedPeer{};

    // Événement déclenché lorsqu'un pair se connecte.
    manager.onPeerConnected = [&](NkPeerId peer)
    {
        std::cout << "Pair connecte : " << peer.value << '\n';

        connectedPeer = peer;
        connected.store(true, std::memory_order_release);
    };

    // ==================================================
    // ROLE SERVEUR
    // ==================================================
    if (role == "serveur")
    {
        const NkNetResult result = manager.StartServer(7777, 8);

        if (result != NkNetResult::NK_NET_OK)
        {
            std::cerr << "Echec du demarrage du serveur : "
                      << NkNetResultStr(result) << '\n';
            return 1;
        }

        std::cout << "Serveur en attente sur le port 7777...\n";

        bool messageReceived = false;

        while (!messageReceived)
        {
            // Récupérer les messages reçus à chaque itération.
            NkVector<NkReceiveMsg> messages;
            manager.DrainAll(messages);

            for (const auto& message : messages)
            {
                const std::string texte(
                    reinterpret_cast<const char*>(message.data),
                    message.size
                );

                std::cout << "Message recu de "
                          << message.from.value
                          << " : " << texte << '\n';

                messageReceived = true;
            }

            std::this_thread::sleep_for(
                std::chrono::milliseconds(10)
            );
        }
    }

    // ==================================================
    // ROLE CLIENT
    // ==================================================
    else
    {
        const char* adresse =
            (args.Size() >= 2)
                ? args[1].CStr()
                : "127.0.0.1";

        // Tester trois méthodes de construction d'adresse.
        const NkAddress adresseServeur(adresse, 7777);
        const NkAddress adresseComposants(127, 0, 0, 1, 7777);
        const NkAddress adresseLoopback = NkAddress::Loopback(7777);

        const NkString texte1 = adresseServeur.ToString();
        const NkString texte2 = adresseComposants.ToString();
        const NkString texte3 = adresseLoopback.ToString();

        std::cout << "\n========== DIAGNOSTIC ADRESSES ==========\n";

        std::cout << "Adresse demandee : "
                  << adresse << '\n';

        std::cout << "Constructeur par chaine : "
                  << texte1.CStr() << '\n';

        std::cout << "Constructeur par composants : "
                  << texte2.CStr() << '\n';

        std::cout << "Constructeur Loopback : "
                  << texte3.CStr() << '\n';

        std::cout << "Validite chaine : "
                  << (adresseServeur.IsValid() ? "oui" : "non")
                  << '\n';

        std::cout << "Validite composants : "
                  << (adresseComposants.IsValid() ? "oui" : "non")
                  << '\n';

        std::cout << "Validite Loopback : "
                  << (adresseLoopback.IsValid() ? "oui" : "non")
                  << '\n';


        // Tester la résolution d'adresse.
        std::cout << "\n========== DIAGNOSTIC RESOLVE ==========\n";

        const auto adressesResolues = NkAddress::Resolve("127.0.0.1", 7777);

        std::cout << "Nombre d'adresses resolues : "
                  << adressesResolues.Size() << '\n';

        for (std::size_t i = 0; i < adressesResolues.Size(); ++i)
        {
            const NkAddress& adresseResolue = adressesResolues[i];

            const NkString texte = adresseResolue.ToString();
            const NkString hote = adresseResolue.HostString();

            std::cout << "Adresse resolue " << i << " : "
                      << texte.CStr() << '\n';

            std::cout << "Hote seul : "
                      << hote.CStr() << '\n';

            std::cout << "Port : "
                      << adresseResolue.Port() << '\n';

            std::cout << "Famille IPv4 : "
                      << (adresseResolue.IsIPv4() ? "oui" : "non") << '\n';

            std::cout << "Loopback : "
                      << (adresseResolue.IsLoopback() ? "oui" : "non") << '\n';

            std::cout << "Adresse valide : "
                      << (adresseResolue.IsValid() ? "oui" : "non")
                      << '\n';
        }

        std::cout << "========================================\n\n";



        // Utiliser provisoirement l'adresse fournie en argument.
        const NkNetResult result = manager.Connect(adresseServeur);

        if (result != NkNetResult::NK_NET_OK)
        {
            std::cerr << "Echec de la demande de connexion : "
                      << NkNetResultStr(result) << '\n';
            return 1;
        }

        std::cout << "Connexion demandee a "
                  << adresse << ":7777\n";

        // Attendre que la connexion soit effectivement établie.
        const auto deadline =
            std::chrono::steady_clock::now()
            + std::chrono::seconds(15);

        while (!connected.load(std::memory_order_acquire)
               && std::chrono::steady_clock::now() < deadline)
        {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(10)
            );
        }

        if (!connected.load(std::memory_order_acquire))
        {
            std::cerr
                << "Delai depasse : aucun pair connecte.\n";
            return 1;
        }

        // Envoyer un message au serveur.
        const std::string texte = "Bonjour serveur !";

        const NkNetResult sendResult = manager.SendTo(
            connectedPeer,
            reinterpret_cast<const uint8*>(texte.data()),
            static_cast<uint32>(texte.size())
        );

        if (sendResult != NkNetResult::NK_NET_OK)
        {
            std::cerr << "Echec de l'envoi : "
                      << NkNetResultStr(sendResult) << '\n';
            return 1;
        }

        std::cout << "Message envoye : "
                  << texte << '\n';

        // Laisser le temps au gestionnaire réseau de traiter l'envoi.
        std::this_thread::sleep_for(
            std::chrono::milliseconds(500)
        );
    }

    return 0;
}