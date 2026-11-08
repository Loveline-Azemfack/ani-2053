#include <iostream>

// On inclut le fichier qui contient NkRefView.
#include "../../../../Nkentseu/Applications/NkRef/src/NkRef/NkRefView.h"

int main()
{
    // Pourquoi déclarons-nous cet objet avec const ?
    // Parce que nous voulons vérifier qu'il ne peut pas être modifié.
    const nkref::NkRefView vue{};

    // Définissons les coordonnées d'un point sur l'écran.
    const nkentseu::math::NkVec2f pixel{640.0f, 360.0f};

    // Définissons les dimensions de la fenêtre.
    const nkentseu::math::NkVec2f viewport{1280.0f, 720.0f};

    // QUESTION : Peut-on appeler PixelToWorld() sur un objet constant ?
    // OUI, car cette méthode est déclarée const.
    const auto positionMonde = vue.PixelToWorld(pixel, viewport);

    // QUESTION : Peut-on appeler WorldToPixel() sur un objet constant ?
    // OUI, car cette méthode est également déclarée const.
    const auto positionPixel = vue.WorldToPixel(positionMonde, viewport);

    // Affichons les résultats.
    std::cout << "Position dans le monde : "
              << positionMonde.x << ", "
              << positionMonde.y << '\n';

    std::cout << "Position sur l'ecran : "
              << positionPixel.x << ", "
              << positionPixel.y << '\n';

    // QUESTION : Peut-on appeler PanByPixels() sur un objet constant ?
    // NON, car cette méthode modifie l'objet et n'est pas déclarée const.
    //
    // Décommentez la ligne suivante pour observer l'erreur de compilation :
    // vue.PanByPixels(10.0f, 5.0f);

    return 0;
}