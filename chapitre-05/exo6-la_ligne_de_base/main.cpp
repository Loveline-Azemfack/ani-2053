#include <iostream>
#include <string>

struct Glyphe{
    char c;
    int avance;
    int x0, y0, x1, y1;
};

struct Crenage{
    char a, b;
    int k;
};

int main()
{
// Lire le nombre de glyphes.
int G;
std::cin >> G;
// Tableau des glyphes.
Glyphe glyphes[200];

// Lire les informations de chaque glyphe.
for (int i = 0; i < G; i++){
    std::cin >> glyphes[i].c>> glyphes[i].avance>> glyphes[i].x0>> glyphes[i].y0>> glyphes[i].x1>> glyphes[i].y1;
}

// Lire le nombre de couples de crénage.
int K;
std::cin >> K;

// Tableau des couples de crénage.
Crenage crenages[200];

// Lire les couples et leurs corrections.
for (int i = 0; i < K; i++){
    std::cin >> crenages[i].a>> crenages[i].b>> crenages[i].k;
}

// Lire le texte et la position de la ligne de base.
std::string texte;
int ox, oy;
std::cin >> texte >> ox >> oy;

// Le curseur commence à ox.
int x = ox;

// Limites de la boîte des dessins.
int minx = 0, miny = 0;
int maxx = 0, maxy = 0;

// Indique si un glyphe a été dessiné.
bool dessin = false;

// Compter les caractères absents.
int absents = 0;

// Parcourir le texte caractère par caractère.
for (int i = 0; i < static_cast<int>(texte.size()); i++){
    char c = texte[i];
    // Chercher le caractère dans la table.
    int indice = -1;

    for (int j = 0; j < G; j++){
        if (glyphes[j].c == c)
        {
            indice = j;
            break;
        }
    }

    // Si le caractère est absent.
    if (indice == -1){
        std::cout << c << " ABSENT" << std::endl;
        absents++;
        continue;
    }

    // Afficher la position du caractère.
    std::cout << c << " " << x << "\n";

    // Récupérer les informations du glyphe.
    int avance = glyphes[indice].avance;
    int x0 = glyphes[indice].x0;
    int y0 = glyphes[indice].y0;
    int x1 = glyphes[indice].x1;
    int y1 = glyphes[indice].y1;

    // Vérifier si le glyphe possède un dessin.
    if (x1 > x0 && y1 > y0){
        // Calculer les coordonnées réelles.
        int gauche = x + x0;
        int haut = oy + y0;
        int droite = x + x1;
        int bas = oy + y1;

        // Le premier dessin initialise la boîte.
        if (!dessin){
            minx = gauche;
            miny = haut;
            maxx = droite;
            maxy = bas;
            dessin = true;
        }
        else{
            // Mettre à jour les limites de la boîte.
            if (gauche < minx) minx = gauche;
            if (haut < miny) miny = haut;
            if (droite > maxx) maxx = droite;
            if (bas > maxy) maxy = bas;
        }
    }

    // Faire avancer le curseur.
    x = x + avance;

    // Chercher le crénage avec le caractère suivant.
    if (i + 1 < static_cast<int>(texte.size()))
    {
        char suivant = texte[i + 1];

        for (int j = 0; j < K; j++){
            if (crenages[j].a == c && crenages[j].b == suivant){
                x = x + crenages[j].k;
                break;
            }
        }
    }
}

// Afficher la position finale du curseur.
std::cout << "CURSEUR " << x << std::endl;

// Si aucun dessin n'a été effectué.
if (!dessin)
{
    std::cout << "BOITE AUCUNE"<< std::endl;;
    std::cout << "MONTE 0"<< std::endl;;
    std::cout << "DESCEND 0"<< std::endl;;
    std::cout << "ECRAN RIEN"<< std::endl;;
}
else
{
    // Afficher les limites de la boîte.
    std::cout << "BOITE "<< minx << " " << miny << " "<< maxx << " " << maxy << "\n";

    // Calculer ce qui monte au-dessus de la ligne de base.
    int monte = 0;
    if (miny < oy)
    {
        monte = oy - miny;
    }

    // Calculer ce qui descend sous la ligne de base.
    int descend = 0;
    if (maxy > oy){
        descend = maxy - oy;
    }

    std::cout << "MONTE " << monte << std::endl;
    std::cout << "DESCEND " << descend << std::endl;

    // Vérifier si le dessin dépasse le haut de l'écran.
    if (maxy <= 0){
        std::cout << "ECRAN HORS"<< std::endl;
    }
    else if (miny < 0){
        std::cout << "ECRAN COUPE"<< std::endl;
    }
    else{
        std::cout << "ECRAN VISIBLE"<< std::endl;
    }
}

// Afficher le nombre de caractères absents.
std::cout << "ABSENTS " << absents << std::endl;

return 0;
}
