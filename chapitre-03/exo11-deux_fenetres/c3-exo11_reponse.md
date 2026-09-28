# EXERCICE12:
Pour realiser cet exercie, il a fallu que je me remette en questio sur comment afficher deux fenetre, et puis je me suis dis, si j'ai pu afficher, il suffit de doubler les variables pour afficher les deux fenetres, du coup j'ai donc duliquer mais variables, mais attention,ce ne sont pas toutes les variables quon duplique par exemple celle de **NkEventSystem** qui est celle `NkEventSystem &events = NkEvents();` car c'est une seule variable qui va devoir gerer l'ensemble des evenements ni la variable **running** qui est celle ci `bool running = true;`  par contre, tout ce qui concerne les variables window il faut les dupliquer car elles sont propre aux fenetre. Vous pouvez le remarquer a travers le code present dans le main.cpp de ce dossier.  

## Ouverture de la fenetre
alors pour cette partie, je n'avais pas encore commence a gere les `GetId` pour les fermetures tout ce que je voulais c'etait simplement de les ouvrir.
```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"
#include <iostream>

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Ma fenetre 1";
    cfg.width = 1280;
    cfg.height = 720;
    cfg.centered = false;
    cfg.x = 100;
    cfg.y = 100;

    NkWindowConfig cfg1;
    cfg1.title = "Ma fenetre 2";
    cfg1.width = 1320;
    cfg1.height = 920;

    NkWindow window(cfg);
    NkWindow window1(cfg1);

    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre 1 echouee");
        return -1;
    }

    if (!window1.IsOpen()) {
        logger.Error("[app] creation fenetre 2 echouee");
        return -1;
    }

    std::cout << "Fenetre 1 creee avec succes !" << std::endl;
    std::cout << "Fenetre 2 creee avec succes !" << std::endl;

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *event) {
                running = false;
    );

    while (running && (window.IsOpen() || window1.IsOpen())) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    return 0;
}
```
Ici j'ai desactiver la configuration de centrage de la premiere fenetre car quand je faisais mon run, ca affichait les deux fenetres de  maniere superposee et pour une personne qui ne connaissait pas ce que je faisais elle n'allait jamais ssavoir qu'il ya deux fenetres superposees, alors j'ai donc desacativer cela pour la premiere et j'ai gere ses positions, alors j'ai une fentre qui s'affiche a un bout de mon ecran et une autre au centre. Voici donc les resultats de ma compilation et mon execution pour ce premier cas:
```powershell
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
│  ✓ Build Successful                                                             Time: 2.92s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.92s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```
EXECUTION
```powershell
PS D:\Projets\Rihen\JENGA+NKENTSEU\FirstWindow\pop\NewWindow> jenga run  

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
fenetre 2 cree avec succes!!
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (18.99s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

Et ensuite j'ai l'affichage de mes fenetres

### Gerer  la fermeture d ela fenetre 
Quand j'ai ouverte ces deux fentres, lorsque je fermais une, les deux ce fermaient alors en meme temps du coup pour resoudre cela je suis partie regarder dans mes include et j'ai vu un fichier NkWindowId.h puis, j'ai aussi regarder dans Nkwindow.h et NkEvent.h et j'ai trouver des methodes liees aux id de windows, qui sont celles que j'ai utiliser dans mon code comme: `GetId()`et `GetWindowId()` respectivement dans NkWindow.h et NKEvent.h.
Alors j'ai implementer exactement le code present ci dessous:
```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"
#include <iostream>

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Ma fenetre 1";
    cfg.width = 1280;
    cfg.height = 720;
    cfg.centered = false;
    cfg.x = 100;
    cfg.y = 100;

    NkWindowConfig cfg1;
    cfg1.title = "Ma fenetre 2";
    cfg1.width = 1320;
    cfg1.height = 920;

    NkWindow window(cfg);
    NkWindow window1(cfg1);

    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre 1 echouee");
        return -1;
    }

    if (!window1.IsOpen()) {
        logger.Error("[app] creation fenetre 2 echouee");
        return -1;
    }

    std::cout << "Fenetre 1 creee avec succes !" << std::endl;
    std::cout << "Fenetre 2 creee avec succes !" << std::endl;

    // Recuperation des identifiants des deux fenetres
    NkWindowId id1 = window.GetId();
    NkWindowId id2 = window1.GetId();

    std::cout << "ID fenetre 1 : " << id1 << std::endl;
    std::cout << "ID fenetre 2 : " << id2 << std::endl;

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *event) {

            // Identifiant de la fenetre qui demande la fermeture
            NkWindowId id = event->GetWindowId();

            if (id == id1) {
                std::cout << "Fermeture de la fenetre 1" << std::endl;
                window.Close();
            }
            else if (id == id2) {
                std::cout << "Fermeture de la fenetre 2" << std::endl;
                window1.Close();
            }

            // On continue tant qu'au moins une fenetre est ouverte
            if (!window.IsOpen() && !window1.IsOpen()) {
                running = false;
            }
        }
    );

    while (running && (window.IsOpen() || window1.IsOpen())) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    return 0;
}
```
 Puis j'ai compiler et executer comme ceci:  
**COMPILATION:**
```cpp

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
│  ✓ Build Successful                                                             Time: 2.24s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.24s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

