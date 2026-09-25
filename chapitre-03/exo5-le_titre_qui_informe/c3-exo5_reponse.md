# EXERCICE 5:

Pour réaliser cet exercice, j'ai dû effectuer un travail de recherche afin de comprendre comment mettre à jour le titre de la fenêtre au bon moment.

J'ai d'abord essayé de gérer l'affichage du titre directement, mais cela ne permettait pas de mettre à jour correctement la taille lorsque la fenêtre était redimensionnée.

J'ai donc utilisé un `AddEventCallback<NkWindowResizeEvent>` afin que le titre soit mis à jour lorsqu'un redimensionnement de la fenêtre se produit.

```cpp
bool EstModifie = false;

auto MettreAJourTitre = [&]() {
    auto taille = window.GetSize();

    NkString title = cfg.title;

    if (EstModifie)
        title += "*";

    title += " - ";
    title += NkString::Fmtf("%u", taille.x);
    title += " x ";
    title += NkString::Fmtf("%u", taille.y);

    window.SetTitle(title);
};

MettreAJourTitre();

events.AddEventCallback<NkWindowResizeEvent>(
    [&](NkWindowResizeEvent *) {
        EstModifie = true;
        MettreAJourTitre();
    }
);
```

Au départ, `EstModifie` est à `false`, donc le titre ne contient pas d'astérisque.

Lorsque je redimensionne la fenêtre, l'événement `NkWindowResizeEvent` est déclenché. Je considère alors ce redimensionnement comme une modification et je mets `EstModifie` à `true`. Le titre est ensuite mis à jour avec un astérisque et la nouvelle taille de la fenêtre.

Par exemple, au lancement, le titre peut être:

`Ma fenetre - 1280 x 720`

Après un redimensionnement, il devient par exemple:

`Ma fenetre* - 1000 x 600`

L'utilisation de `AddEventCallback<NkWindowResizeEvent>` permet donc de faire la mise à jour au bon moment, c'est-à-dire lorsqu'un événement de redimensionnement est détecté, et non à chaque image.


## PREUVE DU FONCTIONNEMENT
<video controls width="700">
  <source src="exo5-print3.mp4" type="video/mp4">
</video>