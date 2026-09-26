# include "NKWindow/NKWindow.h"
# include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"
#include <iostream>
#include <windows.h>

using namespace nkentseu;
int nkmain(const NkEntryState &state){
    NkWindowConfig cfg;
    cfg.title = "Ma fenetre 1";
    cfg.width = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    if(!window.IsOpen()){
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }else{
        std::cout<<"fenetre cree avec succes!!";
    }

    NkString texte = window.GetClipboardText();

    std::cout << "Texte copie dans le presse-papiers : "
            << texte.CStr() << std::endl;

    NkString texteMajuscule = NkStringView(texte).ToUpper();

    std::cout << "Texte transforme en majuscules : "
            << texteMajuscule.CStr() << std::endl;

    window.SetClipboardText(texteMajuscule);

    NkClipboardImage image;

    image.width = 2;
    image.height = 2;
    image.pixels.Resize(16);

    uint8 *p = image.pixels.Data();

    // Pixel 1 : rouge
    p[0] = 255;
    p[1] = 0;
    p[2] = 0;
    p[3] = 255;

    // Pixel 2 : vert
    p[4] = 0;
    p[5] = 255;
    p[6] = 0;
    p[7] = 255;

    // Pixel 3 : bleu
    p[8] = 0;
    p[9] = 0;
    p[10] = 255;
    p[11] = 255;

    // Pixel 4 : blanc
    p[12] = 255;
    p[13] = 255;
    p[14] = 255;
    p[15] = 255;

    if (image.IsValid()) {
        std::cout << "Image creee avec succes." << std::endl;
    } else {
        std::cout << "Image invalide." << std::endl;
    }

    if (window.SetClipboardImage(image)) {
        std::cout << "Image placee dans le presse-papiers." << std::endl;
    } else {
        std::cout << "Impossible de placer l'image dans le presse-papiers." << std::endl;
    }

    if (OpenClipboard(nullptr)) {

        UINT format = 0;

        while ((format = EnumClipboardFormats(format)) != 0) {
            if (format == CF_TEXT)
                std::cout << "CF_TEXT" << std::endl;
            else if (format == CF_BITMAP)
                std::cout << "CF_BITMAP" << std::endl;
            else if (format == CF_DIB)
                std::cout << "CF_DIB" << std::endl;
            else if (format == CF_DIBV5)
                std::cout << "CF_DIBV5" << std::endl;
            else if (format == CF_UNICODETEXT)
                std::cout << "CF_UNICODETEXT" << std::endl;
            else
                std::cout << "Autre format : " << format << std::endl;
        }

        CloseClipboard();
    }

    if (window.HasClipboardImage()) {
        std::cout << "Une image est detectee dans le presse-papiers." << std::endl;
    } else {
        std::cout << "Aucune image detectee dans le presse-papiers." << std::endl;
    }

    if (window.GetClipboardImage(image)) {
        std::cout << "Image lue avec succes." << std::endl;
        std::cout << "Largeur : " << image.width << std::endl;
        std::cout << "Hauteur : " << image.height << std::endl;
    } else {
        std::cout << "Impossible de lire l'image." << std::endl;
    }
    NkClipboardImage imageLue;

    if (window.GetClipboardImage(imageLue)) {
        std::cout << "Image recuperee pour traitement." << std::endl;
    } else {
        std::cout << "Impossible de recuperer l'image." << std::endl;
    }

    uint8 *pixels = imageLue.pixels.Data();

    for (usize i = 0; i < imageLue.pixels.Size(); i += 4) {
        pixels[i]     = 255 - pixels[i];     // Rouge
        pixels[i + 1] = 255 - pixels[i + 1]; // Vert
        pixels[i + 2] = 255 - pixels[i + 2]; // Bleu
        // pixels[i + 3] = Alpha : on ne le modifie pas
    }

    std::cout << "Couleurs inversees." << std::endl;

    if (window.SetClipboardImage(imageLue)) {
        std::cout << "Image inversee remise dans le presse-papiers." << std::endl;
    } else {
        std::cout << "Impossible de remettre l'image dans le presse-papiers." << std::endl;
    }

    bool running = true;

    NkEventSystem &events = NkEvents();
    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *) {
            running = false;
        }
    );
    while (running && window.IsOpen()) {
            events.PollEvents();
            NkClock::Sleep((int64)10);

    }

    window.Close();

    return 0;
}