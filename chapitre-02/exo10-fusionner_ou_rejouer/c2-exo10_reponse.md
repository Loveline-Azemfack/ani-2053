# EXERCICE 10:
Pour cet exercice, nous alllons d'abord creer deux branches:,
## INTEGRATION PAR FUSION
 mais bon pour faire cela je vais utiliser le **git switch -c integration-merge-et-rebase** pour creer et acceder a ma premiere nouvelle branche qui appartIendra  a merge qui renvoie a la fusion **(ne vous centrez pas trop sur le nom de la brnche)** , puis je vais faire une  modification dans cette branche et verifier qu'elle ext bien active, alors je vais ajouter a la ligne 11 et 10 de ma nouvelle branche en enlever la lettre **d** a la fin du  commentaire de la ligne 11 et en ajoutant un nouveau commentaire pour laligne de 12 et puis verifier avec un **git diff**  
Resultat:  
```
diff --git a/fichier2.cpp b/fichier2.cpp
index 8fccda5..c5a4cc2 100644
--- a/fichier2.cpp
+++ b/fichier2.cpp
@@ -8,4 +8,5 @@ int main()
     return 0;
 }
 
-//travail en cours qu'il faut mettre de coted
\ No newline at end of file
+//travail en cours qu'il faut mettre de cote
+//deuxieme modification pour rebase
\ No newline at end of file
```
Ensuite je vais add le fichier et faire un commit pour cette nouvelle :
```
git add fichier2.cpp
 git commit -m "modification dans le cas de rebase"

```
Resultat:
```
[integration-rebase a3604d8] modification dans le cas de rebase
 1 file changed, 2 insertions(+), 1 deletion(-)
```

Maintenant nous allons repartir a notre branche prncipale qui est print2:
```
git switch print2 
```
 creeons encore une nouvelle  branche mais cette fois elle appartiendra a rebase uniquement:  
```
git switch -c integration-rebase            
```
ET ensiute notre **git diff :**
```
diff --git a/fichier2.cpp b/fichier2.cpp
index 8fccda5..c5a4cc2 100644
--- a/fichier2.cpp
+++ b/fichier2.cpp
@@ -8,4 +8,5 @@ int main()
     return 0;
 }
 
-//travail en cours qu'il faut mettre de coted
\ No newline at end of file
+//travail en cours qu'il faut mettre de cote
+//deuxieme modification pour rebase
\ No newline at end of file
```

Nous refaisons le meme travail que dans la premiere branche, donc on fait le **git add** et on **commit** comme ceci :

```
git add fichier2.cpp
 git commit -m "modification dans le cas de rebase"

```

Resultat:

```
[integration-rebase a3604d8] modification dans le cas de rebase
 1 file changed, 2 insertions(+), 1 deletion(-)
```

###  GRAPHE
Maintenant avant de rejouer avec le **rebase**, voyons dans l'ensemble  le graph des modification avec:
```
git log --oneline --graph --all --decorate       
```
Resultat:

```
* a3604d8 (HEAD -> integration-rebase) modification dans le cas de rebase
| * 31611ed (integration-merge-et-rebase) modification dans le cas de merge
|/  
* 89dc22f (print2) ajout du commentaire pour le travail en cours
* c10bdfc (origin/print2, origin/HEAD) Revert "anonce de la somme de 2 +6"
| * 4b1fa6d (refs/stash) WIP on print2: c204f9a anonce de la somme de 2 +6
|/| 
| * c8ffaf0 index on print2: c204f9a anonce de la somme de 2 +6
|/  
* c204f9a anonce de la somme de 2 +6
*   964a08f anonce de la somme de 2 +6
|\  
| *   5d0b8b0 anonce de la somme de 2 +6
| |\  
| * | 40bfbae anonce de la somme de 2 +6
* | | 8735c18 anonce de la somme 2 + 4
| |/  
|/|   
* | bfcfe5b conflit de la ligne 5 resolu
|\| 
| * 42a5715 affichons bonjour a tous
* | 3a55bbb affichons bonjour
|/  
* be7af1a premier main vide
* 79b5cd1 ajout de iostream
* 4eb1ced premiere modification
* 71ef3d6 modif
* 98767fd modification du fichier1
* a7fd8e0 creation de mon troisieme fichier
* 467d24f creation de mon deuxieme fichier
* e8ea254 creation de mon premier fichier
```

