#include <iostream>
#include <string>
#include <cmath>

int main(){

    long long S;
    int N;

    std::string nom;
    long long frequence, canaux, bits, duree, fichier;
    int Tab_bits[4] = {8, 16, 24, 32};
    bool bits_trouve = false;
    int refuses = 0;
    bool sons_memoire = false;
    bool sons_Flux = false;
    long long Total_flux = 0;
    long long Total_Memoire = 0;
    int flux = 0;
    int memoire = 0;

    std::cin>> S;
    std::cin>> N;
    for (int i = 0; i < N; i++){
        std::cin>>nom>> frequence>> canaux>> bits>>duree>>fichier;
        bits_trouve = false;

        for (int j = 0; j < 4; j++){
            if (bits == Tab_bits[j]){
                bits_trouve = true;
                break;
            }
        }

        if(bits_trouve == false){
            std::cout << nom << " REFUSE" << std::endl;
            refuses++;
            continue;
        }

        long long taille = (frequence * canaux * (bits / 8) * duree) / 1000;
        long long brut = taille;
        long long pourcent = (fichier * 100) / brut;

        if (taille > S){
            sons_Flux = true;
            std::cout << nom << " " << brut << " " << pourcent << " FLUX" << std::endl;
            Total_flux = Total_flux + taille;
            flux++;
        } else{
            sons_memoire = true;
            std::cout << nom << " " << brut << " " << pourcent << " MEMOIRE" << std::endl;
            Total_Memoire += taille;
            memoire++;
        }
    }

    std::cout << "MEMOIRE " << Total_Memoire << std::endl;
    std::cout << "FLUX "<< flux<< std::endl;
    std::cout << "REFUSES "<< refuses << std::endl;
    return 0;
}