# EXERCICE :
L'objectif ici est de tester lces 7 configurations : **resizable, movable, closable, minimizable, maximizable, canFullscreen, modal = true** Pour cela je ne vais pas dire que je vais ouvrir en une eule fois 7 fenetres mais je vais plutot ecrire le programme qui me permet d'ouvrir une fenetre et a chaque fois, changer ses droits en utilisant le programme de base observe dans le main.cpp de l'exercice:  
Ok commencons par desactiver resizable
## RESIZABLE:
### Programme:
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
    cfg.resizable = false;
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

    events.AddEventCallback<NkWindowResizeEvent>(
        [](NkWindowResizeEvent *e) {
            logger.Info("Taille : {} x {}", e->GetWidth(), e->GetHeight());
        }
    );
    NkWindowConfig currentConfig = window.GetConfig();

    logger.Info("Resizable demande : {}", cfg.resizable);
    logger.Info("Resizable fenetre : {}", currentConfig.resizable);

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}
```

### Observation:
L'executable affiche:
```
[2026-09-24 15:24:55.866] [INF] [default] [main.cpp:48 in nkmain] -> Resizable demande : false
[2026-09-24 15:24:55.866] [INF] [default] [main.cpp:49 in nkmain] -> Resizable fenetre : false
```
Malgré resizable = false, la fenêtre peut toujours être redimensionnée. La configuration retournée par GetConfig() indique pourtant bien false. On constate également que la zone nouvellement créée après l'agrandissement devient noire, ce qui semble correspondre à un problème de rendu lors du redimensionnement.

## MOVABLE:
### Programme:
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

    cfg.resizable = true;
    cfg.movable = false; // droit désactivé
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
        NkWindowConfig currentConfig = window.GetConfig();

    logger.Info("Movable demande : {}", cfg.movable);
    logger.Info("Movable fenetre : {}", currentConfig.movable);

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations:

L'executable nous fourni ceci:
```
[2026-09-24 15:29:18.319] [INF] [default] [main.cpp:48 in nkmain] -> Movable demande : false
[2026-09-24 15:29:18.320] [INF] [default] [main.cpp:49 in nkmain] -> Movable fenetre : false
```
Lorsque movable est désactivé avec la valeur false, la fenêtre peut toujours être déplacée à l'aide de la barre de titre. La configuration retournée par GetConfig() confirme cependant que movable vaut bien false.
## CLOSABLE:
### Programme:
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

    cfg.resizable = true;
    cfg.movable = true; 
    cfg.closable = false; // droit désactivé
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
        NkWindowConfig currentConfig = window.GetConfig();

    logger.Info("closable demande : {}", cfg.closable);
    logger.Info("closable fenetre : {}", currentConfig.closable);

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observation:
L'executabe nous fourni ceci:
```
[2026-09-24 15:33:05.684] [INF] [default] [main.cpp:48 in nkmain] -> closable demande : false
[2026-09-24 15:33:05.685] [INF] [default] [main.cpp:49 in nkmain] -> closable fenetre : false
```
Lorsque closable est désactivé avec la valeur false, la fenêtre peut toujours être fermée. La configuration retournée par GetConfig() indique bien que closable vaut false.


## Minimizable
### Programmes
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

    cfg.resizable = true;
    cfg.movable = true; 
    cfg.closable = true;
    cfg.minimizable = false; // droit désactivé
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
    NkWindowConfig currentConfig = window.GetConfig();

    logger.Info("minimizable demande : {}", cfg.minimizable);
    logger.Info("minimizable fenetre : {}", currentConfig.minimizable);
    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observation
Executable fourni:
```
[2026-09-24 15:52:01.410] [INF] [default] [main.cpp:48 in nkmain] -> minimizable demande : false
[2026-09-24 15:52:01.410] [INF] [default] [main.cpp:49 in nkmain] -> minimizable fenetre : false
```
Lorsque minimizable est désactivé avec la valeur false, la fenêtre ne peut plus être minimisée à l'aide de l'action de minimisation. La configuration retournée par GetConfig() confirme que minimizable vaut false.

## Maximizable
### Programmes
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

    cfg.resizable = true;
    cfg.movable = true; 
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = false; // droit désactivé
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
    NkWindowConfig currentConfig = window.GetConfig();

    logger.Info("maximizable demande : {}", cfg.maximizable);
    logger.Info("maximizable fenetre : {}", currentConfig.maximizable);

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations
L'executable fourni:
```

[2026-09-24 15:59:04.455] [INF] [default] [main.cpp:48 in nkmain] -> maximizable demande : false
[2026-09-24 15:59:04.456] [INF] [default] [main.cpp:49 in nkmain] -> maximizable fenetre : false
```
Lorsque maximizable est désactivé avec la valeur false, la fenêtre ne peut plus être maximisée à l'aide de l'action de maximisation. La configuration retournée par GetConfig() confirme que maximizable vaut false.

## canFullscreen
### Programmes
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

    cfg.resizable = true;
    cfg.movable = true; 
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = false; // droit désactivé
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
        NkWindowConfig currentConfig = window.GetConfig();

    logger.Info("canFullscreen demande : {}", cfg.canFullscreen);
    logger.Info("canFullscreen fenetre : {}", currentConfig.canFullscreen);

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations
Voici l'executable fourni:
```
[2026-09-24 16:02:05.754] [INF] [default] [main.cpp:48 in nkmain] -> canFullscreen demande : false
[2026-09-24 16:02:05.754] [INF] [default] [main.cpp:49 in nkmain] -> canFullscreen fenetre : false
[2026-09-24 16:02:10.447] [INF] [default] [main.cpp:43 in operator()] -> Taille : 1920 x 1920
```
Lorsque canFullscreen est désactivé avec la valeur false, la fenêtre ne peut plus passer en mode plein écran. La configuration retournée par GetConfig() confirme que canFullscreen vaut false.

## Modal
### Programmes
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

    cfg.resizable = true;
    cfg.movable = true; 
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = false; // droit désactivé
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
        NkWindowConfig currentConfig = window.GetConfig();

    logger.Info("modal demande : {}", cfg.modal);
    logger.Info("modal fenetre : {}", currentConfig.modal);

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations
l'executable affiche ceci:
```
[2026-09-24 16:05:53.282] [INF] [default] [main.cpp:48 in nkmain] -> modal demande : false
[2026-09-24 16:05:53.284] [INF] [default] [main.cpp:49 in nkmain] -> modal fenetre : false
```
Lorsque modal est désactivé avec la valeur false, la fenêtre n'est pas modale : il reste possible d'interagir avec les autres fenêtres. La configuration retournée par GetConfig() confirme que modal vaut false.

## TABLEAU RECAPITULATIF

| Configuration   | Valeur testée | Résultat observé                                                                                            |
| --------------- | ------------: | ----------------------------------------------------------------------------------------------------------- |
| `resizable`     |       `false` | La fenêtre peut toujours être redimensionnée. Après agrandissement, la nouvelle zone ajoutée devient noire. |
| `movable`       |       `false` | La fenêtre peut toujours être déplacée avec la barre de titre.                                              |
| `closable`      |       `false` | La fenêtre peut toujours être fermée.                                                                       |
| `minimizable`   |       `false` | La fenêtre ne peut pas être minimisée.                                                                      |
| `maximizable`   |       `false` | La fenêtre ne peut pas être maximisée.                                                                      |
| `canFullscreen` |       `false` | La fenêtre ne peut pas passer en plein écran.                                                               |
| `modal`         |       `false` | La fenêtre n'est pas modale et les autres fenêtres restent accessibles.                                     |
