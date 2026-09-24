# EXERCICE 3:
Ici, nous allons dfinir une yaille minimale pour notre fenetre et puis verifier jusqu'a quelle taille elle peut aller sans cette taille minimale la

## FIXATION DE LA TAILLE MINIMALE
C'est celui present dans le main.cpp de ce dossier de travail: et on remarque lorsque j'active le rendu de ma fenetre et que je redimensionne, la taille minimale de ma fentre est nette celle que j'ai fixé et ca ne part pa sau dela.

## SUPPRESSION CE CETTE TAILLE MINIMALE
L   orsque je supprime cette taille minimale, et que je reconstruit puis je **run** pour obtenir ma fenetre et que je redimensionne: La taille minimale fournit pas le systeme est:
**Taille : 144 x 144** J'ai pu l'obtenir  travers cette portion de code

```cpp
    events.AddEventCallback<NkWindowResizeEvent>(
        [](NkWindowResizeEvent *e) {
            logger.Info("Taille : {} x {}", e->GetWidth(), e->GetHeight());
        }
    );
```