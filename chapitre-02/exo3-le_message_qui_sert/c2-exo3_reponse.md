# EXERCICE 3:
Pour cette exercice il faudra, d'abord que j'essaie de lister les commit de **Nkentseu** mais puisque ca a trop de commit, je vais lister les 10 derniers avec cette commande:
```
 git log --oneline -n 10
```
Resultat:
```
a175373d (HEAD -> papa, main) ajout de MonEssai
6fb634fc NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle
860e9d7f Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
c1c815ff CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)
addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)
43285010 (origin/fix/nktraits-portable) NkTraits : demander a la primitive si elle existe, pas au compilateur qui il est
0d50a971 NKCode 0.1.0-beta.6 : version bumpee avant publication
7c3e84a0 Merge remote-tracking branch 'origin/main'
4c7d66b5 Distribution : refuser de livrer un exe dont une DLL importee manque
ad0779cb NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur
```
Puis, il faudra choisir trois commit que je vais devoir expliquer, sur ce, je prendrai:
```
addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)
43285010 (origin/fix/nktraits-portable) NkTraits : demander a la primitive si elle existe, pas au compilateur qui il est
0d50a971 NKCode 0.1.0-beta.6 : version bumpee avant publication
```
## Choix 1 du commit: addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)

### Ce qu'il fait 
Ce commit montre qu'il y a eu un changement de la version de NKcode beta.8 qui passe a beta.11

### Pourquoi
De ce message on peut dire qu'il y a eu un changement parce que l'ancienne version ne rejoignait pas le man(#86)

### Porte-t-il un seul sujet?
Oui, ce commit n'a qu'un seul sujet, celui du changement de la version
## Choix 2 du commit : 43285010 (origin/fix/nktraits-portable) NkTraits : demander a la primitive si elle existe, pas au compilateur qui il est

### Ce qu'il fait :
Ce commit porte sur la  modification de NKTraits qui consiste plutot a demander a la primitive si elle existe que de demander au compilateur qui il est.


### Pourquoi
C'est pour pouvoir bien verifier l'existence d'une primitive que d'aller verifier une identiter du compilateur, c'est pour eviter la confusion

### Porte-t-il un seul sujet?
Oui, il porte exactement sur un sujet, celui de l'existence de la primitive

## Choix 3 du commit : 0d50a971 NKCode 0.1.0-beta.6 : version bumpee avant publication
### Ce qu'il fait :
Il augmente la version de NKCode a 0.1.0-beta.6. avant la publication

### Pourquoi
Dans le message du commit on voit **version bumpee avant publication** donc on fait cela, car une publication etait prevue.

### Porte-t-il un seul sujet?
Oui et ce sujet est le changement de version.

## celui qui vous paraît le plus faible
Lorsqu'on demande celui qui est plus faible, je suppose que c'est celui qui est moins precis, du coup celui qui me parait le plus faible ici est : **0d50a971 NKCode 0.1.0-beta.6 : version bumpee avant publication**
 IL me parait le plus faible parce que tout le monde ne pourrait pas facilement comprendre l'expression **bumpee**, de plus, il est difficile de ressortir le **pourquoi** donc ce serait peut etre mieux de mettre **0d50a971 NKCode 0.1.0-beta.6 :  changement de version (nom de l'ancienne version)  avant de faire une publication** tout en notant qu'il doit etre court et expressif.
