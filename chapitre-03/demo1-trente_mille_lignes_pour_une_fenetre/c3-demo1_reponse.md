# DEMO1:
Pour realiser cet exercice, je suis d'abord partie dans nkentseu et j'ai acceder a NkWindow comme ceci: ` cd D:\Projets\Rihen\Nkentseu\Kernel\Runtime\NKWindow`  

## Comptage des fichiers du module
Pour ette partie, jai compté tous les fichiers présents dans les sous-dossiers de NkWindow.
J'ai utilisé la commande suivante :
```powershell
Get-ChildItem -Recurse -File -Include *.h,*.hpp,*.cpp,*.c,*.inl |
    Measure-Object
```
J'ai fais une recherche sur l'IA pour obtenir la commande que nous devons taper afin de compter les fichier d'un dossier et ca m'a fourni la commande ci dessus

Le résultat obtenu était :
```powershell
Count             : 129
Average           : 
Sum               : 
Maximum           : 
Minimum           : 
StandardDeviation : 
Property          : 
```
Il existe donc 129 fichier dans le module NkWindow

## Comptage des lignes de code
Ensuite, Pour compter les lignes de code de ce module
J'ai utilisé la commande suivante qui me permet de ce compter les lignes dans chaque fichiers en fonction de son extension :
```powershell
Get-ChildItem -Recurse -File -Include *.h,*.hpp,*.cpp,*.c,*.inl |
    Get-Content |
    Measure-Object -Line
```
Le résultat obtenu était :
```powershell
Lines Words Characters Property
----- ----- ---------- --------
28422                  

```
Le module contient donc environ 28 422 lignes de code.

## La liste des backends de plateforme
Pour cette partie, je suis partie dans platform:
```powershell
src\NKWindow\Platform
```
J'ai compté les sous-dossiers avec :
```powershell
(Get-ChildItem .\src\NKWindow\Platform -Directory).Count
```
ceci me permet de connaitre dans combien de platforme est basee le module NkWindow

Le résultat obtenu est :
```powershell
14
```
J'ai ensuite affiché leurs noms avec :
```powershell
Get-ChildItem .\src\NKWindow\Platform -Directory |
    Select-Object Name
```
Le résultat obtenu est :
```powershell
Android
Cocoa
Common
Emscripten
HarmonyOS
Linux
Noop
UIKit
UWP
Wayland
Win32
Xbox
XCB
XLib
```
J'ai donc identifié 14 dossiers de plateformes/backends dans NKWindow.

## Choix de l'appel
### Recherche de l'appel aproprié
Pour ceci, j'ai regarder dans powershell ceci pour avoir les fonctions publiques de NkWindow.h:
```powershell
src\NKWindow\Core\NkWindow.h
```
J'ai notamment trouvé plusieurs fonctions publiques comme :
```powershell
void SetTitle(const NkString &title);
void SetSize(uint32 width, uint32 height);
void SetPosition(int32 x, int32 y);
void SetVisible(bool visible);
void Minimize();
void Maximize();
void Restore();
void SetFullscreen(bool fullscreen);
void SetDecorated(bool decorated);
void SetOpacity(float32 opacity);
void SetBackgroundColor(uint32 rgba);
void SetAlwaysOnTop(bool onTop);
void SetMousePosition(uint32 x, uint32 y);
void ShowMouse(bool show);
void CaptureMouse(bool capture);
void SetCursor(NkCursorType cursor);
```

### Choix de SetSize
J'ai choisi la fonction :
```cpp
void SetSize(uint32 width, uint32 height);
```
car elle possède plusieurs implémentations dans les dossiers Platform.
La peuve est que j'ai recherché toutes ses définitions avec :
```powershell
Get-ChildItem .\src\NKWindow -Recurse -File |
    Select-String -Pattern "void NkWindow::SetSize|NkWindow::SetSize"
```
J'ai obtenu notamment :
```powershell
Android
Cocoa
Emscripten
HarmonyOS
Noop
UIKit
UWP
Wayland
Win32
Xbox
XCB
XLib
```
Ce qui prouve que l'implementation de setsize varie en fonction des systemes.


## IMPLEMENTATION DIFFERENTES
### implémentation avec Win32  comme plateforme
J'ai affiché la partie du fichier :
```cpp
src\NKWindow\Platform\Win32\NkWin32Window.cpp
```
avec :
```powershell
Get-Content .\src\NKWindow\Platform\Win32\NkWin32Window.cpp |
    Select-Object -Skip 1095 -First 35
```
J'ai trouvé l'implémentation :
```cpp
void NkWindow::SetSize(uint32 w, uint32 h) {
    mConfig.width = w;
    mConfig.height = h;

    if (!mData.mHwnd)
        return;

    LONG fw = 0, fh = 0;

    NkWin32TailleFenetreDepuisClient(
        mData.mHwnd,
        mData.mBorderless,
        (LONG)w,
        (LONG)h,
        fw,
        fh
    );

    SetWindowPos(
        mData.mHwnd,
        nullptr,
        0,
        0,
        fw,
        fh,
        SWP_NOMOVE | SWP_NOZORDER
    );
}
```
J'ai observé que la fonction commence par enregistrer la nouvelle largeur et la nouvelle hauteur dans :
```cpp
mConfig.width = w;
mConfig.height = h;
```
Ensuite, elle vérifie si la fenêtre native existe :
```cpp
if (!mData.mHwnd)
    return;
```
La taille demandée est ensuite transformée en taille réelle de fenêtre avec :
```cpp
NkWin32TailleFenetreDepuisClient(
        mData.mHwnd,
        mData.mBorderless,
        (LONG)w,
        (LONG)h,
        fw,
        fh
    );
```
Enfin, la fonction native Windows :
```cpp
SetWindowPos(
        mData.mHwnd,
        nullptr,
        0,
        0,
        fw,
        fh,
        SWP_NOMOVE | SWP_NOZORDER
    );
```
est utilisée pour appliquer le redimensionnement.


