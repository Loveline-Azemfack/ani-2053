# EXERCICE 3:
Ici, nous allons dfinir une yaille minimale pour notre fenetre et puis verifier jusqu'a quelle taille elle peut aller sans cette taille minimale la

## FIXATION DE LA TAILLE MINIMALE
C'est celui present dans le main.cpp de ce dossier de travail: et on remarque lorsque j'active le rendu de ma fenetre et que je redimensionne, la taille minimale de ma fentre ne part pas au dela de celle que j'ai fixé et ca ne part pa sau dela.
### Rendu de l'executable
```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  MyWindow.exe
     D:\Projets\Rihen\JENGA+NKENTSEU\FirstWindow\pop\NewWindow\Build\Bin\Debug-Windows\MyWindow\MyWindow.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

valeur demande Taille ->: 600 x 400
```
Voici la derniere la ligne de mon executable lorsque j'essaie de reduire:
```
[2026-09-25 08:09:49.114] [INF] [default] [main.cpp:43 in operator()] -> Valeur obtenue -> Taille : 600 x 600
```
et la plus petite dimension que ca m'a fourni est celle ci:
```
[2026-09-25 08:09:19.657] [INF] [default] [main.cpp:43 in operator()] -> Valeur obtenue -> Taille : 584 x 584
```
## SUPPRESSION CE CETTE TAILLE MINIMALE
L'orsque je supprime cette taille minimale, et que je reconstruit puis je **run** pour obtenir ma fenetre et que je redimensionne: La taille minimale fournit pas le systeme est:
```
[2026-09-25 08:15:55.176] [INF] [default] [main.cpp:40 in operator()] -> Valeur obtenue -> Taille : 144 x 144
```
 J'ai pu l'obtenir  travers cette portion de code.

```cpp
    events.AddEventCallback<NkWindowResizeEvent>(
        [](NkWindowResizeEvent *e) {
            logger.Info("Valeur obtenue ->Taille : {} x {}", e->GetWidth(), e->GetHeight());
        }
    );
```