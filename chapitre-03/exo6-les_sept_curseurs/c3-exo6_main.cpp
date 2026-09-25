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

            auto taille = window.GetSize();

            float W = (float)taille.x;
            float H = (float)taille.y;

            float x = (float)e->GetX();
            float y = (float)e->GetY();

            // -----------------------------
            // ZONE 1
            // -----------------------------
            if (x < W / 3 && y < H / 2) {
                window.SetCursor(NkWindow::NkCursorType::Arrow);
            }

            // -----------------------------
            // ZONE 2
            // -----------------------------
            else if (x >= W / 3 &&
                     x < 2 * W / 3 &&
                     y < H / 2) {

                window.SetCursor(NkWindow::NkCursorType::TextInput);
            }

            // -----------------------------
            // ZONE 3
            // -----------------------------
            else if (x >= 2 * W / 3 &&
                     y < H / 2) {

                window.SetCursor(NkWindow::NkCursorType::Hand);
            }

            // -----------------------------
            // ZONE 4
            // -----------------------------
            else if (x < W / 3 &&
                     y >= H / 2) {

                window.SetCursor(NkWindow::NkCursorType::ResizeNS);
            }

            // -----------------------------
            // ZONE 5
            // -----------------------------
            else if (x >= W / 3 &&
                     x < 2 * W / 3 &&
                     y >= H / 2 &&
                     y < 2 * H / 3) {

                window.SetCursor(NkWindow::NkCursorType::ResizeWE);
            }

            // -----------------------------
            // ZONE 6
            // -----------------------------
            else if (x >= 2 * W / 3 &&
                     y >= H / 2 &&
                     y < 2 * H / 3) {

                window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
            }

            // -----------------------------
            // ZONE 7
            // -----------------------------
            else {
                window.SetCursor(NkWindow::NkCursorType::ResizeNESW);
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