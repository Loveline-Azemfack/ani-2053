#include "NKWindow/NKMain.h"
#include "NKWindow/Core/NkWindow.h"
#include "NKWindow/Core/NkWindowConfig.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Ma fenetre";
    cfg.width = 1280;
    cfg.height = 720;

    //cfg.minWidth = 600;
    //cfg.minHeight = 400;
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable =  true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;
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

    /*auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();

    logger.Info(
        "Fenetre : {} x {} | Surface : {} x {} | Facteur d'echelle (DPI) : {}",
        windowSize.x,
        windowSize.y,
        surface.width,
        surface.height,
        window.GetDpiScale()
    );*/
    bool EstModifie = false;
    events.AddEventCallback<NkWindowResizeEvent>(
        [&](NkWindowResizeEvent *) {

            auto taille = window.GetSize();

            NkString title = cfg.title;

            if (!EstModifie)
                title += "*";

            title += " - ";
            title += NkString::Fmtf("%u", taille.x);
            title += " x ";
            title += NkString::Fmtf("%u", taille.y);

            window.SetTitle(title);
        }
    );

    events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e) {
            events.AddEventCallback<NkMouseButtonPressEvent>(
                [&](NkMouseButtonPressEvent *e) {
                    if (e->IsLeft()) {
                        std::cout << "Clic gauche : capture active" << std::endl;
                        window.CaptureMouse(true);
                    }
                }
            );
            std::cout << "Souris : "
                << e->GetX()
                << " ; "
                << e->GetY()
                << std::endl;
            events.AddEventCallback<NkMouseButtonReleaseEvent>(
                [&](NkMouseButtonReleaseEvent *e) {
                    if (e->IsLeft()) {
                        std::cout << "Clic gauche : capture liberee" << std::endl;
                        window.CaptureMouse(false);
                    }
                }
            );
        }
    );


    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);

    }

    window.Close();

    return 0;
}