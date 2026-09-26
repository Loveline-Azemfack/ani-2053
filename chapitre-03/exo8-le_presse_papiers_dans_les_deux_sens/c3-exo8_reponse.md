# EXERCICE 8:
Pour faire cette exercice,  l fallu que je passe une journee complete de recherche, car non seulement je ne savais pas comment communiquer avec la presse papier de mon PC mais je ne savais pas aussi comment manipuler les images via cela. Des lors j'ai commencer a fouiller nkentseu pour voir s'il avait des fonctions pour m'aider:

## programme qui lit le texte du presse-papiers, le met en majuscules, et le remet
Pour cette partie, j'ai fait un **Ctrl + Shift + F** dans Nkentseu et j'ai recherché clipboard. Cela m'a ramenée vers **NkWindow**, où j'ai trouvé les fonctions permettant de communiquer avec le presse-papiers.

J'ai notamment trouvé les fonctions :
`SetClipboardText()`
`GetClipboardText()`

J'ai donc commencé par tester la récupération du texte présent dans le presse-papiers avec ceci:
```cpp
NkString texte = window.GetClipboardText();
SetClipboardText(texte)
```
Et ca communiquait bien avec ma pressse papier.

Ensuite, j'ai transformé le texte récupéré en majuscules avant de le remettre dans le presse-papiers. avec cette portion de code:
```cpp
NkString texte = window.GetClipboardText();

    std::cout << "Texte copie dans le presse-papiers : "
            << texte.CStr() << std::endl;

    NkString texteMajuscule = NkStringView(texte).ToUpper();
```
Pour retrouver `NkStringView(texte).ToUpper()` il fallut que j'entre dans le fichier **NkStringView.h** pour retrouver la fonction ToUpper() dans nkentseu.

Comme preuve du resultat, j'ai voulu gerer l'affichage de cela dans mon terminal avec ceci:
### PREUVE:
```cpp
    std::cout << "Texte transforme en majuscules : "
            << texteMajuscule.CStr() << std::endl;

    window.SetClipboardText(texteMajuscule);
```

Et lorsque j'essayais de construire et d'executer l'ensemble cela s'effectuait parfaitement:

#### PREUVE DE CONSTRUCTION
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
│  ✓ Build Successful                                                             Time: 2.93s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.93s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```

#### PREUVE D'EXECUTION
Prenons le cas de **hello world** que nous copions avec un **ctrl+c**

```powershwell

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

