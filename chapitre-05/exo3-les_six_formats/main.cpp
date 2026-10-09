#include <iostream>
#include <string>

int main(){
    long long w, h, nombre_Total_pixel;
    int N;
    int REFUSES = 0;
    long long Octets_Par_Pixel_source;
    long long Octets_Par_Pixel_cible;
    int sans_perte = 0;
    long long TOTAL = 0;

    std::string format[6] = {"GRAY8", "GRAY_A16", "RGB24", "RGBA32", "RGB96F", "RGBA128F" };
    int Octets_Par_Pixel[6] = {1, 2, 3, 4, 12, 16};
    bool Couleur[6] = {false, false, true, true, true, true};
    bool Transparence[6] = {false, true, false, true, false, true};
    bool Flottants[6] = {false, false, false, false, true, true};

    std::cin>>w >> h;
    std::cin >> N;
    nombre_Total_pixel = w *h;

    for (int i = 0; i< N; i++){
        std::string SOURCE, CIBLE;
        int source_index = -1;
        int cible_index = -1;
        std::cin>> SOURCE >> CIBLE;

        for (int j = 0; j < 6; j++){
            if(SOURCE == format[j] ){
                source_index = j;
                Octets_Par_Pixel_source = Octets_Par_Pixel[j];
            }
            if(CIBLE == format[j] ){
                cible_index = j;
                Octets_Par_Pixel_cible = Octets_Par_Pixel[j];
            }

        }
        if(source_index == -1  || cible_index == -1){
            std::cout << SOURCE << " " << CIBLE << " REFUSE" << std::endl;
            REFUSES++;
        }else{

            //calcul de la memoire de la source
            long long octets_source = Octets_Par_Pixel_source * nombre_Total_pixel;
            //calcul de la memoire de la cible
            long long octets_cible = Octets_Par_Pixel_cible * nombre_Total_pixel;
            std::string pertes = "";
            //recherche des pertes
            if(Transparence[source_index] && !Transparence[cible_index]){
                pertes = "TRANSPARENCE";
            }
            if(Couleur[source_index] && !Couleur[cible_index]){
                if(pertes != ""){
                    pertes += "+";
                }
                pertes += "COULEUR";
            }
            if(Flottants[source_index] && !Flottants[cible_index]){
                if(pertes != ""){
                    pertes += "+";
                }
                pertes += "ETENDUE";
            }
            if (pertes == ""){
                pertes = "AUCUNE";
                sans_perte++;
            }

            TOTAL += octets_cible;
            std::cout<< SOURCE << " "<< CIBLE << " "<< octets_source << " "<< octets_cible<< " "<< pertes<< std::endl;
        }
    }
    std::cout << "TOTAL "<< TOTAL<< std::endl;
    std::cout<< "SANS_PERTE "<< sans_perte << std::endl;
    std::cout << "REFUSES "<< REFUSES<< std::endl;
    return 0;
}