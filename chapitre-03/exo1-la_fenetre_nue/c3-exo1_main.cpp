# include "NKWindow/NKWindow.h"
# include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"
#include <iostream>

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