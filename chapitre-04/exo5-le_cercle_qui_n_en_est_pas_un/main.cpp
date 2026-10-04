
#include <iostream>
#include <cmath>

int main(){
    int N;
    const double pi = 3.141592653589793;
    std::cin >> N;
    int TotalRefus = 0;
    int TotalVisibles = 0;


    for (int i = 0; i < N; i++){
        int r, n;
        std::cin >> r >> n;
        if (n < 3){
            std::cout << r <<" "<<n << " REFUSE\n" << std::endl;
            TotalRefus++;
            continue;
        }
        double g = r * (1 - cos(pi / n));

        int ecart = static_cast<int>(floor(g * 1000.0)); //floor c'est pour l'arrondi vers le bas
        int zoom;
        if (g == 0){
            std::cout<<r << " " << n << " "<< ecart << " JAMAIS"<<std::endl;
        }else {
            zoom = static_cast<int>(ceil(100/g));
            ecart = ecart*(zoom/100);
        }

        if(zoom <= 100){
            std::cout << r << " " << n << " " << ecart << " " << zoom << " VISIBLE\n";
            TotalVisibles++;
        }else{
            std::cout << r << " " << n << " " << ecart << " " << zoom << " INVISIBLE\n";
        }
    }

    std::cout << "VISIBLES " << TotalVisibles << "\n";
    std::cout << "REFUSES " << TotalRefus << "\n";

    return 0;
}