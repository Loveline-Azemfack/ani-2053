#include <iostream>
#include <string>

struct Police
{
    std::string nom;
    int n, w, h;
    int x1, y1, x2, y2;
};

int main()
{
    int P, L, G;
    std::cin >> P >> L;
    std::cin >> G;

    if (G == 0)
    {
        std::cout << "AUCUN" << std::endl;
        return 0;
    }

    Police GroupePolices[100];
    int besoin = 0;
    int occupe = 0;

    for (int i = 0; i < G; i++)
    {
        std::cin >> GroupePolices[i].nom>> GroupePolices[i].n>> GroupePolices[i].w>> GroupePolices[i].h;
        besoin += int(GroupePolices[i].n)* (GroupePolices[i].w + P)* (GroupePolices[i].h + P);
        occupe += int(GroupePolices[i].n)* GroupePolices[i].w* GroupePolices[i].h;
    }

    int W = L;

    if (L == 0)
    {
        W = 512;
        while (int64_t(W) * W < 2 * besoin && W < 4096)
        {
            W = W * 2;
        }
    }

    int H = W;
    int essais = 0;
    bool reussi = false;

    while (essais < 8 && !reussi)
    {
        essais++;
        int x = P;
        int y = P;
        int e = 0;
        bool possible = true;

        for (int i = 0; i < G && possible; i++)
        {
            int rw = GroupePolices[i].w + P;
            int rh = GroupePolices[i].h + P;

            for (int j = 0; j < GroupePolices[i].n; j++)
            {
                if (x + rw > W - P)
                {
                    x = P;
                    y = y + e + P;
                    e = 0;
                }

                if (x + rw > W - P)
                {
                    possible = false;
                    break;
                }

                if (y + rh > H - P)
                {
                    possible = false;
                    break;
                }

                if (j == 0)
                {
                    GroupePolices[i].x1 = x;
                    GroupePolices[i].y1 = y;
                }

                GroupePolices[i].x2 = x;
                GroupePolices[i].y2 = y;

                x += rw;

                if (rh > e)
                {
                    e = rh;
                }
            }
        }

        if (possible)
        {
            reussi = true;
        }
        else if (essais < 8)
        {
            if (W == H)
            {
                W = W * 2;
            }
            else
            {
                H = W;
            }
        }
    }

    if (!reussi)
    {
        std::cout << "ESSAIS 8" << std::endl;
        std::cout << "ECHEC" << std::endl;
        return 0;
    }

    std::cout << "ESSAIS " << essais << std::endl;
    std::cout << "TEXTURE " << W << " " << H << std::endl;

    for (int i = 0; i < G; i++)
    {
        std::cout << GroupePolices[i].nom << " "<< GroupePolices[i].x1 << " "<< GroupePolices[i].y1 << " "<< GroupePolices[i].x2 << " "<< GroupePolices[i].y2 << std::endl;
    }

    std::cout << "OCCUPE " << occupe << std::endl;

    int surface = int(W) * H;
    int perdu = (surface - occupe) * 100 / surface;

    std::cout << "PERDU " << perdu << std::endl;

    return 0;
}