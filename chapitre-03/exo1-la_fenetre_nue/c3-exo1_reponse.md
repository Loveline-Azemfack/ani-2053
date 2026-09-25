# EXERCICE1:
Ici, il est question d'ecrire un plus petit programme qui ouvre une fenetre, la garde ouverte et se termine proprement:
Alors c'est le petit programme observe dans main.cpp dont les parties de l'enonce sont les suivantes:  
## Partie du programme qui ouvre la fenetre
```cpp
    NkWindow window(cfg)
```

cette partie montre bien que la fenetre doit s'ouvrir a ce niveau la condition qui suit apres c'est pour le cas contraire


## Partie du programme qui la garde ouverte

Dans mon programme, la fenêtre est maintenue ouverte grâce à la boucle :

```cpp
while (running && window.IsOpen()) {
    events.PollEvents();
    NkClock::Sleep((int64)10);
}
```
La condition `running && window.IsOpen()` permet de continuer la boucle tant que le programme fonctionne et que la fenêtre est ouverte.
`events.PollEvents()` permet de récupérer et de traiter les événements de la fenêtre.
`NkClock::Sleep((int64)10)` permet de faire une courte pause entre deux passages dans la boucle.


## Se termine proprement

Dans mon programme, la fermeture est gérée avec l'événement `NkWindowCloseEvent`.

```cpp
events.AddEventCallback<NkWindowCloseEvent>(
    [&](NkWindowCloseEvent *) {
        running = false;
    }
);
```
Lorsque l'utilisateur demande la fermeture de la fenêtre, `running` devient `false`. La condition de la boucle `while` devient alors fausse et la boucle s'arrête.
Ensuite, j'utilise :
```cpp
window.Close();
```
pour fermer explicitement la fenêtre.
Enfin :
```cpp
return 0;
```
permet de terminer normalement le programme.

## COMPTE DES LIGNES
Mon programme fait au total **38** lignes de codes et l'espace entre les lignes  y est compris. si on ne compte pas l'espace entre lignes, alors jai **32** lignes de code.

## PREUVE DE DONSTRUCTION ET D'EXECUTION
### CONSTRUCTION
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
│  ✓ Build Successful                                                             Time: 2.26s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.26s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
#### TEMPS DE CONSTRUCTION
Time:           2.26s

### EXECUTION
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

D:\Projets\Rihen\JENGA+NKENTSEU\FirstWindow\pop\NewWindow\NewWindow.jenga:15: SyntaxWarning: invalid escape sequence '\L'
  useconfig("Loveline\Loveline.jenga")

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  MyWindow.exe
     D:\Projets\Rihen\JENGA+NKENTSEU\FirstWindow\pop\NewWindow\Build\Bin\Debug-Windows\MyWindow\MyWindow.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

fenetre cree avec succes!!
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (33.26s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
On remarque bien le message suivant: **fenetre cree avec succes!!**

#### CAPTURE VIDEO
<video controls width="700">
  <source src="exo1-print3.mp4" type="video/mp4">
</video>

## RETROUVONS CHACUNE DANS LE CHAPITRE

D'après le programme fourni dans le chapitre, j'ai retrouvé plusieurs éléments dans mon programme.

* `nkmain` : il permet de fournir le point d'entrée du programme avec le système Nkentseu.

* `NkWindowConfig cfg` : il permet de créer la configuration de la fenêtre.

* `cfg.title`, `cfg.width` et `cfg.height` : ils permettent de définir respectivement le titre, la largeur et la hauteur de la fenêtre.

* `NkWindow window(cfg)` : il permet de créer la fenêtre à partir de la configuration définie.

* `window.IsOpen()` : il permet de vérifier si la fenêtre est ouverte.

* `while (running && window.IsOpen())` : dans mon programme, cette boucle permet de maintenir la fenêtre ouverte tout en traitant les événements.

* `return 0` : il permet de terminer normalement le programme.

Les lignes suivantes ont été ajoutées par moi pour compléter le programme du chapitre :

* `#include "NKEvent/NkWindowEvent.h"` : je l'ai ajouté pour pouvoir utiliser l'événement de fermeture de la fenêtre.

* `#include "NKTime/NkClock.h"` : je l'ai ajouté pour pouvoir utiliser `NkClock::Sleep`.

* `bool running = true` : je l'ai ajouté pour pouvoir contrôler la boucle du programme.

* `NkEventSystem &events = NkEvents()` : je l'ai ajouté pour récupérer le système de gestion des événements.

* `events.AddEventCallback<NkWindowCloseEvent>(...)` : je l'ai ajouté pour détecter lorsque l'utilisateur demande la fermeture de la fenêtre.

* `running = false` : je l'ai ajouté pour arrêter la boucle lorsque l'utilisateur ferme la fenêtre.

* `events.PollEvents()` : je l'ai ajouté dans la boucle pour récupérer et traiter les événements. Cela permet aussi à la fenêtre de continuer à répondre.

* `NkClock::Sleep((int64)10)` : je l'ai ajouté pour faire une courte pause entre deux passages dans la boucle.

* `window.Close()` : je l'ai ajouté pour fermer explicitement la fenêtre avant de terminer le programme.

* `std::cout<<"fenetre cree avec succes!!";` : je l'ai ajouté pour afficher un message permettant de vérifier que la fenêtre a bien été créée.

Mon programme est donc basé sur le programme minimal présenté dans le chapitre, mais certaines lignes ont été ajoutées par moi pour gérer les événements, maintenir la fenêtre réactive et permettre sa fermeture propre.



## DIFFICULTES
Il faut noter que j'ai rencontree une difficultee pour reconstruire la fenetre avec le plus petit programme fourni par le chapitre car ca ne  reconnaissait pas les modules window ou windowcnfig. Pour cela, j'ai parcourue le tutoriel **Fenetre-01** de nkentseu et j'a vu un **using namespace nkentseu;** et c'est quand je l'ai introduit que j'ai pu **build** mon programme et enfin voir ma fenetre