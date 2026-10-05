#include <iostream>
#include <string>

struct Objet
{
    std::string nom;
    std::string parent;

    int tx;
    int ty;
    int angle;
    int echelle;

    int x;
    int y;
    int angleMonde;
    int echelleMonde;
    int niveau;
};

int main()
{
    int N;
    std::cin >> N;

    Objet objets[100];
    int profondeurMax = 0;

    for (int i = 0; i < N; i++)
    {
        std::cin >> objets[i].nom>> objets[i].parent>> objets[i].tx>> objets[i].ty>> objets[i].angle>> objets[i].echelle;

        if (objets[i].parent == "-")
        {
            objets[i].x = objets[i].tx;
            objets[i].y = objets[i].ty;
            objets[i].angleMonde = objets[i].angle % 360;
            if (objets[i].angleMonde < 0)
            {
                objets[i].angleMonde += 360;
            }
            objets[i].echelleMonde = objets[i].echelle;
            objets[i].niveau = 1;
        }
        else
        {
            int indiceParent ;
            for (int j = 0; j < i; j++)
            {
                if (objets[j].nom == objets[i].parent)
                {
                    indiceParent = j;
                    break;
                }
            }

            int ax = objets[i].tx * objets[indiceParent].echelleMonde;
            int ay = objets[i].ty * objets[indiceParent].echelleMonde;

            int c = 0;
            int s = 0;
            if (objets[indiceParent].angleMonde == 0)
            {
                c = 1;
                s = 0;
            }
            else if (objets[indiceParent].angleMonde == 90)
            {
                c = 0;
                s = 1;
            }
            else if (objets[indiceParent].angleMonde == 180)
            {
                c = -1;
                s = 0;
            }
            else if (objets[indiceParent].angleMonde == 270)
            {
                c = 0;
                s = -1;
            }
            int rx = ax * c - ay * s;
            int ry = ax * s + ay * c;
            objets[i].x = objets[indiceParent].x + rx;
            objets[i].y = objets[indiceParent].y + ry;
            objets[i].angleMonde = objets[indiceParent].angleMonde + objets[i].angle;
            objets[i].angleMonde %= 360;

            if (objets[i].angleMonde < 0)
            {
                objets[i].angleMonde += 360;
            }
            objets[i].echelleMonde = objets[indiceParent].echelleMonde * objets[i].echelle;

            objets[i].niveau = objets[indiceParent].niveau + 1;
        }

        if (objets[i].niveau > profondeurMax)
        {
            profondeurMax = objets[i].niveau;
        }

        std::cout << objets[i].nom << " "<< objets[i].x << " "<< objets[i].y << " "<< objets[i].angleMonde << " "<< objets[i].echelleMonde << "\n";
    }

    std::cout << "PROFONDEUR " << profondeurMax << "\n";

    return 0;
}