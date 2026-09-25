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

    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
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

    bool EstModifie = false;

    auto MettreAJourTitre = [&]() {
        auto taille = window.GetSize();

        NkString title = cfg.title;

        if (EstModifie)
            title += "*";

        title += " - ";
        title += NkString::Fmtf("%u", taille.x);
        title += " x ";
        title += NkString::Fmtf("%u", taille.y);

        window.SetTitle(title);
    };

    // Titre initial : pas d'astérisque
    MettreAJourTitre();

    // Le redimensionnement est considéré comme une modification
    events.AddEventCallback<NkWindowResizeEvent>(
        [&](NkWindowResizeEvent *) {
            EstModifie = true;
            MettreAJourTitre();
        }
    );

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}