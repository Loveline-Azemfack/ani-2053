/*#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKMath/NkMat.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKTime/NkTime.h"
#include <iostream>*/




/*class Fenetre : public  nkentseu::renderer::NkCanvasApp
{
    private:
        nkentseu::math::NkRect2f tete{100, 100, 50, 50};
        nkentseu::float32 speed = 50;

        nkentseu::float32 xspeed = 0;
        nkentseu::float32 yspeed = 0;

        nkentseu::float32 t = 0.f;
        nkentseu::float32 deltaTime = 0.f;
public :
    Fenetre()
    {
        Config().title = "Fenetre nue";
        Config().width = 800;
        Config().height = 600;
        Config().clearColor = nkentseu::renderer::NkColor2D{150, 200, 24, 255};
        
    }

    bool OnInit() override{
        //charge ce qu'il faut; false on ne demarre pas
        return true;
    }
    void OnUpdate(nkentseu::float32 deltaTime) override{
        this->deltaTime = deltaTime;
            // Logique de mise à jour du jeu
            if (this->deltaTime)
                this->deltaTime = 1.0f / 60.0f;
            t += this->deltaTime;
        //avancer dans le monde du jeu seln les mises a jour
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override{

        nkentseu::renderer::NkRenderer2D &r2d = target.GetRenderer2D();
        r2d.DrawFilledRect(tete, nkentseu::renderer::NkColor2D{52, 84, 150, 255});
    }
};

int nkmain(const nkentseu::NkEntryState  & state){
    return nkentseu::renderer::NkCanvasApp::Run<Fenetre>(state);
}

NKENTSEU_DEFINE_APP_DATA(([]()){
    NkAppData d{};
    d.appName = "fenetre de dessin";
    d.appVersion = "1.0.0";
    return d;
})() );*/

 //-------------------------------------------------------------
 //                 EXERCICE4
 //--------------------------------------------------------------

 /*
int nkmain(const nkentseu::NkEntryState& state)
{
    nkentseu::NkWindowConfig config{};
    config.title = "fenetre de dessin";
    config.width = 800;
    config.height = 600;
    //return NkCanvasApp::Run<Fenetre>(state);

    nkentseu::NkWindow window;
    if(!window.Create(config)){
        logger.Error("failed to create window");
        return 1;
    }

    //cible
    nkentseu::NkContextDesc contextDesc;
    contextDesc.api = nkentseu::NkGraphicsApi::NK_GFX_API_OPENGL;

    nkentseu::renderer::NkRenderWindow renderwindow(window, contextDesc);

    if(!renderwindow.IsValid()){
        logger.Error("Failed to initializa render window");
        return 2;
    }

    bool running = true;
    auto &eventSystem = nkentseu::NkEvents();

    nkentseu::NkClock clock;
    nkentseu::NkChrono chrono;
    float t = 0.f;

    while (running)
    {
        nkentseu::float32 dt = clock.Tick().delta;
        //t += (float32)chrono.Elapsed().milliseconds* 0.001f;
        if(dt > 0.1f)
            dt = 1.0f/60.0f;
        t += dt;

        nkentseu::NkEvent * event;
        while(eventSystem.PollEvent(event)){
            if(event->Is<nkentseu::NkWindowCloseEvent>()){
                running =  false;
            }
        }
        renderwindow.Clear(nkentseu::renderer::NkColor2D{150, 200, 24, 255});

        nkentseu::renderer::NkRenderer2D &r2d = renderwindow.GetRenderer2D();
        const nkentseu::float32 hp = 60.0f + 28.f * nkentseu::math::NkSin(t *  2.f); //hauteur
        const nkentseu::float32 cx = 500, cy =500;
        const nkentseu::math::NkRect2f box(cx - hp, cy - hp, hp*2.f, hp*2.f);
        r2d.DrawFilledRect(box, nkentseu::renderer::NkColor2D{30, 40, 130, 255});
        renderwindow.Display();
    }

    return 0;
}
    */

#include <iostream>
#include <cmath>
#include <string>

int main(){
    int minx, maxx, miny, maxy ;
    int InTheworldX[4];
    int InTheworldY[4];

    int c;
    int s;
    int nbre_refuse  = 0;
    int n;
    std::cin>> n;

    for(int i = 0; i < n; i++){
        std::string nom;
        int w, h, px, py, ox, oy, sx, sy;
        int angle;

        std::cin>> nom >> w >> h >> px >> py >> ox >> oy >> sx >> sy >> angle;

        angle = angle % 360; //on convertis la valeur entree  en celle d'un vrai angle
        
        if (angle < 0)
        {
            angle += 360;
        }

        if(angle % 90 != 0){
            std::cout <<nom<<" ANGLE REFUSE" << std::endl;
            nbre_refuse++;
            continue; //pour passer au rectangle suivant
        }

        if (angle == 0)
        {
            c = 1;
            s = 0;
        }
        else if (angle == 90)
        {
            c = 0;
            s = 1;
        }
        else if (angle == 180)
        {
            c = -1;
            s = 0;
        }
        else
        {
            c = 0;
            s = -1;
        }
        int xs[4] = {0, w, w, 0};
        int ys[4] = {0, 0, h, h};

        for (int i = 0; i < 4; i++)
        {
            int x = xs[i];
            int y = ys[i];

            int ax = (x - ox) * sx;
            int ay = (y - oy) * sy;

            int rx = ax * c - ay * s;
            int ry = ax * s + ay * c;

            InTheworldX[i] = px + rx;
            InTheworldY[i] = py + ry;
        }

        minx = InTheworldX[0];
        maxx = InTheworldX[0];

        miny = InTheworldY[0];
        maxy = InTheworldY[0];

        for (int i = 1; i < 4; i++)
        {
            if (InTheworldX[i] < minx)
            {
                minx = InTheworldX[i];
            }

            if (InTheworldX[i] > maxx)
            {
                maxx = InTheworldX[i];
            }

            if (InTheworldY[i] < miny)
            {
                miny = InTheworldY[i];
            }

            if (InTheworldY[i] > maxy)
            {
                maxy = InTheworldY[i];
            }
        }
        std::cout << nom << " COINS ";

        for (int i = 0; i < 4; i++)
        {
            std::cout << InTheworldX[i] << " " << InTheworldY[i] << " ";
        }

        std::cout << std::endl;

        std::cout << nom << " BOITE "
        << minx << " " << miny << " "
        << maxx << " " << maxy << std::endl;
    }

    std::cout <<"REFUSES "<< nbre_refuse << std::endl;
    return 0;
}