**EXECUTION:**  
```cpp
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

Fenetre 1 creee avec succes !
Fenetre 2 creee avec succes !
ID fenetre 1 : 1
ID fenetre 2 : 2
Fermeture de la fenetre 2
Fermeture de la fenetre 1

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (7.56s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

**PREUVE:**
<video controls width="700">
  <source src="DEUX-FENETRE.mp4" type="video/mp4">
</video>

## pour chaque clic, laquelle l'a reçu
Pour cette partie j'ai fais un ctrl+shift+F dans mon workspace, et j'ai chercher **MouseButton** j'ai recu un resultat de recherche elargie ensuite j'ai donc taper **MouseButtonPress** et je me suis rendu dans `NkMouseEvent.h` j'ai vu des fonctions en commentaires et j'ai un peu lu, ensuite j'ai vu ceci:
```cpp
void OnMouseButtonPress(nkentseu::NkMouseButtonPressEvent& event) {
			using namespace nkentseu;

			// Clic droit = menu contextuel
			if (event.IsRight()) {
				ShowContextMenu(event.GetX(), event.GetY());
				event.MarkHandled();
			}

```

J'ai donc essayer d'assimiler ceci en utilisant un `AddEventCallBack` a ma variable EventSystem et pui j'ai donc ajouter cettte portion de code:
```cpp
events.AddEventCallback<NkMouseButtonPressEvent>(
        [&](NkMouseButtonPressEvent *event) {

            if (event->IsLeft()) {

                if (event->GetWindowId() == id1) {
                    std::cout << "Clic gauche reçu par la fenêtre 1"<< std::endl;
                }
                else if (event->GetWindowId() == id2) {
                    std::cout << "Clic gauche reçu par la fenêtre 2"<< std::endl;
                }
            }
        }
    );
```

Puis j'ai compiler et executer:
### COMPILATION:
```powershell

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
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.04s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
### EXECUTION
```powershell
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

Fenetre 1 creee avec succes !
Fenetre 2 creee avec succes !
ID fenetre 1 : 1
ID fenetre 2 : 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 2
Clic gauche re├ºu par la fen├¬tre 1
Clic gauche re├ºu par la fen├¬tre 1
Fermeture de la fenetre 1
Fermeture de la fenetre 2

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (19.32s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

### PREUVE
<video controls width="700">
  <source src="clic-par-fenetre.mp4" type="video/mp4">
</video>

## CE QU'IL MANQUERAIT POUR DESSINER DANS LES DEUX
Apres le travail precedent effectuer, s'il faudrait passer au dessin dans chaque fenetre, cela risquerait etre complexe car il pourrait manquer un lien entre chaque fenêtre et son rendu ou bien encore son contexte de rendu car on veut etre capable d'effectuer un dessin dans une fenetre et dire au systeme qu'il voudrait dessiner dans telle fenetre, selon son id donc on voudrait renvoyer les actions de dessin a la bonne fenetre. mais c'est une action qui reste encore a revoir pour mon cas mais une alternative serait d'essayer de le faire avec l'API win32