### implementation avec Wayland comme plateforme
```cpp
src\NKWindow\Platform\Wayland\NkWaylandWindow.cpp
```
J'ai affiché le code correspondant avec :
```powershell
Get-Content .\src\NKWindow\Platform\Wayland\NkWaylandWindow.cpp |
    Select-Object -Skip 1425 -First 35
```
J'ai obtenu :
```cpp
void NkWindow::SetSize(uint32 width, uint32 height) {
mConfig.width = width;
mConfig.height = height;

if (!mData.mXdgToplevel || !mData.mSurface || !mData.mDisplay)
    return;

const int32_t w = static_cast<int32_t>(width);
const int32_t h = static_cast<int32_t>(height);

// Contraint min == max == taille souhaitée
#if NKENTSEU_HAS_LIBDECOR
if (mData.mUsingLibdecor && mData.mLibdecorFrame) {
    libdecor_frame_set_min_content_size(mData.mLibdecorFrame, w, h);
    libdecor_frame_set_max_content_size(mData.mLibdecorFrame, w, h);
} else
#endif
{
    xdg_toplevel_set_min_size(mData.mXdgToplevel, w, h);
    xdg_toplevel_set_max_size(mData.mXdgToplevel, w, h);
}
wl_surface_commit(mData.mSurface);
wl_display_flush(mData.mDisplay);

if (mConfig.resizable) {
    // Prépare le relâchement des contraintes après le configure
    mData.mPendingSizeRelease = true;
    mData.mPendingMinW = mConfig.minWidth;
    mData.mPendingMinH = mConfig.minHeight;
    mData.mPendingMaxW = (mConfig.maxWidth >= 0xFFFF) ? 0 : mConfig.maxWidth;
    mData.mPendingMaxH = (mConfig.maxHeight >= 0xFFFF) ? 0 : mConfig.maxHeight;
```
L'implémentation complète observée montre que Wayland fonctionne différemment de Win32.
La fonction commence également par enregistrer la taille :
```cpp
mConfig.width = width;
mConfig.height = height;
```
Elle vérifie ensuite que les objets natifs Wayland nécessaires existent :
```cpp
if (!mData.mXdgToplevel || !mData.mSurface || !mData.mDisplay)
    return;
```
La taille demandée est ensuite convertie en `int32_t`.
Wayland utilise ensuite des contraintes de taille. La taille minimale et la taille maximale sont temporairement fixées à la taille demandée :
```cpp
    xdg_toplevel_set_min_size(mData.mXdgToplevel, w, h);
    xdg_toplevel_set_max_size(mData.mXdgToplevel, w, h);
```
Enfin, la modification est envoyée avec :
```cpp
wl_surface_commit(mData.mSurface);
wl_display_flush(mData.mDisplay);
```
Pour avoir ce fonctionnement, j'ai demandé à l'IA ChatGPT de m'expliquer chaque portion de code.


## Comparaison des deux implémentations

### SIMILITUDES:
* Les deux plateformes utilisent la même interface publique :
```cpp
void NkWindow::SetSize(uint32 width, uint32 height);
```
Elles commencent de la meme maniere avec:
```cpp
    mConfig.width = width;
    mConfig.height = height;
```

## DIFFERENCES
* leur manière d'appliquer la taille est différente:
**Win32** travaille avec une fenêtre identifiée par :
`mData.mHwnd`
La taille client demandée est convertie en taille de fenêtre puis appliquée avec :
`SetWindowPos()`  
**Wayland** utilise :
```
mData.mXdgToplevel
mData.mSurface
mData.mDisplay
```
La taille est imposée à travers les contraintes du protocole Wayland :
```cpp
    xdg_toplevel_set_min_size(mData.mXdgToplevel, w, h);
    xdg_toplevel_set_max_size(mData.mXdgToplevel, w, h);
```
Donc taille minimale et maximale
puis la surface est validée et envoyée avec :
```cpp
wl_surface_commit(mData.mSurface);
wl_display_flush(mData.mDisplay);
```

## Ce que le module absorbe
Puisque en fonction de la plateforme utilisee, il y a une implementtion specifique d'une methode de NkWindow, cela veut dire que l'on peut avoir les memes resultats pour differents systems, alors, le module **NkWindow absorbe donc cette difference de plateforme la**

### Regroupement en trois phrases
* Similitudes: la declaration `SetSize(width, height)`
* Difference: chacune  a son implementation propre
* Ce que le module absorbe: cette difference la.