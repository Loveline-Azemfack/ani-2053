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
Ce qui n'est pas normal, j'ai donc change le precednt code releve ci dessus par ceci:
```cpp
    auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();

    logger.Info("Window X : {}", windowSize.x);
    logger.Info("Window Y : {}", windowSize.y);

    logger.Info("Surface width : {}", surface.width);
    logger.Info("Surface height : {}", surface.height);

    logger.Info("DPI Scale : {}", window.GetDpiScale());

    auto width = windowSize.x;
    auto height = windowSize.y;
    auto surfaceWidth = surface.width;
    auto surfaceHeight = surface.height;
    auto dpi = window.GetDpiScale();

    std::cout<<"Fenetre : "<< width << " X " <<height <<" | Surface : "<< surface.width << " X " <<surface.height<< " | Facteur d'echelle (DPI) : "<< window.GetDpiScale() << std::endl;
    while (running && window.IsOpen()) {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }
```
Qui me permettra d'abord de verifier et enfin de gerer l'affichage exacte des valeurs. Et voici ce que j'obtiens de mon executable:
```

[2026-09-25 09:26:25.411] [INF] [default] [main.cpp:44 in nkmain] -> Window X : 1280
[2026-09-25 09:26:25.411] [INF] [default] [main.cpp:45 in nkmain] -> Window Y : 720
[2026-09-25 09:26:25.411] [INF] [default] [main.cpp:47 in nkmain] -> Surface width : 1280
[2026-09-25 09:26:25.412] [INF] [default] [main.cpp:48 in nkmain] -> Surface height : 720
[2026-09-25 09:26:25.412] [INF] [default] [main.cpp:50 in nkmain] -> DPI Scale : 1
Fenetre : 1280 X 720 | Surface : 1280 X 720 | Facteur d'echelle (DPI) : 1
```
On remarque alors que sur l'echelle j'obtiens **1** je vais donc changer le reglage d'echelle.  
j'etais d'abord a 100% maintenat je suis passee a 125% et quan je recompile et je lance l'executable, jobtiens ceci:
```
[2026-09-25 09:31:28.208] [INF] [default] [main.cpp:44 in nkmain] -> Window X : 1278
[2026-09-25 09:31:28.208] [INF] [default] [main.cpp:45 in nkmain] -> Window Y : 712
[2026-09-25 09:31:28.209] [INF] [default] [main.cpp:47 in nkmain] -> Surface width : 1278
[2026-09-25 09:31:28.209] [INF] [default] [main.cpp:48 in nkmain] -> Surface height : 712
[2026-09-25 09:31:28.209] [INF] [default] [main.cpp:50 in nkmain] -> DPI Scale : 1.25
Fenetre : 1278 X 712 | Surface : 1278 X 712 | Facteur d'echelle (DPI) : 1.25
```
Voici donc l'ensemble du travail en gros