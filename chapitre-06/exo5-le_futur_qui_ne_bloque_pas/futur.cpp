#include <iostream>
#include "NKWindow/NKMain.h"
#include <NKThreading/NkThread.h>
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>
#include <NKTime/NkChrono.h>
#include <NKThreading/NkFuture.h>
#include <NKThreading/NkThreadPool.h>

//NkWindow
#include "NKLogger/NkLog.h"

//NkCanvas
#include "NKCanvas/Core/NKRenderer2D.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Resources/NkFont.h"
#include "NKCanvas/Renderer/Resources/NkSprite.h"
#include "NKCanvas/Renderer/Shapes/NkRectangleShape.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2DTypes.h"

#include "NKFont/Embedded/NkFontEmbedded.h"
#include "NKImage/NKImage.h"

#include "NKEvent/NkWindowEvent.h"
#include "NKMath/NkMat.h"
#include "NKMath/NkColor.h"
#include "NKTime/NkClock.h"

//NKCanvas
#include <NKCanvas/App/NkCanvasApp.h>
#include <NKCanvas/Renderer/Core/NkIRenderer2D.h>
#include  <NKCanvas/Renderer/Core/NkDrawable.h>

using namespace nkentseu;
using namespace nkentseu::renderer;
using namespace nkentseu::threading;
using namespace nkentseu::time;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "Ma fenetre 1";
    cfg.width = 1280;
    cfg.height = 720;
    
    NkWindow window(cfg);
    
    if(!window.IsOpen()){
        logger.Error("probleme d'ouverture de la fenetre !");
        return -1;
    };
    
    bool running = true;
    NkEventSystem & events = NkEvents();
    NkClock clock;
    int nombre_de_Trames = 0;
    int carre_avance = 0;
    events.AddEventCallback<NkWindowCloseEvent>([&](NkWindowCloseEvent*){
        running = false;
    });
    
    NkContextDesc contextDesc;
    contextDesc.api = NkGraphicsApi::NK_GFX_API_OPENGL;

    NkRenderWindow renderwindow(window, contextDesc);

    if (!renderwindow.IsValid())
    {
    logger.Error("Failed to initialize render window");
    return 2;
    }
    
    // Pool de threads pour le chargement en arriere-plan
    NkThreadPool pool;

    // Promesse qui transmettra l'image chargee
    NkPromise<NkImage> promesse;

    // Futur qui permettra de recuperer cette image
    NkFuture<NkImage> futur = promesse.GetFuture();

    // Image recuperee par le thread principal
    const NkImage* imageChargee = nullptr;

    // Etat du chargement
    bool chargementLance = false;
    bool imageRecuperee = false;

    // Mesures du chargement et de l'affichage
    double dureeChargementMs = 0.0;
    double dureeTrameMaxMs = 0.0;
    int tramesPendantChargement = 0;

    // Chronometre utilise pour mesurer chaque trame
    NkChrono chronoTrame;

    // false : tester Get()
    // true  : tester IsReady()
    constexpr bool UTILISER_ISREADY = true;

  while (running && window.IsOpen())
  {
      // Demarrer la mesure de cette trame
      (void)chronoTrame.Reset();

      // Traiter les evenements de la fenetre
      events.PollEvents();

      // Compter les trames traitees
      ++nombre_de_Trames;

      // Faire avancer le carre d'un pixel par trame
      ++carre_avance;

      // Recommencer lorsque le carre atteint le bord droit
      if (carre_avance >= 1280)
      {
          carre_avance = 0;
      }

      // Lancer le chargement une seule fois, apres 60 trames
      if (nombre_de_Trames >= 60 && !chargementLance)
      {
          chargementLance = true;

          pool.Enqueue([&]()
          {
              NkImage img;

              // Mesurer le temps de chargement dans le thread secondaire
              NkChrono chronoChargement;

              bool succes = img.Load("Exercices-sprint/src/photo.jpg");

              dureeChargementMs =
                  chronoChargement.Elapsed().ToMilliseconds();

              if (!succes)
              {
                  logger.Error("Echec du chargement de photo.jpg");
              }
              else
              {
                  logger.Info("Chargement de photo.jpg reussi");
              }

              // Transmettre l'image au futur
              promesse.SetValue(nkentseu::traits::NkMove(img));
          });

          logger.Info("Chargement de photo.jpg lance en arriere-plan");

          // Methode 1 : attendre le resultat avec Get()
          if (!UTILISER_ISREADY)
          {
              imageChargee = &futur.Get();
              imageRecuperee = true;

              logger.Info("Image recuperee avec Get()");
          }
      }

      // Methode 2 : verifier la disponibilite avec IsReady()
      if (chargementLance && UTILISER_ISREADY && !imageRecuperee)
      {
          if (futur.IsReady())
          {
              imageChargee = &futur.Get();
              imageRecuperee = true;

              logger.Info("Image recuperee avec IsReady()");
          }
          else
          {
              // Cette trame sera affichee pendant le chargement
              ++tramesPendantChargement;
          }
      }

      // Recuperer le moteur de rendu 2D
      auto& renderer = renderwindow.GetRenderer2D();

      // Effacer l'image precedente
      renderwindow.Clear(NkColor2D{18, 18, 24, 255});

      // Dessiner la bande en haut de la fenetre
      renderer.DrawFilledRect(
          {0.0f, 0.0f, 800.0f, 70.0f},
          NkColor2D{40, 40, 50, 255}
      );

      // Dessiner le carre rouge
      renderer.DrawFilledRect(
          {
              static_cast<float32>(carre_avance),
              100.0f,
              50.0f,
              50.0f
          },
          NkColor2D{255, 0, 0, 255}
      );

      // Afficher l'image dessinee
      renderwindow.Display();

      // Mesurer la duree totale de cette trame, rendu compris
      double dureeTrameMs = chronoTrame.Elapsed().ToMilliseconds();

      // Conserver la duree maximale observee
      if (dureeTrameMs > dureeTrameMaxMs)
      {
          dureeTrameMaxMs = dureeTrameMs;
      }
  }

    // Attendre la fin du chargement si la fenetre est fermee trop tot
    if (chargementLance && !imageRecuperee)
    {
        imageChargee = &futur.Get();
        imageRecuperee = true;
    }
    
   window.Close();

   std::cout << "\n========== RESULTATS DU TEST ==========\n";
   std::cout << "Image : photo.jpg (4 171 622 octets)\n";
   std::cout << "Temps de chargement : "
             << dureeChargementMs << " ms\n";
   std::cout << "Methode utilisee : "
             << (UTILISER_ISREADY ? "IsReady()" : "Get()") << '\n';
   std::cout << "Duree maximale d'une trame : "
             << dureeTrameMaxMs << " ms\n";
   std::cout << "Trames affichees pendant le chargement : "<< tramesPendantChargement << '\n';
   std::cout << "Nombre total de trames traitees : "<< nombre_de_Trames << '\n';
   std::cout << "=======================================\n";

    return 0;
}