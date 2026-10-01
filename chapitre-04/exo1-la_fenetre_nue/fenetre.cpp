#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"

using namespace nkentseu;
using namespace nkentseu::renderer;

class Fenetre : public NkCanvasApp
{
public:
    Fenetre()
    {
        Config().title = "Fenetre nue";
        Config().width = 800;
        Config().height = 600;
        Config().clearColor = NkColor2D{150, 200, 24, 255};
    }
};

int nkmain(const NkEntryState& state)
{
    return NkCanvasApp::Run<Fenetre>(state);
}