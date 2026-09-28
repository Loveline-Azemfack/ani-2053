#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKTime/NkClock.h"
#include <iostream>

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Ma fenetre 1";
    cfg.width = 1280;
    cfg.height = 720;
    cfg.centered = false;
    cfg.x = 100;
    cfg.y = 100;

    NkWindowConfig cfg1;
    cfg1.title = "Ma fenetre 2";
    cfg1.width = 1320;
    cfg1.height = 920;

    NkWindow window(cfg);
    NkWindow window1(cfg1);

    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre 1 echouee");
        return -1;
    }

    if (!window1.IsOpen()) {
        logger.Error("[app] creation fenetre 2 echouee");
        return -1;
    }

    std::cout << "Fenetre 1 creee avec succes !" << std::endl;
    std::cout << "Fenetre 2 creee avec succes !" << std::endl;

    // Recuperation des identifiants des deux fenetres
    NkWindowId id1 = window.GetId();
    NkWindowId id2 = window1.GetId();

    std::cout << "ID fenetre 1 : " << id1 << std::endl;
    std::cout << "ID fenetre 2 : " << id2 << std::endl;

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *event) {

            // Identifiant de la fenetre qui demande la fermeture
            NkWindowId id = event->GetWindowId();

            if (id == id1) {
                std::cout << "Fermeture de la fenetre 1" << std::endl;
                window.Close();
            }
            else if (id == id2) {
                std::cout << "Fermeture de la fenetre 2" << std::endl;
                window1.Close();
            }

            // On continue tant qu'au moins une fenetre est ouverte
            if (!window.IsOpen() && !window1.IsOpen()) {
                running = false;
            }
        }
    );
    events.AddEventCallback<NkMouseButtonPressEvent>(
        [&](NkMouseButtonPressEvent *event) {

            if (event->IsLeft()) {

                if (event->GetWindowId() == id1) {
                    std::cout << "Clic gauche reçu par la fenêtre 1"<< std::endl;
                }
                else if (event->GetWindowId() == id2) {
                    std::cout << "Clic gauche reçu par la fenêtre 2"<< std::endl;
                }
            }
        }
    );

    while (running && (window.IsOpen() || window1.IsOpen())) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    return 0;
}