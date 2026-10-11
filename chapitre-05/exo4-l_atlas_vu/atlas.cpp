#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKLogger/NkLog.h"

// NkCanvas
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include "NKCanvas/Core/NKRenderer2D.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Resources/NkFont.h"
#include "NKCanvas/Renderer/Resources/NkSprite.h"
#include "NKCanvas/Renderer/Shapes/NkRectangleShape.h"

#include "NKFont/NkFont.h"
#include "NKFont/Embedded/NkFontEmbedded.h"
#include "NKImage/NKImage.h"

#include "NKEvent/NkWindowEvent.h"
#include "NKMath/NkMat.h"
#include "NKMath/NkColor.h"
#include "NKTime/NkClock.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace nkentseu;
using namespace nkentseu::renderer;

int nkmain(const NkEntryState &state)
{
    // Chemin vers le fichier de police.
    const char *cheminPolice_Ecriture = "C:/Windows/Fonts/arial.ttf";

    NkFontAtlas atlas;    // On cree l'atlas de police.

    nkentseu::NkFont *police = atlas.AddFontFromFile(
        cheminPolice_Ecriture, 18.f    // On ajoute la police avec une taille de 18 pixels.
    );

    if (police == nullptr)
    {
        logger.Error("Erreur : impossible de charger la police.");
        return -1;
    }

    if (!atlas.Build())    // On construit l'atlas apres avoir ajoute la police.
    {
        logger.Error("Erreur : impossible de construire l'atlas.");
        return -1;
    }

    // On recupere les pixels et les dimensions de la texture.
    nkft_uint8 *pixels = nullptr;
    nkft_int32 largeur = 0;
    nkft_int32 hauteur = 0;

    atlas.GetTexDataAsRGBA32(&pixels, &largeur, &hauteur);

    // On verifie que les donnees sont disponibles avant de parcourir les pixels.
    if (pixels == nullptr || largeur <= 0 || hauteur <= 0)
    {
        std::cout << "Erreur : texture de l'atlas invalide." << std::endl;
        return -1;
    }

    int pixelsVisibles = 0;

    for (int i = 0; i < largeur * hauteur; i++)
    {
        if (pixels[i * 4 + 3] != 0)
        {
            pixelsVisibles++;
        }
    }

    std::cout << "Pixels visibles : " << pixelsVisibles << std::endl;

    // On enveloppe les pixels dans une image.
    // Wrap ne copie pas les pixels : l'atlas doit rester en vie.
    NkImage image = NkImage::Wrap(
        pixels,
        largeur,
        hauteur,
        NkImagePixelFormat::NK_RGBA32
    );

    std::cout << "Premier pixel RGBA : "
              << static_cast<int>(pixels[0]) << ", "
              << static_cast<int>(pixels[1]) << ", "
              << static_cast<int>(pixels[2]) << ", "
              << static_cast<int>(pixels[3]) << std::endl;

    if (!image.SavePNG("atlas.png"))
    {
        std::cout << "Erreur : impossible d'enregistrer atlas.png." << std::endl;
        return -1;
    }

    // On affiche les informations pour la taille 18.
    std::cout << "Taille : 18" << std::endl;
    std::cout << "Nombre de glyphes : " << police->glyphCount << std::endl;
    std::cout << "Largeur de la texture : " << largeur << std::endl;
    std::cout << "Hauteur de la texture : " << hauteur << std::endl;

    // On cree un deuxieme atlas pour tester la taille 48.
    // Cela permet de garder la premiere image independante.
    NkFontAtlas atlas48;

    // On ajoute la meme police avec une taille de 48 pixels.
    nkentseu::NkFont *police48 = atlas48.AddFontFromFile(
        cheminPolice_Ecriture, 48.f
    );

    // On verifie si la police a ete chargee.
    if (police48 == nullptr)
    {
        std::cout << "Erreur : impossible de charger la police en taille 48."<< std::endl;
        return -1;
    }

    // On construit l'atlas de taille 48.
    if (!atlas48.Build())
    {
        std::cout << "Erreur : impossible de construire l'atlas en taille 48."<< std::endl;
        return -1;
    }

    // On recupere les dimensions pour la taille 48.
    nkft_uint8 *pixels48 = nullptr;
    nkft_int32 largeur48 = 0;
    nkft_int32 hauteur48 = 0;

    atlas48.GetTexDataAsRGBA32(&pixels48, &largeur48, &hauteur48);

    // On verifie que les donnees de la taille 48 sont disponibles.
    if (pixels48 == nullptr || largeur48 <= 0 || hauteur48 <= 0)
    {
        std::cout << "Erreur : texture de l'atlas invalide en taille 48."<< std::endl;
        return -1;
    }

    // On affiche les informations pour la taille 48.
    std::cout << std::endl;
    std::cout << "Taille : 48" << std::endl;
    std::cout << "Nombre de glyphes : " << police48->glyphCount << std::endl;
    std::cout << "Largeur de la texture : " << largeur48 << std::endl;
    std::cout << "Hauteur de la texture : " << hauteur48 << std::endl;

    return 0;
}