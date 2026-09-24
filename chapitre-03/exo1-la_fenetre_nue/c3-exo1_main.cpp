# include "NKWindow/NKWindow.h"
# include "NKWindow/NKMain.h"

using namespace nkentseu;
int nkmain(const NkEntryState &state){
    NkWindowconfig cfg;
    cfg.title = "Ma fenetre 1";
    cfg.width = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    if(!window.IsOpen()){
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }

    while (window.IsOpen()){
        while (window.PollEvent(event)) {
            events.PollEvents();
        }
    }
    
    return 0;
}