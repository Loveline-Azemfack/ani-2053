#include <iostream>
#include <vector>
#include <NKThreading/NkThread.h>
//#include <NKThreading/NKThreading.h>
#include <NKThreading/NkThreadPool.h>
#include <NKTime/NkChrono.h>

using namespace nkentseu;
using namespace nkentseu::threading;

//using namespace nkentseu::renderer;
using namespace nkentseu::threading;

long long CalculerSomme() {
    /*Ici, volatile indique au compilateur que les accès à cette variable doivent être conservés,
     * ce qui limite sa capacité à supprimer les opérations sur cette variable. Cela rend le calcul
     * plus représentatif du travail que nous souhaitons mesurer.
     */
    volatile long long somme = 0;

    for (int repetition = 0; repetition < 100; ++repetition) {
        for (int i = 0; i <= 1000; ++i) {
            somme += i;
        }
    }

    return somme;
}

int main()
{
    NkThreadPool reserve(4);
    std::vector<long long> resultats(200);

    std::cout << "Nombre d'ouvriers : "<< reserve.GetNumWorkers() << '\n';

    NkChrono chrono_reserve;

    for (int i = 0; i < 200; ++i) {
        reserve.Enqueue([i, &resultats]() {
            resultats[i] = CalculerSomme();
        });
    }

   reserve.Join();

   double temps_reserve = chrono_reserve.Elapsed().ToMilliseconds();

   long long verification_reserve = 0;
   for (long long resultat : resultats) {
       verification_reserve += resultat;
   }

   std::cout << "Vérification réserve : "<< verification_reserve << '\n';
             
    std::cout << "Temps de la reserve : "<< temps_reserve << " ms\n";


    // Deuxième expérience : 200 fils individuels
    std::vector<NkThread> fils;
    fils.reserve(200);
    
    NkChrono chrono_fils;
    
    /*Nous allons créer un tableau de 200 résultats, 
     * puis demander à chaque tâche d'y enregistrer son résultat. 
     * Chaque tâche utilisera une case différente.
     */
    for (int i = 0; i < 200; ++i) {
        fils.emplace_back([i, &resultats](void*) {//celle ci cree a chaque fois un fil individuel et lui confie le calcul
            resultats[i] = CalculerSomme();
        });
    }
    
    for (auto& fil : fils) {
        fil.Join();
    }

    double temps_fils = chrono_fils.Elapsed().ToMilliseconds();

    long long verification_fils = 0;
    for (long long resultat : resultats) {
        verification_fils += resultat;
    }

    std::cout << "Vérification fils : "<< verification_fils << '\n';          
    
    std::cout << "Temps des fils individuels : "<< temps_fils << " ms\n";
            
    
    return 0;
}