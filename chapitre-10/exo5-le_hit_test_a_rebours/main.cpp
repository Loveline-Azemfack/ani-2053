#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct Image
{
    std::string nom;
    double x;
    double y;
    double demiLargeur;
    double demiHauteur;
};

bool touche(const Image& image, double px, double py)
{
    return std::fabs(px - image.x) <= image.demiLargeur &&
           std::fabs(py - image.y) <= image.demiHauteur;
}

std::string chercher(
    const std::vector<Image>& images,
    double px,
    double py,
    bool aRebours)
{
    if (aRebours)
    {
        for (int i = static_cast<int>(images.size()) - 1; i >= 0; --i)
        {
            if (touche(images[i], px, py))
                return images[i].nom;
        }
    }
    else
    {
        for (std::size_t i = 0; i < images.size(); ++i)
        {
            if (touche(images[i], px, py))
                return images[i].nom;
        }
    }

    return "AUCUN";
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<Image> images;

    for (int i = 0; i < N; ++i)
    {
        Image image;
        double largeur;
        double hauteur;
        double echelle;

        std::cin >> image.nom
                 >> image.x
                 >> image.y
                 >> largeur
                 >> hauteur
                 >> echelle;

        image.demiLargeur = largeur * echelle / 2.0;
        image.demiHauteur = hauteur * echelle / 2.0;

        images.push_back(image);
    }

    int Q;
    std::cin >> Q;

    int erreurs = 0;

    for (int k = 1; k <= Q; ++k)
    {
        double px;
        double py;

        std::cin >> px >> py;

        std::string resultatRebours =
            chercher(images, px, py, true);

        std::string resultatEndroit =
            chercher(images, px, py, false);

        std::cout << "CLIC " << k << " "
                  << resultatRebours << " "
                  << resultatEndroit << '\n';

        if (resultatRebours != resultatEndroit)
            ++erreurs;
    }

    std::cout << "ERREURS " << erreurs << '\n';

    return 0;
}