Concentrons nous sur cette partie ci, observons la tres bien:
```
* a3604d8 (HEAD -> integration-rebase) modification dans le cas de rebase
| * 31611ed (integration-merge-et-rebase) modification dans le cas de merge
|/  
* 89dc22f (print2) ajout du commentaire pour le travail en cours
```
On remarque que nos branches viennent bien evidemment de ce commit **89dc22f** qui appartient au **print2**.  

## INTEGRATION EN REJOUANT
Faisons donc un rebase:  
Mais puisque c'est pour la branche **integration-merge-et-rebase**, on va la faire la:
```
git rebase integration-merge-et-rebase
```
Lorsque je fais  ceci, j'ai rencontre un conflit entre mes deux depots, du ccoup pour resoudre cela, j'ai copier mon premier depot et  coller dans le deuxieme puis j'ai fait un git add pour signaler que le conflit a ete resolu, et j'ai fait **git rebase --continue** pour que ca continue de jouer et voici le message :
```
[detached HEAD c56dfde] modification dans le cas de rebase
 1 file changed, 1 insertion(+), 1 deletion(-)
Successfully rebased and updated refs/heads/integration-rebase.
```
### GRAPHE 

Maintenant faisons un graph apres le rebase :
```
git log --oneline --graph --all --decorate
```

Resultat:
```
* c56dfde (HEAD -> integration-rebase) modification dans le cas de rebase
* 31611ed (integration-merge-et-rebase) modification dans le cas de merge
* 89dc22f (print2) ajout du commentaire pour le travail en cours
* c10bdfc (origin/print2, origin/HEAD) Revert "anonce de la somme de 2 +6"
| * 4b1fa6d (refs/stash) WIP on print2: c204f9a anonce de la somme de 2 +6
|/| 
| * c8ffaf0 index on print2: c204f9a anonce de la somme de 2 +6
|/  
* c204f9a anonce de la somme de 2 +6
*   964a08f anonce de la somme de 2 +6
|\  
| *   5d0b8b0 anonce de la somme de 2 +6
| |\  
| * | 40bfbae anonce de la somme de 2 +6
* | | 8735c18 anonce de la somme 2 + 4
| |/  
|/|   
* | bfcfe5b conflit de la ligne 5 resolu
|\| 
| * 42a5715 affichons bonjour a tous
* | 3a55bbb affichons bonjour
|/  
* be7af1a premier main vide
* 79b5cd1 ajout de iostream
* 4eb1ced premiere modification
* 71ef3d6 modif
* 98767fd modification du fichier1
* a7fd8e0 creation de mon troisieme fichier
* 467d24f creation de mon deuxieme fichier
* e8ea254 creation de mon premier fichier
```

Voici le graphe obteniue apres avoir fait un rebase. Concentrons nous sur cette partie:
```
* c56dfde (HEAD -> integration-rebase) modification dans le cas de rebase
* 31611ed (integration-merge-et-rebase) modification dans le cas de merge
* 89dc22f (print2) ajout du commentaire pour le travail en cours
```

## EXPLICATION DE LA DIFFERENCE OBTENU SUR LES GRAPHES

Lorsqu'on regarde les deux graphes suivants:
```
* a3604d8 (HEAD -> integration-rebase) modification dans le cas de rebase
| * 31611ed (integration-merge-et-rebase) modification dans le cas de merge
|/  
* 89dc22f (print2) ajout du commentaire pour le travail en cours
```

Et:
```
* c56dfde (HEAD -> integration-rebase) modification dans le cas de rebase
* 31611ed (integration-merge-et-rebase) modification dans le cas de merge
* 89dc22f (print2) ajout du commentaire pour le travail en cours
```

- La premiere remarque intervient d'abord sur l'organisation, le premier graphe avait une organisation qui converge en celle pyramidale et le second est plutot lineair et plus facile a cmprendre
- Ensuite on remarque un changement des identifiants de commit car dans le premier on a ceci **a3604d8 (HEAD -> integration-rebase) modification dans le cas de rebase** et dans le second **c56dfde (HEAD -> integration-rebase) modification dans le cas de rebase**   
On peut donc dire la que lorsque l'integration par fusion reunit les fistoriques de  chacune des branches creer, a un graphe ramifié et dont certains commits peuvent dependre d'un commit parent en principe, il cree un comit de fusion tant dis que l'integration en rejouant a d'abord un graphe lineaire, il rejoue les commit sur une nouvelle branche 

## PREFERENCE
Moi je prefere celui en rejouant car il est lineair, facile a lire et a comprendre.