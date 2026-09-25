#include "NKWindow/NKMain.h"
#include "NKWindow/Core/NkWindow.h"
#include "NKWindow/Core/NkWindowConfig.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Capture souris";
    cfg.width = 1280;
    cfg.height = 720;

    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;

    NkWindow window(cfg);

    if (!window.IsValid()) {
        return 1;
    }

    bool running = true;
    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *) {
            running = false;
        }
    );

    // Déplacement de la souris
    events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e) {
            std::cout << "Souris : "
                      << e->GetX()
                      << " ; "
                      << e->GetY()
                      << std::endl;
        }
    );

    // Appui sur le bouton gauche : activation de la capture
    events.AddEventCallback<NkMouseButtonPressEvent>(
        [&](NkMouseButtonPressEvent *e) {
            if (e->IsLeft()) {
                std::cout << "Clic gauche : capture active"
                          << std::endl;

                window.CaptureMouse(true);
            }
        }
    );

    // Relâchement du bouton gauche : libération de la capture
    events.AddEventCallback<NkMouseButtonReleaseEvent>(
        [&](NkMouseButtonReleaseEvent *e) {
            if (e->IsLeft()) {
                std::cout << "Clic gauche : capture liberee"
                          << std::endl;

                window.CaptureMouse(false);
            }
        }
    );

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}