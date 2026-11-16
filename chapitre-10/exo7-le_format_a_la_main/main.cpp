#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

class Lecteur
{
private:
    vector<uint8_t> octets;
    size_t position = 0;

public:
    explicit Lecteur(const vector<uint8_t>& donnees)
        : octets(donnees)
    {
    }

    bool lireU8(uint8_t& valeur)
    {
        if (position + 1 > octets.size())
            return false;

        valeur = octets[position++];
        return true;
    }

    bool lireU32(uint32_t& valeur)
    {
        if (position + 4 > octets.size())
            return false;

        valeur =
            static_cast<uint32_t>(octets[position]) |
            (static_cast<uint32_t>(octets[position + 1]) << 8) |
            (static_cast<uint32_t>(octets[position + 2]) << 16) |
            (static_cast<uint32_t>(octets[position + 3]) << 24);

        position += 4;
        return true;
    }

    bool lireF32(float& valeur)
    {
        uint32_t bits;

        if (!lireU32(bits))
            return false;

        memcpy(&valeur, &bits, sizeof(float));
        return true;
    }

    bool sauter(size_t nombre)
    {
        if (nombre > octets.size() - position)
            return false;

        position += nombre;
        return true;
    }

    bool lireOctet(uint8_t& valeur)
    {
        return lireU8(valeur);
    }

    bool estFin() const
    {
        return position == octets.size();
    }
};

void afficherFlottant(float valeur)
{
    double arrondi = round(static_cast<double>(valeur) * 100.0) / 100.0;

    if (arrondi == 0.0)
        arrondi = 0.0;

    cout << fixed << setprecision(2) << arrondi;
}

