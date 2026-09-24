# EXERCICE1:
Ici, il est question d'ecrire un plus petit programme qui ouvre une fenetre, la garde ouverte et se termine proprement:
Alors c'est le petit programme observe dans main.cpp dont les parties de l'enonce sont les suivantes:  
## Partie du programme qui ouvre la fenetre
```cpp
    NkWindow window(cfg); 
```

cette partie montre bien que la fenetre doit s'ouvrir a ce niveau la condition qui suit apres c'est pour le cas contraire

## Partie du programme qui la garde ouvert

```cpp
    while (window.IsOpen()){}
```
celle ci c'est la boucle qui devra la garder ouverte c'est plus tard qu'on remplira les evenements

## Se termine proprement 
Ici c'est lorsque window.IsOpen egale false alors la fenetre se ferme et return 0 termine le programme.

## COMPTE DES LIGNES
Mon programme fait au total **19** lignes de codes et l'espace entre les lignes  y est compris. si on ne compte pas l'espace entre lignes, alors jai **20** lignes de code.

## RETROUVONS CHACUNE DANS LE CHAPITRE
D'apres ce programme fourni par le chapitre: 
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title  = "Ma fenetre";
    cfg.width  = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    while (window.IsOpen()) { /* les evenements arrivent ici */ }
    return 0;
}
```

Les lignes retrouvees dans  ce chapitre sont:

* nkmain : pour que le module puisse  fournir le point d'entre natif de chaque plateforme;

*      NkWindowconfig: c'est pour fournir les identites de la fenetre (la taille, titre), ce que l'utilisateur peut redimensionner et l'apparence du rendu

* IsOpen : d'apres le chapitre, elle sert de verification car l'ouverture de la fenetre peut echouer 

*     NkWindow window(cfg): la fenetre est cree selon les configurations entrees.

*  while (window.IsOpen()){}: c'est pour garder la fenetre ouvert, le chapitre indique qu'on pourra y mettre les evenements apres

* return 0: pour terminer le programe;


## DIFFICULTES
Il faut noter que j'ai rencontree une difficultee pour reconstruire la fenetre avec le plus petit programme fourni par le chapitre car ca ne  reconnaissait pas les modules window ou windowcnfig. Pour cela, j'ai parcourue le tutoriel **fenetre-01** de nkentseu et j'a vu un **namespace nkentseu** et c'est quand je l'ai introduit que j'ai pu **build** mon programme et enfin voir ma fenetre