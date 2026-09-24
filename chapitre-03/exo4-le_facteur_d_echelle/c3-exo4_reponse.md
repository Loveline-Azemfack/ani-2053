# EXERCICE 4:
Pour realiser cet exercice, il fallu que je me ressoursce dans le fichier NKWindow.h de  selon ce chemein d'acces: 
```
Nkentseu\Kernel\Runtime\NKWindow\src\NKWindow\Core\NkWindow.h
```
je me suis aussi servis de NkSurface.h pour pouvoir trouver comment recuperer les taille ainsi que le facteur d'echelle et j'ai ajouter cette portion de code:
```cpp
    auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();

    logger.Info(
        "Fenetre : {} x {} | Surface : {} x {} | Facteur d'echelle (DPI) : {}",
        windowSize.x,
        windowSize.y,
        surface.width,
        surface.height,
        window.GetDpiScale()
    );
```
J’ai regardé les fonctions disponibles dans NkWindow.h et la structure NkSurfaceDesc dans NkSurface.h. J’ai ensuite utilisé GetSize() pour récupérer la taille de la fenêtre, GetSurfaceDesc() pour récupérer la taille de la surface de rendu (width et height), et GetDpiScale() pour récupérer le facteur d’échelle. J’ai utilisé auto pour que C++ déduise automatiquement le type retourné par GetSize() et GetSurfaceDesc().

et ainsi quand je lance le jenga run de mon travail j'obtiens ceci:
```
[2026-09-24 16:49:34.137] [INF] [default] [main.cpp:44 in nkmain] -> Fenetre : 1280 x 1280 | Surface : 1280 x 1280 | Facteur d'echelle (DPI): 1280
```

