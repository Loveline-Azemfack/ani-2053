#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2DTypes.h"
#include "NKTime/NkTime.h"

using namespace nkentseu;
using namespace nkentseu::renderer;

int nkmain(const NkEntryState& state)
{
    NkWindowConfig config{};
    config.title = "exercice10: Interface qui ne defile pas";
    config.width = 800;
    config.height = 600;

    NkWindow window;

    if (!window.Create(config))
    {
        logger.Error("Failed to create window");
        return 1;
    }

    if (!window.IsOpen())
    {
        logger.Error("Window is not open");
        return 1;
    }

    NkContextDesc contextDesc;
    contextDesc.api = NkGraphicsApi::NK_GFX_API_OPENGL;

    NkRenderWindow renderwindow(window, contextDesc);

    if (!renderwindow.IsValid())
    {
        logger.Error("Failed to initialize render window");
        return 2;
    }

    bool running = true;
    auto& eventSystem = NkEvents();

    NkClock clock;

    float centreX = 400.0f;

    while (running && window.IsOpen())
    {
        float32 dt = clock.Tick().delta;

        if (dt > 0.1f)
            dt = 1.0f / 60.0f;

        NkEvent* event;
        while (eventSystem.PollEvent(event))
        {
            if (event->Is<NkWindowCloseEvent>())
            {
                running = false;
            }
        }

        centreX += 100.0f * dt;

        renderwindow.Clear(NkColor2D{18, 18, 24, 255});

        auto& renderer = renderwindow.GetRenderer2D();

        // Vue du monde
        NkView2D view;
        view.center = {centreX, 300.0f};
        view.size = {800.0f, 600.0f};

        renderer.SetView(view);

        // Monde plus large que la fenêtre
        for (int i = 0; i < 20; i++)
        {
            renderer.DrawFilledRect(
                {i * 100.0f, 250.0f, 60.0f, 60.0f},
                NkColor2D{255, 0, 0, 255}
            );
        }

        // Remettre la vue écran pour l'interface
        renderwindow.ResetView();

        // Barre d'interface
        renderer.DrawFilledRect(
            {0.0f, 0.0f, 800.0f, 70.0f},
            NkColor2D{40, 40, 50, 255}
        );

        /*
        // Version fautive sans ResetView :
        // La barre utilise encore la vue du monde.

        renderer.DrawFilledRect(
            {0.0f, 0.0f, 800.0f, 70.0f},
            NkColor2D{40, 40, 50, 255}
        );
        */

        renderwindow.Display();
    }

    return 0;
}