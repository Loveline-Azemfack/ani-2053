
#include <iostream>

int main()
{
    int caseCourante = 0;
    int tempsAccumule = 0;

    int avances = 0;
    int plafonnes = 0;

    int dt;
    int C, R, W , H , F , D , P, N;
    std::cin >>C >> R >> W >> H >> F >> D >> P;
    std::cin>> N;

    for(int i =0; i < N; i++){
        std::cin>>dt;
        if(dt>P){
            dt = P;
            plafonnes++; // on a rencontree un dt plafonné
        }

        tempsAccumule += dt;
        while ( tempsAccumule >= D)
        {
            tempsAccumule -= D;
            caseCourante++;
            if(caseCourante == F ){
                caseCourante = 0;
            }
            avances++;
        }

        int colonneCase = caseCourante % C;
        int ligneCase = caseCourante / C;

        int x = colonneCase * W;
        int y = ligneCase * H;

        std::cout << caseCourante << " "<< x << " "<< y << " "<< W << " "<< H << std::endl;
    }

    std::cout << "AVANCES " << avances << std::endl;
    std::cout << "PLAFONNES " << plafonnes << std::endl;

    return 0;
}