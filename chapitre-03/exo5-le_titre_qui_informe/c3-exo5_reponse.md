# EXERCICE 5:
Pour réaliser cet exercice, j'ai dû effectuer un travail de recherche afin de comprendre comment mettre à jour le titre de la fenêtre au bon moment.
J'ai d'abord essayé de gérer l'affichage du titre directement, mais cela ne permettait pas de mettre à jour correctement la taille lorsque la fenêtre était redimensionnée.
J'ai donc utilisé un `AddEventCallback<NkWindowResizeEvent>` afin que le titre soit mis à jour uniquement lorsqu'un redimensionnement de la fenêtre se produit.
```cpp
bool EstModifie = false;

events.AddEventCallback<NkWindowResizeEvent>(
    [&](NkWindowResizeEvent *) {

        auto taille = window.GetSize();

        NkString title = cfg.title;

        if (EstModifie)
            title += "*";

        title += " - ";
        title += NkString::Fmtf("%u", taille.x);
        title += " x ";
        title += NkString::Fmtf("%u", taille.y);

        window.SetTitle(title);
    }
);
```

Au départ, je n'avais pas introduit cette gestion dans le `ResizeEvent`. Le titre pouvait alors indiquer l'état de modification, mais la taille affichée dans le titre ne se mettait pas correctement à jour lors du redimensionnement.

L'utilisation de `AddEventCallback<NkWindowResizeEvent>` permet donc de faire la mise à jour au bon moment, c'est-à-dire lorsqu'un événement de redimensionnement est détecté, et non à chaque image.
