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

    auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();

    logger.Info("Window X : {}", windowSize.x);
    logger.Info("Window Y : {}", windowSize.y);

    logger.Info("Surface width : {}", surface.width);
    logger.Info("Surface height : {}", surface.height);

    logger.Info("DPI Scale : {}", window.GetDpiScale());

    auto width = windowSize.x;
    auto height = windowSize.y;
    auto surfaceWidth = surface.width;
    auto surfaceHeight = surface.height;
    auto dpi = window.GetDpiScale();

    std::cout<<"Fenetre : "<< width << " X " <<height <<" | Surface : "<< surface.width << " X " <<surface.height<< " | Facteur d'echelle (DPI) : "<< window.GetDpiScale() << std::endl;
    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}