#include <iostream>
#include <vector>
#include <NKThreading/NkThread.h>

using namespace nkentseu;
using namespace nkentseu::threading;

int main()
{
    int compteur = 0;

    // Deuxième expérience : 200 fils individuels
    std::vector<NkThread> fils;
    fils.reserve(8);
    
    for(int i = 0; i < 8; ++i){
        fils.emplace_back([&compteur](void*){ //on construit l'objet directement dans le vecteur et on met &compteur pour qu'un fil puisse acceder au compteur qu est partager
        //donc on capture la variable par reference
            for(int j = 0; j < 1000000; ++j){
                compteur += 1;
            }
        });
    }
    for(auto &fil : fils){
        fil.Join();
    }
    
    std::cout << "Total obtenu : " << compteur << '\n';
    std::cout << "Total attendu : " << 8000000 << '\n';
    
    return 0;
}