#include "D:\Projets\Rihen\Nkentseu\Applications\NkRef\src\NkRef\NkRefView.h"

#include <cmath>
#include <iostream>

using nkref::NkRefView;
using nkref::NkVec2f;

constexpr float EPSILON = 0.001f;

// Test 1 : WorldToPixel doit inverser PixelToWorld.
bool aller_retour()
{
    NkRefView camera;
    NkVec2f viewport{1280.0f, 720.0f};
    NkVec2f pixel{345.67f, 234.56f};

    camera.center = {12.0f, -8.0f};
    camera.zoom = 2.5f;

    camera.ZoomAtPixel(1.7f, pixel, viewport);

    NkVec2f monde = camera.PixelToWorld(pixel, viewport);
    NkVec2f retour = camera.WorldToPixel(monde, viewport);

    return std::fabs(retour.x - pixel.x) < EPSILON &&
           std::fabs(retour.y - pixel.y) < EPSILON;
}

// Test 2 : le point du monde sous le curseur doit rester fixe après le zoom.
bool point_fixe()
{
    NkRefView camera;
    NkVec2f viewport{1280.0f, 720.0f};
    NkVec2f pixel{300.0f, 200.0f};

    NkVec2f avant = camera.PixelToWorld(pixel, viewport);

    camera.ZoomAtPixel(2.0f, pixel, viewport);

    NkVec2f apres = camera.PixelToWorld(pixel, viewport);

    return std::fabs(avant.x - apres.x) < EPSILON &&
           std::fabs(avant.y - apres.y) < EPSILON;
}

// Test 3 : le zoom doit toujours respecter ses limites.
bool bornes()
{
    NkRefView camera;

    camera.ZoomAtPixel(1000.0f, {640.0f, 360.0f}, {1280.0f, 720.0f});

    bool maximumRespecte =
        camera.zoom >= NkRefView::kZoomMin &&
        camera.zoom <= NkRefView::kZoomMax;

    camera.ZoomAtPixel(0.00001f, {640.0f, 360.0f}, {1280.0f, 720.0f});

    bool minimumRespecte =
        camera.zoom >= NkRefView::kZoomMin &&
        camera.zoom <= NkRefView::kZoomMax;

    return maximumRespecte && minimumRespecte;
}

// Test 4 : lorsque le zoom diminue, l'espacement de la grille ne diminue pas.
bool grille()
{
    NkRefView camera;
    const float minPixels = 20.0f;

    camera.zoom = 4.0f;
    float precedent = camera.GridSpacing(minPixels);

    camera.zoom = 2.0f;
    float actuel = camera.GridSpacing(minPixels);

    if (actuel < precedent)
        return false;

    precedent = actuel;

    camera.zoom = 1.0f;
    actuel = camera.GridSpacing(minPixels);

    if (actuel < precedent)
        return false;

    precedent = actuel;

    camera.zoom = 0.5f;
    actuel = camera.GridSpacing(minPixels);

    return actuel >= precedent;
}

// Test 5 : Reset doit remettre le centre à zéro et le zoom à un.
bool origine()
{
    NkRefView camera;

    camera.ZoomAtPixel(2.5f, {300.0f, 200.0f}, {1280.0f, 720.0f});
    camera.PanByPixels(150.0f, 80.0f);

    camera.Reset();

    return std::fabs(camera.center.x) < EPSILON &&
           std::fabs(camera.center.y) < EPSILON &&
           std::fabs(camera.zoom - 1.0f) < EPSILON;
}

int main()
{
    std::cout << "TEST aller_retour : "
              << (aller_retour() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST point_fixe : "
              << (point_fixe() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST bornes : "
              << (bornes() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST grille : "
              << (grille() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST origine : "
              << (origine() ? "OK" : "ECHEC") << '\n';

    return 0;
}