fenetre cree avec succes!!Texte copie dans le presse-papiers : hello world
Texte transforme en majuscules : HELLO WORLD

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (2.73s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
Et lorsqu'on vient refaire notr **ctrl + v** on obtient ceci: **HELLO WORLD**

Alors on remarque bien qu'on a pu bien trouver cela.

## avec une image : lisez-la, inversez ses couleurs, remettez-la

Pour cette partie j'ai rencontre enormement de difficulte, car pour etre sur de mon evolution j'ai d'abord voulu afficher un message dans la mesure ou on retrouve une image dans la presse-papier comme ceci:
```cpp
  if (window.HasClipboardImage()) {
        std::cout << "Une image est detectee dans le presse-papiers." << std::endl;
    } else {
        std::cout << "Aucune image detectee dans le presse-papiers." << std::endl;
    }

```

Mais lorsque je partais copier une image, le terminal m'affichait encore et encore **Aucune image detectee dans le presse-papiers.** du coup j'ai fais mes reherches sur l'IA pour savoir comment y parvenir ca m'a proposer de faire
```cpp
 if (OpenClipboard(nullptr)) {

        UINT format = 0;

        while ((format = EnumClipboardFormats(format)) != 0) {
            if (format == CF_TEXT)
                std::cout << "CF_TEXT" << std::endl;
            else if (format == CF_BITMAP)
                std::cout << "CF_BITMAP" << std::endl;
            else if (format == CF_DIB)
                std::cout << "CF_DIB" << std::endl;
            else if (format == CF_DIBV5)
                std::cout << "CF_DIBV5" << std::endl;
            else if (format == CF_UNICODETEXT)
                std::cout << "CF_UNICODETEXT" << std::endl;
            else
                std::cout << "Autre format : " << format << std::endl;
        }

        CloseClipboard();
    }
```
pour determiner si cetait le logiciel avec lequel j'ouvre les images qui etait un probleme puisqu'on a d'abord regarder une fonction de format de clipboard et on a remarque que c'etait restreint en quelques types orr mes images sont **png** et **jpg** et ca ne faisaient pas partir de ces types la, alors on a dnc trouver que c'etait mieux de dessiner une image nous meme et de renvoyer son inverse avec ceci:
```cpp
image.width = 2;
    image.height = 2;
    image.pixels.Resize(16);

    uint8 *p = image.pixels.Data();

    // Pixel 1 : rouge
    p[0] = 255;
    p[1] = 0;
    p[2] = 0;
    p[3] = 255;

    // Pixel 2 : vert
    p[4] = 0;
    p[5] = 255;
    p[6] = 0;
    p[7] = 255;

    // Pixel 3 : bleu
    p[8] = 0;
    p[9] = 0;
    p[10] = 255;
    p[11] = 255;

    // Pixel 4 : blanc
    p[12] = 255;
    p[13] = 255;
    p[14] = 255;
    p[15] = 255;

    if (image.IsValid()) {
        std::cout << "Image creee avec succes." << std::endl;
    } else {
        std::cout << "Image invalide." << std::endl;
    }

    if (window.SetClipboardImage(image)) {
        std::cout << "Image placee dans le presse-papiers." << std::endl;
    } else {
        std::cout << "Impossible de placer l'image dans le presse-papiers." << std::endl;
    }

    if (OpenClipboard(nullptr)) {

        UINT format = 0;

        while ((format = EnumClipboardFormats(format)) != 0) {
            if (format == CF_TEXT)
                std::cout << "CF_TEXT" << std::endl;
            else if (format == CF_BITMAP)
                std::cout << "CF_BITMAP" << std::endl;
            else if (format == CF_DIB)
                std::cout << "CF_DIB" << std::endl;
            else if (format == CF_DIBV5)
                std::cout << "CF_DIBV5" << std::endl;
            else if (format == CF_UNICODETEXT)
                std::cout << "CF_UNICODETEXT" << std::endl;
            else
                std::cout << "Autre format : " << format << std::endl;
        }

        CloseClipboard();
    }

    if (window.HasClipboardImage()) {
        std::cout << "Une image est detectee dans le presse-papiers." << std::endl;
    } else {
        std::cout << "Aucune image detectee dans le presse-papiers." << std::endl;
    }

    if (window.GetClipboardImage(image)) {
        std::cout << "Image lue avec succes." << std::endl;
        std::cout << "Largeur : " << image.width << std::endl;
        std::cout << "Hauteur : " << image.height << std::endl;
    } else {
        std::cout << "Impossible de lire l'image." << std::endl;
    }
    NkClipboardImage imageLue;

    if (window.GetClipboardImage(imageLue)) {
        std::cout << "Image recuperee pour traitement." << std::endl;
    } else {
        std::cout << "Impossible de recuperer l'image." << std::endl;
    }

    uint8 *pixels = imageLue.pixels.Data();

    for (usize i = 0; i < imageLue.pixels.Size(); i += 4) {
        pixels[i]     = 255 - pixels[i];     // Rouge
        pixels[i + 1] = 255 - pixels[i + 1]; // Vert
        pixels[i + 2] = 255 - pixels[i + 2]; // Bleu
        // pixels[i + 3] = Alpha : on ne le modifie pas
    }

    std::cout << "Couleurs inversees." << std::endl;

    if (window.SetClipboardImage(imageLue)) {
        std::cout << "Image inversee remise dans le presse-papiers." << std::endl;
    } else {
        std::cout << "Impossible de remettre l'image dans le presse-papiers." << std::endl;
    }
```
ce qui marchait bien:
### PREUVE DE CONSTRUCTION ET D'EXECUTION:
#### CONSTRUCTION

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
│  ✓ Build Successful                                                             Time: 2.89s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.89s
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

fenetre cree avec succes!!Texte copie dans le presse-papiers : main
Texte transforme en majuscules : MAIN
Image creee avec succes.
Image placee dans le presse-papiers.
CF_DIBV5
CF_DIB
CF_BITMAP
Une image est detectee dans le presse-papiers.
Image lue avec succes.
Largeur : 2
Hauteur : 2
Image recuperee pour traitement.
Couleurs inversees.
Image inversee remise dans le presse-papiers.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (2.56s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

Cependant il faudrait une application ayant les formats fourni pour l'afficher.

Voici donc l'ensemble du travail.