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
Mon programme fait au total **37** lignes de codes et l'espace entre les lignes  y est compris. si on ne compte pas l'espace entre lignes, alors jai **31** lignes de code.

## RETROUVONS CHACUNE DANS LE CHAPITRE

D'après le programme fourni dans le chapitre, j'ai retrouvé plusieurs éléments dans mon programme.

* `nkmain` : il permet de fournir le point d'entrée du programme avec le système Nkentseu.

* `NkWindowConfig cfg` : il permet de créer la configuration de la fenêtre.

* `cfg.title`, `cfg.width` et `cfg.height` : ils permettent de définir respectivement le titre, la largeur et la hauteur de la fenêtre.

* `NkWindow window(cfg)` : il permet de créer la fenêtre à partir de la configuration définie.

* `window.IsOpen()` : il permet de vérifier si la fenêtre est ouverte.

* `while (running && window.IsOpen())` : dans mon programme, cette boucle permet de maintenir la fenêtre ouverte tout en traitant les événements.

* `events.PollEvents()` : il permet de traiter les événements de la fenêtre.

* `return 0` : il permet de terminer normalement le programme.

Mon programme est donc basé sur le programme minimal présenté dans le chapitre, mais j'ai ajouté la gestion des événements et la fermeture de la fenêtre.


## DIFFICULTES
Il faut noter que j'ai rencontree une difficultee pour reconstruire la fenetre avec le plus petit programme fourni par le chapitre car ca ne  reconnaissait pas les modules window ou windowcnfig. Pour cela, j'ai parcourue le tutoriel **Fenetre-01** de nkentseu et j'a vu un **using namespace nkentseu;** et c'est quand je l'ai introduit que j'ai pu **build** mon programme et enfin voir ma fenetre