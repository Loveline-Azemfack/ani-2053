# include "NKWindow/NKWindow.h"
# include "NKWindow/NKMain.h"
#include "NKLogger/NkLog.h"

//NkCanvas
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include "NKCanvas/Core/NKRenderer2D.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Resources/NkFont.h"
#include "NKCanvas/Renderer/Resources/NkSprite.h"
#include "NKCanvas/Renderer/Shapes/NkRectangleShape.h"

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

    bool running = true;
    NkEventSystem &events = NkEvents();

    NkImage img, img1, icone, capture, dessin;

    std::this_thread::sleep_for(std::chrono::seconds(10));

    if(!img.Load("Nk_IMAGE-FONT-AUDIO/Assets/photo.jpg")){
        logger.Error("erreur de chargement de la premiere photo \n");
    }else{
        int largeur = img.Width();
        int hauteur = img.Height();
        int bytesPP = img.BytesPP();
        uint8 * pixel = img.Pixels();
        std::cout<< "photo chargee avec succes !"<< std::endl;
        logger.Info("largeur photo: {}", largeur);
        logger.Info("hauteur photo: {}", hauteur);
        logger.Info("BytesPP photo: {}", bytesPP);
        logger.Info("Calcul memoire photo: {}", largeur * hauteur * bytesPP);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    if(!img1.Load("Nk_IMAGE-FONT-AUDIO/Assets/photo2.jpg")){
        logger.Error("erreur de chargement de la deuxieme photo \n");
    }else{
        int largeur1 = img1.Width();
        int hauteur1 = img1.Height();
        int bytesPP1 = img1.BytesPP();
        uint8 * pixel1 = img1.Pixels();
        std::cout<< "photo2 chargee avec succes !"<< std::endl;        
        logger.Info("largeur photo2: {}", largeur1);
        logger.Info("hauteur photo2: {}", hauteur1);
        logger.Info("BytesPP photo2: {}", bytesPP1);
        logger.Info("Calcul memoire photo2: {}", largeur1 * hauteur1 * bytesPP1);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    if(!icone.Load("Nk_IMAGE-FONT-AUDIO/Assets/icone.jpg")){
        logger.Error("erreur de chargement de l'icone \n");
    }else{
        
        int largeur2 = icone.Width();
        int hauteur2 = icone.Height();
        int bytesPP2 = icone.BytesPP();
        uint8 * pixel2 = icone.Pixels();
        std::cout<< "icone chargee avec succes !"<< std::endl;
        logger.Info("largeur icone: {}", largeur2);
        logger.Info("hauteur icone: {}", hauteur2);
        logger.Info("BytesPP icone: {}", bytesPP2);
        logger.Info("Calcul memoire icone: {}", largeur2 * hauteur2 * bytesPP2);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    if(!dessin.Load("Nk_IMAGE-FONT-AUDIO/Assets/dessin_aplat.png")){
        logger.Error("erreur de chargement du dessin  \n");
    }else{
        int largeur3 = dessin.Width();
        int hauteur3 = dessin.Height();
        int bytesPP3 = dessin.BytesPP();
        uint8 * pixel3 = dessin.Pixels();
        std::cout<< "dessin chargee avec succes !"<< std::endl;
        logger.Info("largeur dessin: {}", largeur3);
        logger.Info("hauteur dessin: {}", hauteur3);
        logger.Info("BytesPP dessin: {}", bytesPP3);
        logger.Info("Calcul memoire dessin: {}", largeur3 * hauteur3 * bytesPP3);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));
    
    if(!capture.Load("Nk_IMAGE-FONT-AUDIO/Assets/Capture-écran.png")){
        logger.Error("erreur de chargement de la capture d'ecran \n");
    }else{
        int largeur4 = capture.Width();
        int hauteur4 = capture.Height();
        int bytesPP4 = capture.BytesPP();
        uint8 * pixel4 = capture.Pixels();
        std::cout<< "capture chargee avec succes !"<< std::endl;
        logger.Info("largeur capture: {}", largeur4);
        logger.Info("hauteur capture: {}", hauteur4);
        logger.Info("BytesPP capture: {}", bytesPP4);
        logger.Info("Calcul memoire capture: {}", largeur4 * hauteur4 * bytesPP4);
    }

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