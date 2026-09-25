# EXERCICE 7:

Pour cet exercice nous allons commencer avec l'experience sans capture pour voir comment la souris se comporte lorsqu'elle sort de la fenetre.

```cpp
events.AddEventCallback<NkMouseMoveEvent>(
    [&](NkMouseMoveEvent *e) {
        std::cout << "Souris : "
                  << e->GetX()
                  << " ; "
                  << e->GetY()
                  << std::endl;
    }
);
```

## SANS CAPTURE

Lorsque je construis puis j'execute le programme, les positions de la souris sont affichees lorsque je deplace la souris dans la fenetre.

On peut voir par exemple :

```text
Souris : 25 ; 332
Souris : 18 ; 335
Souris : 10 ; 338
Souris : 3 ; 342
Souris : 2 ; 350
```

Lorsque la souris sort de la fenetre, les positions ne sont plus affichees.

### REMARQUE

Du point de vue de l'utilisateur, on peut voir que lorsque la souris sort de la fenetre, le suivi s'arrete. Si je commence un glisser dans la fenetre et que je sors de celle-ci, le suivi de la souris est donc interrompu.

## AVEC CAPTURE

Pour cette partie, il a fallu que je me serve de fichiers tels que `NKEvent/NkMouseEvent.h`, `NKEvent/NkEventState.h` et `NkWin32Window.cpp`.

J'ai remarque qu'une fonction parlait deja de la capture de la souris. Je l'ai donc utilisee dans mon programme avec `window.CaptureMouse(true)` pour activer la capture et `window.CaptureMouse(false)` pour la liberer.

Pour que les evenements soient enregistres correctement, j'ai place les evenements de clic et de relachement en dehors de l'evenement de deplacement de la souris. Ils sont ainsi enregistres une seule fois au demarrage.

```cpp
events.AddEventCallback<NkMouseMoveEvent>(
    [&](NkMouseMoveEvent *e) {
        std::cout << "Souris : "
                  << e->GetX()
                  << " ; "
                  << e->GetY()
                  << std::endl;
    }
);

events.AddEventCallback<NkMouseButtonPressEvent>(
    [&](NkMouseButtonPressEvent *e) {
        if (e->IsLeft()) {
            std::cout << "Clic gauche : capture active"
                      << std::endl;

            window.CaptureMouse(true);
        }
    }
);

events.AddEventCallback<NkMouseButtonReleaseEvent>(
    [&](NkMouseButtonReleaseEvent *e) {
        if (e->IsLeft()) {
            std::cout << "Clic gauche : capture liberee"
                      << std::endl;

            window.CaptureMouse(false);
        }
    }
);
```

Lorsque je construis puis j'execute le programme, je clique sur le bouton gauche et je garde le clic pendant que je deplace la souris vers l'exterieur de la fenetre.

On peut observer que les positions continuent d'etre affichees meme lorsque la souris sort de la fenetre :

```text
Clic gauche : capture active
Souris : 25 ; 332
Souris : 3 ; 335
Souris : -17 ; 342
Souris : -38 ; 347
Souris : -57 ; 355
Souris : -83 ; 365
Souris : -94 ; 370
Souris : -102 ; 373
Souris : -110 ; 378
Souris : -120 ; 380
Souris : -130 ; 382
Clic gauche : capture liberee
```

Les valeurs negatives montrent que la souris a depasse le bord de la fenetre, mais les positions continuent quand meme a etre recues grace a la capture.

### REMARQUE

Du point de vue de l'utilisateur, la difference est visible lorsque je fais un glisser avec le bouton gauche maintenu. Sans capture, lorsque je sors de la fenetre, le suivi s'arrete. Avec la capture, le suivi continue meme lorsque je sors de la fenetre.

## NB

Je n'ai pas mis toutes les sorties du programme car elles sont tres longues. J'ai seulement garde quelques lignes qui permettent de voir la difference entre le fonctionnement sans capture et avec capture.

## CONCLUSION (DIFFERENCE)

| Sans capture                            | Avec capture                             |
| --------------------------------------- | ---------------------------------------- |
| Souris suivie dans la fenetre           | Souris suivie meme hors de la fenetre    |
| Sortie de la fenetre → suivi interrompu | Sortie de la fenetre → le suivi continue |
| Pas de capture                          | Capture active pendant le clic           |
| Adapté aux mouvements simples           | Utile pour le glisser-deposer            |
