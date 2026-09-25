# EXERCICE 6

Pour faire cet exercice, mon travail a reposé sur des recherches dans les fichiers de Nkentseu.

J'ai d'abord cherché comment gérer les différents types de curseurs. Je suis allé dans le fichier `NkWindowCursor.cpp`, mais je n'ai pas trouvé directement ce qui me permettait de réaliser les sept zones.

J'ai donc utilisé la recherche dans les fichiers avec **Ctrl + Shift + F** en recherchant le mot `cursor`.

En parcourant les résultats, je suis arrivé dans `NKWindow.h`, où j'ai trouvé l'énumération :

```cpp
enum class NkCursorType {

    Arrow = 0,       ///< flèche standard
    TextInput,       ///< I-beam (saisie texte)
    Hand,            ///< main (lien)
    ResizeNS,        ///< redimensionnement vertical ↕
    ResizeWE,        ///< redimensionnement horizontal ↔
    ResizeNWSE,      ///< diagonale ↘↖
    ResizeNESW       ///< diagonale ↗↙

};
```

Cette énumération m'a permis de connaître les sept types de curseurs disponibles et de les associer aux sept zones de ma fenêtre.

## DÉCOUPAGE DE LA FENÊTRE

Au départ, mon découpage était assez irrégulier. Après vérification, j'ai décidé de modifier le découpage afin que les sept zones soient plus équilibrées et plus faciles à tester.
J'ai donc divisé la largeur de la fenêtre en sept parties :
```cpp
W / 7
```

Chaque zone occupe ainsi approximativement un septième de la largeur de la fenêtre et toute sa hauteur.
Le découpage obtenu est :

```
┌────┬────┬────┬────┬────┬────┬────┐
│ Z1 │ Z2 │ Z3 │ Z4 │ Z5 │ Z6 │ Z7 │
│    │    │    │    │    │    │    │
│    │    │    │    │    │    │    │
└────┴────┴────┴────┴────┴────┴────┘
```

Ce découpage permet de passer plus facilement la souris dans chacune des sept zones.
## TEST1:
```cpp
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

            // ZONE 1
            if (x < W / 7) {
                window.SetCursor(NkWindow::NkCursorType::Arrow);
            }

            // ZONE 2
            else if (x < 2 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::TextInput);
            }

            // ZONE 3
            else if (x < 3 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::Hand);
            }

            // ZONE 4
            else if (x < 4 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::ResizeNS);
            }

            // ZONE 5
            else if (x < 5 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::ResizeWE);
            }

            // ZONE 6
            else if (x < 6 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
            }

            // ZONE 7
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
```
### DESCRIPTION DE CE QUI SE PASSE AU SURVOL

Lorsque je déplace la souris dans les différentes zones, le curseur change en fonction de la zone dans laquelle il se trouve.

#### ZONE 1
Le curseur prend la forme d'une flèche normale.
Elle correspond à :

```cpp
NkWindow::NkCursorType::Arrow
```

#### ZONE 2
Le curseur prend la forme utilisée pour la saisie de texte.
Elle correspond à :

```cpp
NkWindow::NkCursorType::TextInput
```

#### ZONE 3
Le curseur prend la forme d'une main, comme celle généralement utilisée pour indiquer un élément cliquable.
Elle correspond à :
```cpp
NkWindow::NkCursorType::Hand
```

#### ZONE 4
Le curseur indique un redimensionnement vertical :
```
↕
```

Il correspond à :

```cpp
NkWindow::NkCursorType::ResizeNS
```
#### ZONE 5

Le curseur indique un redimensionnement horizontal :
```
↔
```

Il correspond à :
```cpp
NkWindow::NkCursorType::ResizeWE
```
#### ZONE 6
Le curseur indique un redimensionnement diagonal allant du bas droit vers le haut gauche :
```
↘↖
```
Il correspond à :
```cpp
NkWindow::NkCursorType::ResizeNWSE
```
#### ZONE 7
Le curseur indique un redimensionnement diagonal dans l'autre direction :
```
↗↙
```
Il correspond à :
```cpp
NkWindow::NkCursorType::ResizeNESW
```


## CONSTRUCTION ET VÉRIFICATION

Après avoir modifié le découpage des sept zones, j'ai construit le programme afin de vérifier qu'il compile correctement.

### Sortie de construction

```
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
D:\Projets\Rihen\JENGA+NKENTSEU\FirstWindow\pop\NewWindow\NewWindow.jenga:15: SyntaxWarning: invalid escape sequence '\L'
  useconfig("Loveline\Loveline.jenga")

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. MyWindow [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MyWindow                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MyWindow\MyWindow.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.49s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.49s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```

Cette sortie permet de vérifier que le programme utilisé pour l'exercice est bien celui que j'ai réellement construit.

### Vérification de l'exécution

J'ai ensuite lancé le programme et vérifié le comportement des sept zones en déplaçant la souris dans chacune d'elles.

J'ai également effectué le test demandé dans le deuxième volet en définissant le curseur une seule fois au démarrage.

### Preuve

J'ajoute une capture d'écran ou une courte vidéo montrant le fonctionnement des différentes zones
<video controls width="700">
  <source src="test1.mp4" type="video/mp4">
</video>


## TEST 2
```cpp
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
    window.SetCursor(NkWindow::NkCursorType::Hand);
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
/*
    events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e) {

            auto taille = window.GetSize();

            float W = (float)taille.x;
            float H = (float)taille.y;

            float x = (float)e->GetX();

            // ZONE 1
            if (x < W / 7) {
                window.SetCursor(NkWindow::NkCursorType::Arrow);
            }

            // ZONE 2
            else if (x < 2 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::TextInput);
            }

            // ZONE 3
            else if (x < 3 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::Hand);
            }

            // ZONE 4
            else if (x < 4 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::ResizeNS);
            }

            // ZONE 5
            else if (x < 5 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::ResizeWE);
            }

            // ZONE 6
            else if (x < 6 * W / 7) {
                window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
            }

            // ZONE 7
            else {
                window.SetCursor(NkWindow::NkCursorType::ResizeNESW);
            }
        }
    );*/
    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);

    }

    window.Close();

    return 0;
}
```

Pour le deuxième test, j'ai défini le curseur une seule fois au démarrage de la fenêtre :

`window.SetCursor(NkWindow::NkCursorType::Hand);`

J'ai ensuite désactivé le code qui modifiait le curseur dans NkMouseMoveEvent.
Le programme démarre donc avec le curseur Hand, mais aucun changement de curseur n'est effectué lorsque je déplace la souris.

### DESCRIPTION DE CE QUI SE PASSE AU SURVOL

Lorsque je déplace la souris dans les différentes zones de la fenêtre, le curseur reste inchangé et conserve la forme de la main pendant tout le déplacement.


### Preuve

J'ajoute une capture d'écran ou une courte vidéo montrant le fonctionnement de ce deplacement
<video controls width="700">
  <source src="test2.mp4" type="video/mp4">
</video>

## RESUME

| Test       | Code utilisé                              | Ce que je vérifies                                                             |
| ---------- | ----------------------------------------- | ------------------------------------------------------------------------------ |
| **Test 1** | `SetCursor()` dans `NkMouseMoveEvent`     | Le curseur change dans les 7 zones                                             |
| **Test 2** | `SetCursor()` une seule fois au démarrage | Le comportement du curseur est uniforme, il ne change plus|
