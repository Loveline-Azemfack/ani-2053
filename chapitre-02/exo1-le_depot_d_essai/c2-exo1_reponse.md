# EXERCICE 1

## CREATION DU DEPOT VIDE
Pour ceci, j'ai utilisé la  commande suivante pour creer mon dossier et acceder:
```
MKdir Exercice1-print2
cd Exercice1-print2
```

puis j'ai fait un:
```
git init
```
Puis jai obtenu le message suivant:
```
Initialized empty Git repository in D:/Projets/Rihen/JENGA+NKENTSEU/Exercice1-print2/.git/
```

Des lors, je passe a l'etat suivante de mon enonce

## CREATION DES TROIS FICHIERS EN TROIS COMMIT
Pour cette partie, je me suis d'abord renseigné, et j'utilisait les commandes suivantes
```
"creation de mon premier fichier"|Out-File fichier1.cpp
```

je faisais ceci pour mes trois fichiers, mais je rencontrais un probleme pour la troisieme etape pour afficher l'historique de mes commmit, des lors j'ai changé de tactique, je creeais d'abord avec un git add nom_fichier et puis je faisais les commit comme pour ces trois fichiers:  
**PREMIER FICHIER**

```
git add fichier1.cpp
```
```
 git commit -m "creation de mon premier fichier"
```
Resultat:
```
[main (root-commit) e8ea254] creation de mon premier fichier
 1 file changed, 1 insertion(+)
 create mode 100644 fichier1.cpp
```

**DEUXIEME FICHIER**
```
git add fichier2.cpp
```
```
git commit -m "creation de mon deuxieme fichier"
```
Resultat:
```
[main 467d24f] creation de mon deuxieme fichier
 1 file changed, 1 insertion(+)
 create mode 100644 fichier2.cpp
```

**TROISISEME FICHIER**
```
git add fichier3.cpp
```
```
 git commit -m "creation de mon troisieme fichier"
```
Resultat:
```
[main a7fd8e0] creation de mon troisieme fichier
 1 file changed, 1 insertion(+)
 create mode 100644 fichier3.cpp
```

## AFFICHAGE DE L'HISTORIQUE EN UNE LIGNE PAR COMMIT
Pour ceci, j'ai utilise la commande:
```
git log --oneline
```
Resultat:
```
a7fd8e0 (HEAD -> main) creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```

## AFFICHAGE DU GRAPHE
Pour cela, j'ai utilise la commande:
```
git log --oneline --graph
```
Resultat:
```
* a7fd8e0 (HEAD -> main) creation de mon troisieme fichier
* 467d24f creation de mon deuxieme fichier
* e8ea254 creation de mon premier fichier
```

**EN RESUME :** Pour faire mon depot, j'ai creer mon dossier avec **mkdir Exercice1-print2** et j'ai acceder a celui ci, puis j'ai fait un **git init**. Pour ajouter mes fichiers avec des commit j'ai d'abord fait un **git add nom_fichier** pour ajouter mes fichiers et j'ai nsuite fait un **git commit -m "message"** pour chaque fichier. Pour afficher l'historique des commit par ligne j'ai fait un **git log --online** et pour le graphe j'ai fait **git log --online --graph**