int main()
{
    size_t T;

    if (!(cin >> T))
        return 0;

    vector<uint8_t> octets;
    octets.reserve(T);

    for (size_t i = 0; i < T; ++i)
    {
        string hexadecimal;

        if (!(cin >> hexadecimal))
        {
            cout << "TRONQUE\n";
            return 0;
        }

        unsigned int valeur = 0;

        try
        {
            valeur = static_cast<unsigned int>(stoul(hexadecimal, nullptr, 16));
        }
        catch (...)
        {
            cout << "TRONQUE\n";
            return 0;
        }

        octets.push_back(static_cast<uint8_t>(valeur));
    }

    if (octets.size() < 4)
    {
        cout << "TRONQUE\n";
        return 0;
    }

    if (octets[0] != 0x4E ||
        octets[1] != 0x4B ||
        octets[2] != 0x52 ||
        octets[3] != 0x46)
    {
        cout << "PAS_UNE_PLANCHE\n";
        return 0;
    }

    Lecteur lecteur(octets);

    uint8_t octet;
    uint32_t version;

    for (int i = 0; i < 4; ++i)
        lecteur.lireU8(octet);

    if (!lecteur.lireU32(version))
    {
        cout << "TRONQUE\n";
        return 0;
    }

    if (version != 1)
    {
        cout << "VERSION_INCONNUE " << version << '\n';
        return 0;
    }

    float cx, cy, zoom;

    if (!lecteur.lireF32(cx) ||
        !lecteur.lireF32(cy) ||
        !lecteur.lireF32(zoom))
    {
        cout << "TRONQUE\n";
        return 0;
    }

    uint8_t theme, grille;

    if (!lecteur.lireU8(theme) ||
        !lecteur.lireU8(grille) ||
        !lecteur.lireU8(octet) ||
        !lecteur.lireU8(octet))
    {
        cout << "TRONQUE\n";
        return 0;
    }

    uint32_t nombreImages;

    if (!lecteur.lireU32(nombreImages))
    {
        cout << "TRONQUE\n";
        return 0;
    }

    struct Image
    {
        float x, y, echelle, rotation, opacite;
        uint8_t miroirX, miroirY;
        uint32_t largeur, hauteur, taille;
    };

    vector<Image> images;

    for (uint32_t i = 0; i < nombreImages; ++i)
    {
        Image image;

        if (!lecteur.lireF32(image.x) ||
            !lecteur.lireF32(image.y) ||
            !lecteur.lireF32(image.echelle) ||
            !lecteur.lireF32(image.rotation) ||
            !lecteur.lireF32(image.opacite) ||
            !lecteur.lireU8(image.miroirX) ||
            !lecteur.lireU8(image.miroirY) ||
            !lecteur.lireU8(octet) ||
            !lecteur.lireU8(octet) ||
            !lecteur.lireU32(image.largeur) ||
            !lecteur.lireU32(image.hauteur) ||
            !lecteur.lireU32(image.taille))
        {
            cout << "TRONQUE\n";
            return 0;
        }

        if (!lecteur.sauter(image.taille))
        {
            cout << "TRONQUE\n";
            return 0;
        }

        images.push_back(image);
    }

    uint32_t nombreTraits;

    if (!lecteur.lireU32(nombreTraits))
    {
        cout << "TRONQUE\n";
        return 0;
    }

    struct Point
    {
        float x, y;
    };

    struct Trait
    {
        uint8_t r, g, b, a;
        float epaisseur;
        vector<Point> points;
    };

    vector<Trait> traits;

    for (uint32_t i = 0; i < nombreTraits; ++i)
    {
        Trait trait;
        uint32_t nombrePoints;

        if (!lecteur.lireU8(trait.r) ||
            !lecteur.lireU8(trait.g) ||
            !lecteur.lireU8(trait.b) ||
            !lecteur.lireU8(trait.a) ||
            !lecteur.lireF32(trait.epaisseur) ||
            !lecteur.lireU32(nombrePoints))
        {
            cout << "TRONQUE\n";
            return 0;
        }

        for (uint32_t j = 0; j < nombrePoints; ++j)
        {
            Point point;

            if (!lecteur.lireF32(point.x) ||
                !lecteur.lireF32(point.y))
            {
                cout << "TRONQUE\n";
                return 0;
            }

            trait.points.push_back(point);
        }

        traits.push_back(trait);
    }

    cout << "VUE ";
    afficherFlottant(cx);
    cout << " ";
    afficherFlottant(cy);
    cout << " ";
    afficherFlottant(zoom);
    cout << '\n';

    cout << "THEME " << (theme != 0 ? "SOMBRE" : "CLAIR") << '\n';

    cout << "GRILLE " << (grille == 0 ? "AFFICHEE" : "CACHEE") << '\n';

    cout << "IMAGES " << nombreImages << '\n';

    for (size_t i = 0; i < images.size(); ++i)
    {
        const Image& image = images[i];

        cout << "IMAGE " << i + 1 << " ";

        afficherFlottant(image.x);
        cout << " ";
        afficherFlottant(image.y);
        cout << " ";
        afficherFlottant(image.echelle);
        cout << " ";
        afficherFlottant(image.rotation);
        cout << " ";
        afficherFlottant(image.opacite);

        cout << " " << (image.miroirX != 0 ? 1 : 0)
             << " " << (image.miroirY != 0 ? 1 : 0)
             << " " << image.largeur
             << " " << image.hauteur
             << " " << image.taille << '\n';
    }

    cout << "TRAITS " << nombreTraits << '\n';

    for (size_t i = 0; i < traits.size(); ++i)
    {
        const Trait& trait = traits[i];

        cout << "TRAIT " << i + 1
             << " " << static_cast<int>(trait.r)
             << " " << static_cast<int>(trait.g)
             << " " << static_cast<int>(trait.b)
             << " " << static_cast<int>(trait.a)
             << " ";

        afficherFlottant(trait.epaisseur);

        cout << " " << trait.points.size() << '\n';

        for (const Point& point : trait.points)
        {
            cout << "POINT ";
            afficherFlottant(point.x);
            cout << " ";
            afficherFlottant(point.y);
            cout << '\n';
        }
    }

    return 0;
}