# EXERCICE :
L'objectif ici est de tester lces 7 configurations : **resizable, movable, closable, minimizable, maximizable, canFullscreen, modal = true** Pour cela je ne vais pas dire que je vais ouvrir en une eule fois 7 fenetres mais je vais plutot ecrire le programme qui me permet d'ouvrir une fenetre et a chaque fois, changer ses droits en utilisant le programme de base observe dans le main.cpp de l'exercice:  
Ok commencons pas desactiver resizable
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

    cfg.resizable = false;      // droit désactivé
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

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observation:
Lorsque je desactive resizable et je fais mon `jenga run`, j'obtiens une fenetre que je peux toujours redimensionner mais cette fois lorsque j'agrandi, le contenu a jouter est tout noir et lorsque je diminue ca diminue juste, si je dminue et je reessaie d'agrandir, le contenu ajouter reste toujours noir.

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

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations:


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

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observation:



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

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observation

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

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations


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

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations


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

    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

```

### Observations
