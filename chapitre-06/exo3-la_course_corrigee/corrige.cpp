#include <iostream>
#include <vector>
#include <NKThreading/NkThread.h>
#include <NKTime/NkChrono.h>
#include <NKCore/NkAtomic.h>
#include <NKThreading/NkFuture.h>
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>

using namespace nkentseu;
using namespace nkentseu::time;
using namespace nkentseu::threading;

int main()
{
    //version sans protection
    int compteur_sans_protection = 0;
    NkChrono chrono_sans_protection;
    
    std::vector<NkThread> fils_sans_protection;
    fils_sans_protection.reserve(8);
    
    // Création de huit threads qui partagent le même compteur.
    for (int i = 0; i < 8; ++i)
    {
        fils_sans_protection.emplace_back(
            [&compteur_sans_protection](void*)
            {
                // Chaque thread effectue un million d'incréments.
                for (int j = 0; j < 1000000; ++j)
                {
                    ++compteur_sans_protection;
                }
            });
    }

        // Attendre la fin des huit threads.
        for (auto& fil : fils_sans_protection)
        {
            fil.Join();
        }

        double temps_sans_protection = chrono_sans_protection.Elapsed().ToMilliseconds();

        std::cout << "Total sans protection : "<< compteur_sans_protection << '\n';
        std::cout << "Temps sans protection : "<< temps_sans_protection << " ms" << '\n';

    //-----
    
    
    int compteur_mutex = 0;
    NkMutex mutex;
    NkChrono chrono_mutex;

    std::vector<NkThread> fils_mutex;
    fils_mutex.reserve(8);

    for (int i = 0; i < 8; ++i)
    {
        fils_mutex.emplace_back([&compteur_mutex, &mutex](void*)
        {
            for (int j = 0; j < 1000000; ++j)
            {
                NkScopedLockMutex verrou(mutex);
                ++compteur_mutex;
            }
        });
    }

    for (auto& fil : fils_mutex)
    {
        fil.Join();
    }

    double temps_mutex = chrono_mutex.Elapsed().ToMilliseconds();

    std::cout << "Total avec mutex : " << compteur_mutex << '\n';
    std::cout << "Temps avec mutex : " << temps_mutex << " ms" << '\n';

    NkChrono chrono_atomique;
    NkAtomicInt compteur_atomique(0);

    std::vector<NkThread> fils_atomiques;
    fils_atomiques.reserve(8);

    for (int i = 0; i < 8; ++i)
    {
        fils_atomiques.emplace_back([&compteur_atomique](void*)
        {
            for (int j = 0; j < 1000000; ++j)
            {
                compteur_atomique.FetchAdd(1);
            }
        });
    }

    for (auto& fil : fils_atomiques)
    {
        fil.Join();
    }

    double temps_atomique = chrono_atomique.Elapsed().ToMilliseconds();

    std::cout << "Total atomique : " << compteur_atomique.Load() << '\n';
    std::cout << "Temps atomique : " << temps_atomique << " ms" << '\n';

    // Version locale
    NkChrono chrono_local;

    // Une case de résultat réservée à chaque fil.
    std::vector<int> totaux_locaux(8, 0);

    std::vector<NkThread> fils_locaux;
    fils_locaux.reserve(8);

    // Création des huit fils.
    for (int i = 0; i < 8; ++i)
    {
        fils_locaux.emplace_back([&totaux_locaux, i](void*)
        {
            // Chaque fil possède son propre compteur local.
            int compteur_local = 0;

            for (int j = 0; j < 1000000; ++j)
            {
                ++compteur_local;
            }
            // Chaque fil écrit dans sa propre case.
            totaux_locaux[i] = compteur_local;
        });
    }

    // Attendre la fin de tous les fils.
    for (auto& fil : fils_locaux)
    {
        fil.Join();
    }

    // Additionner les résultats après la fin des fils.
    int total_local = 0;
    for (int i = 0; i < 8; ++i)
    {
        total_local += totaux_locaux[i];
    }

    double temps_local = chrono_local.Elapsed().ToMilliseconds();
    std::cout << "Total local : "<< total_local << '\n';
    std::cout << "Temps local : "<< temps_local << " ms" << '\n';
              
    return 0;
}
