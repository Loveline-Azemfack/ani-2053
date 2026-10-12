#include <iostream>
#include <fstream>
#include <string>
#include "NKMedia/Video/NkVideoReader.h"
#include "NKMedia/NkMediaProbe.h"
#include "NKLogger/NkLog.h"

// Fonction qui teste un fichier vidéo.
void TesterVideo(const char* nomFichier, std::ofstream& fichierResultats)
{
// Affiche le nom du fichier testé.
std::cout << "\nFichier teste : " << nomFichier << std::endl;

// Crée un lecteur vidéo.
NkVideoReader lecteur;

// Essaie d'ouvrir le fichier.
bool ouvert = lecteur.Open(nomFichier);

// Initialise le compteur d'images.
int nombreImages = 0;

// Initialise le nom du conteneur détecté par la sonde.
std::string conteneurSonde = "inconnu";

// Prépare les informations qui seront fournies par la sonde.
NkMediaInfo informationsSonde;

// Examine le fichier avec la sonde.
bool sondeReussie = NkMediaProbe::ProbeFile(nomFichier, informationsSonde);

// Vérifie si la sonde a réussi.
if (sondeReussie)
{
    // Récupère le nom du conteneur détecté.
    conteneurSonde = informationsSonde.ContainerName().CStr();

    // Affiche le conteneur détecté.
    std::cout << "Conteneur detecte : " << conteneurSonde << std::endl;

    // Affiche le codec de chaque piste détectée.
    for (const auto& piste : informationsSonde.tracks)
    {
        std::cout << "Codec de la piste : " << piste.codec.CStr() << std::endl;
    }
}
else
{
    // Signale que la sonde n'a pas réussi.
    std::cout << "La sonde n'a pas pu analyser le fichier." << std::endl;
}

// Vérifie si le lecteur a réussi à ouvrir le fichier avant de lire les images.
if (ouvert)
{
    // Récupère les informations de la vidéo.
    auto informations = lecteur.Info();

    // Affiche les informations du lecteur.
    std::cout << "Conteneur du lecteur : " << informations.container.CStr() << std::endl;
    std::cout << "Codec du lecteur : " << informations.codec.CStr() << std::endl;
    std::cout << "Largeur : " << informations.width << std::endl;
    std::cout << "Hauteur : " << informations.height << std::endl;

    // Prépare une image pour recevoir chaque image lue.
    NkVideoFrame image;

    // Lit les images une par une et les compte.
    while (lecteur.ReadFrame(image))
    {
        nombreImages++;
    }

    // Affiche le nombre d'images lues.
    std::cout << "Nombre d'images lues : " << nombreImages << std::endl;
}
else
{
    // Signale que le lecteur a refusé le fichier.
    std::cout << "Le lecteur a refuse le fichier." << std::endl;
}

// Écrit une ligne de résultats pour le fichier testé.
fichierResultats << "fichier : " << nomFichier << ", ouvert : " << (ouvert ? "oui" : "non") << ", images : " << nombreImages << ", sonde : " << conteneurSonde << std::endl;

}

// Fonction principale du programme.
int main()
{
// Crée le fichier qui recevra les résultats.
std::ofstream fichierResultats("resultats.txt");
// Vérifie que le fichier a bien été ouvert.
if (!fichierResultats.is_open())
{
    std::cout << "Impossible de creer resultats.txt." << std::endl;
    return 1;
}

// Teste la vidéo originale.
TesterVideo("film.mp4", fichierResultats);

// Teste la vidéo coupée.
TesterVideo("film_coupe.mp4", fichierResultats);

// Teste le fichier texte renommé en MP4.
TesterVideo("texte.mp4", fichierResultats);

// Ferme le fichier de résultats.
fichierResultats.close();

// Indique que les tests sont terminés.
std::cout << "Tests termines. Consulte resultats.txt." << std::endl;

return 0;

}
