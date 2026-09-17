# EXERCICE 8:
PROVOQUONS PUIS DEFAISONS LES DIFFERENTES SITUATIONS CI  APRES:

## MODIFICATION NON VOULUE
Pour ceci, j'ai juste ajouter un std::cout dans mon fichier comme ceci, **std::cout<<"ajout d'une modification par erreur" << std::endl;** puis j'ai verifier que la modification est bien presente, avec **git status** et voici le resultat:
```
On branch print2
Your branch is up to date with 'origin/print2'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier2.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

On remarque bien que ca nous propose soit d'ajouter la modification dans le repository avec le **git add** soit de revenir en arriere avant la modification avec le **git restore** et comme l'exercice renvoie a une modification non voulue, on va faire le **git restore**, et quand je l'ai fait, je vais encore taper un **git status** pour voir l'etat du fichier actuel et j'obtiens:  
```
On branch print2
Your branch is up to date with 'origin/print2'.

nothing to commit, working tree clean
```
**Donc la modification non voulue a ete resolu**

## UN ADD DE TROP
Ici, il va falloir modifier un fichier, puis ajouter ce fichier puis le retirer. Avant tout il faut noter que faire le git add d'un  fichier c'est le placer dans la zone de staging qui est la mise en attente avant de push.  
Alors j'ai ajouter cette ligne dans mon fichier:
```
    std::cout<<"ajout d'une modification pour pousser apres";
```
et puis j'ai fait un **git add** et pour verifier mon avancer dans le travai, j'ai fais :
```
git status
```
et voici mon resultat:
```
On branch print2
Your branch is up to date with 'origin/print2'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   fichier2.cpp

```
Ici on remarque bien que ma modification a bien ete add et que c'est bien dans le staging  
Maintenant, essayons d'enlever le add. Pour cela, je fais un **git restore --staged fichier2.cpp** puisque je suis entrain de faire mes modification dans le fichier2.cpp. Et juste apres, j'ai fais un **git status:**  
Et voici le resultat
```
On branch print2
Your branch is up to date with 'origin/print2'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier2.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

On remarque que le message qui s'affichait en vert dans le premier **git status** s'affiche maintenant en rouge dans ce deuxieme **git status** et on remarque que le git restore --staged qu'on avait precedemment fait n'a pas supprimer notre modification mais a plutot enlever de la zone de staging.  
D'où la situation d'un add de trop  a ete resolu.

## UN COMMIT DE TROP
Pour ceci, j'ai gardé ma precedente modification, puisque je devais toujours faire une modification, pour ce fait, je commence avec un **git add fichier2.cpp** j'ai fait le commit suivant : **git commit -m "declaration d'un ajout pour modification"** et puis j'ai fait un **git log --oneline** pour voir ci mon ouveau commit etait bien present dans mon historique de commit et j'obtiens:
```
bd952b8 (HEAD -> print2) declaration d'un ajout pour modification
5d0b8b0 (origin/print2, origin/HEAD) anonce de la somme de 2 +6
40bfbae anonce de la somme de 2 +6
bfcfe5b conflit de la ligne 5 resolu
42a5715 affichons bonjour a tous
3a55bbb affichons bonjour
be7af1a premier main vide
79b5cd1 ajout de iostream
4eb1ced premiere modification
71ef3d6 (main) modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```

et on retrouve bien en tete mon commit, ce qui prouve que c'est bien dans l'historique mais puisque je ne veux plus qu'il soit la, je vais le retirer avec:
```
git reset HEAD~1
```
Resultat:
```
Unstaged changes after reset:
M       fichier2.cpp

```
et lorsque je refais mon **git log --oneline**, j'obtiens bien ceci:
```
5d0b8b0 (HEAD -> print2, origin/print2, origin/HEAD) anonce de la somme de 2 +6
40bfbae anonce de la somme de 2 +6
bfcfe5b conflit de la ligne 5 resolu
42a5715 affichons bonjour a tous
3a55bbb affichons bonjour
be7af1a premier main vide
79b5cd1 ajout de iostream
4eb1ced premiere modification
71ef3d6 (main) modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```

La on remarque bien que le commit que je venais de faire n'y est plus

## UN COMMIT POUSSE QU'IL FAUT ANNULER
Pour cette fois je vais toujours travailler avec le meme commit mais a la difference que je vais le push cette fois, et voici la preuve de mon push: 
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 402 bytes | 402.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Loveline-Azemfack/Exercice1-print2.git
   964a08f..c204f9a  print2 -> print2
```

Mais il faut noter que mon premier push avait toujours tenu compte de cette affaire de conflit. C'est lorsque j'ai copier la meme ligne pour aller mettre dans le deuxieme clone que ca a poussé.  
On va donc verifier sin notre commit est bien present avc git log --oneline:  
```
c204f9a (HEAD -> print2, origin/print2, origin/HEAD) anonce de la somme de 2 +6
964a08f anonce de la somme de 2 +6
8735c18 anonce de la somme 2 + 4
5d0b8b0 anonce de la somme de 2 +6
40bfbae anonce de la somme de 2 +6
bfcfe5b conflit de la ligne 5 resolu
42a5715 affichons bonjour a tous
3a55bbb affichons bonjour
be7af1a premier main vide
79b5cd1 ajout de iostream
4eb1ced premiere modification
71ef3d6 modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```
Notons que j'ai fais expres d'avoir mis un meme commit que l'ancien pour avoir une raison pour le supprimer.  
Maintenant nous allons enlever ce commit pousser avec un **git revert  mon_identifiant** comme ceci:  
```
git revert c204f9a
```
Resultat:
```
Revert "anonce de la somme de 2 +6"

This reverts commit c204f9a2da8ffbf39d4cc71cacb412efb8dc327b.

# Please enter the commit message for your changes. Lines starting
# with '#' will be ignored, and an empty message aborts the commit.
#
# On branch print2
# Your branch is up to date with 'origin/print2'.
#
# Changes to be committed:
#       modified:   fichier2.cpp
```
Puis j'ai cliquer sur **Esc :wq** pour sortir et voici le resultat obtenu:
```
[print2 c10bdfc] Revert "anonce de la somme de 2 +6"
 1 file changed, 1 deletion(-)
```

Donc le revert a bien fonctionné, puis j'ai fait un **git log --oneline**
ET voici le resultat:
```
c10bdfc (HEAD -> print2) Revert "anonce de la somme de 2 +6"
c204f9a (origin/print2, origin/HEAD) anonce de la somme de 2 +6
964a08f anonce de la somme de 2 +6
8735c18 anonce de la somme 2 + 4
5d0b8b0 anonce de la somme de 2 +6
40bfbae anonce de la somme de 2 +6
bfcfe5b conflit de la ligne 5 resolu
42a5715 affichons bonjour a tous
3a55bbb affichons bonjour
be7af1a premier main vide
79b5cd1 ajout de iostream
4eb1ced premiere modification
71ef3d6 modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```

On remarque que le git revert a bien changé  mon commit, maintenant on va **push** sur github pour ajouter ce nouvel historique.  
Donc le probleme de cette partie a bien ete resolu

## UN TRAVAIL EN COURS QU'IL FAUT METTRE DE COTE
Pour ceci, nous allons travailler avec le **git stash**
Avant tout on va modifier une ligne de notre travail, et moi pour ce fait, j'ai ajouter un commentaire a la ligne 11 de mon ficher: fichier2.cpp et des lors, je fais un **git status** pour remarquer ma modification:
```
Your branch is up to date with 'origin/print2'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier2.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
On remarque que ma modification est bien presente.  
maintenat pour mettre mon travail en cours en pause  je fais un **git stash** et j'obtiens: 
```
Saved working directory and index state WIP on print2: c10bdfc Revert "anonce de la somme de 2 +6"
```
Maintenant pour verifier que notre **stash** a effectivement marché je vais refaire un git status pour voir l'etat de mon travail:
```
On branch print2
Your branch is up to date with 'origin/print2'.

nothing to commit, working tree clean
```

Ou encore on peut regarder dans la list du stash avec **git stash list**, et j'obtiens:
```
stash@{0}: WIP on print2: c10bdfc Revert "anonce de la somme de 2 +6"
```
On voit bien qu'il a bien ete stoque dans cette liste selon l'ID du commit qui a ete fournit dans le message du **stash**: 
Passons maintenant a la resolution, pour cela, on va faire un **git stah pop** pour reprendre le travail recent en cours:
```
On branch print2
Your branch is up to date with 'origin/print2'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier2.cpp

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (3da93bc5e73999852d9a975a2d60570b2478761c)
```

Pour etre rassuree que cela a vraiment fonctionné, nous allons faire un **git status** pour voir l'etat du travail actuel, et on obtient bien: 
```
On branch print2
Your branch is up to date with 'origin/print2'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier2.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
Donc le travail en cours qu'il faut mettre de cote, a bien ete resolu.


## UN COMMIT PERDU A RETROUVER PAR LE REFLOG

Ici, je vais continuer avec la modification de la tache precedente, et je vais jsute add et commit. Puis je vais essayer de le supprimer.  
Le commit deja fait et qui est celui ci: **git commit -m "ajout du commentaire pour le travail en cours"**
je vais voir si il est present dans la liste des commit avec **git log --oneline** et voici le resultat:
```
89dc22f (HEAD -> print2) ajout du commentaire pour le travail en cours
c10bdfc (origin/print2, origin/HEAD) Revert "anonce de la somme de 2 +6"
c204f9a anonce de la somme de 2 +6
964a08f anonce de la somme de 2 +6
8735c18 anonce de la somme 2 + 4
5d0b8b0 anonce de la somme de 2 +6
40bfbae anonce de la somme de 2 +6
bfcfe5b conflit de la ligne 5 resolu
42a5715 affichons bonjour a tous
3a55bbb affichons bonjour
be7af1a premier main vide
79b5cd1 ajout de iostream
4eb1ced premiere modification
71ef3d6 modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```
Maintenant on va  essayer de le supprimer en jouant juste avec la tete de commit, et je vais donc utiliser le **git reset --hard c10bdfc** ici, je vais juste dire a la tete de commit de prendre celui precedent, a ce niveau ci tous les commit qui existent apres ca n'y seront plus, on va donc verifier avec notre **git log --oneline** et voici ce qu'on obtient:
```
c10bdfc (HEAD -> print2, origin/print2, origin/HEAD) Revert "anonce de la somme de 2 +6"
c204f9a anonce de la somme de 2 +6
964a08f anonce de la somme de 2 +6
8735c18 anonce de la somme 2 + 4
5d0b8b0 anonce de la somme de 2 +6
40bfbae anonce de la somme de 2 +6
bfcfe5b conflit de la ligne 5 resolu
42a5715 affichons bonjour a tous
3a55bbb affichons bonjour
be7af1a premier main vide
79b5cd1 ajout de iostream
4eb1ced premiere modification
71ef3d6 modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
PS D:\Projets\Rihen\Exercice1-print2-clone2> git reflog              
c10bdfc (HEAD -> print2, origin/print2, origin/HEAD) HEAD@{0}: reset: moving to c10bdfc
89dc22f HEAD@{1}: reset: moving to 89dc22f
89dc22f HEAD@{2}: commit: ajout du commentaire pour le travail en cours
c10bdfc (HEAD -> print2, origin/print2, origin/HEAD) HEAD@{3}: reset: moving to HEAD
c10bdfc (HEAD -> print2, origin/print2, origin/HEAD) HEAD@{4}: revert: Revert "anonce de la somme de 2 +6"
c204f9a HEAD@{5}: reset: moving to HEAD
c204f9a HEAD@{6}: commit: anonce de la somme de 2 +6
964a08f HEAD@{7}: commit (merge): anonce de la somme de 2 +6
8735c18 HEAD@{8}: commit: anonce de la somme 2 + 4
bfcfe5b HEAD@{9}: commit (merge): conflit de la ligne 5 resolu
3a55bbb HEAD@{10}: commit: affichons bonjour
be7af1a HEAD@{11}: clone: from https://github.com/Loveline-Azemfack/Exercice1-print2.git
```

sachant que le resultat de notre **git reset --hard c10bdfc** est:
```
HEAD is now at c10bdfc Revert "anonce de la somme de 2 +6"

```

On remarque bien que notre commit a disparu, alors on va essayer de le recuperer en utilisant **git reflog** qui va afficher les actions recentes de HEAD et on va tout simplement deplacer notre head toujours en utilisant le git reset --hard mais cette fois on va mettre l'identifiant du commit qui a ete supprimé, toutefois, il faut retenir le message qui a ete entre dans le commit c'est pour ca qu'il faut tujours bien expliciter les commmit; alors, voici donc les differentes commandes ainsi que les resultat:

```
git reflog :
```
Resultat:
```             
c10bdfc (HEAD -> print2, origin/print2, origin/HEAD) HEAD@{0}: reset: moving to c10bdfc
89dc22f HEAD@{1}: reset: moving to 89dc22f
89dc22f HEAD@{2}: commit: ajout du commentaire pour le travail en cours
c10bdfc (HEAD -> print2, origin/print2, origin/HEAD) HEAD@{3}: reset: moving to HEAD
c10bdfc (HEAD -> print2, origin/print2, origin/HEAD) HEAD@{4}: revert: Revert "anonce de la somme de 2 +6"
c204f9a HEAD@{5}: reset: moving to HEAD
c204f9a HEAD@{6}: commit: anonce de la somme de 2 +6
964a08f HEAD@{7}: commit (merge): anonce de la somme de 2 +6
8735c18 HEAD@{8}: commit: anonce de la somme 2 + 4
bfcfe5b HEAD@{9}: commit (merge): conflit de la ligne 5 resolu
3a55bbb HEAD@{10}: commit: affichons bonjour
be7af1a HEAD@{11}: clone: from https://github.com/Loveline-Azemfack/Exercice1-print2.git
```

Puis, 
```
git reset --hard 89dc22f
```
Resultat:
```
HEAD is now at 89dc22f ajout du commentaire pour le travail en cours
```
Et enfin on verifie maintenant l'etat de l'historique pour voir si effectivement le commit est revenu:
 git log --oneline 
```      
89dc22f (HEAD -> print2) ajout du commentaire pour le travail en cours
c10bdfc (origin/print2, origin/HEAD) Revert "anonce de la somme de 2 +6"
c204f9a anonce de la somme de 2 +6
964a08f anonce de la somme de 2 +6
8735c18 anonce de la somme 2 + 4
5d0b8b0 anonce de la somme de 2 +6
40bfbae anonce de la somme de 2 +6
bfcfe5b conflit de la ligne 5 resolu
42a5715 affichons bonjour a tous
3a55bbb affichons bonjour
be7af1a premier main vide
79b5cd1 ajout de iostream
4eb1ced premiere modification
71ef3d6 modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```

Et on voit bien qu'il est la donc tache resolue!

## En conclusion:
- Lorsqu'on modifie un fichier, la commande pour la revenir c'est **git restore**;
- Lorsqu'on fait un add de trop, la commande pour l'enlever est **git restore --staged nom_fichier** pour enlever de l'historique des staging
- Lorsqu'on fait un commit de trop, la commande pour retirer de l'historique est : **git reset HEAD~1**
- Pour annuler un commit deja pousser on utilise le **git revert Identifiant_du_commit**
- Pour mettre un travaile en cours en pause, on utilise un **git stash** et pour le reprendre un **git stash pop**
- Pour retrouver un commit perdu on utilise le **git reflog** et on joue sur la position du head en fonction de l'identifiant

Il faut avouer que ce travail mettait vraiment en exergue la comprehension de l'introduction et beaucoup de recherche et surtout une belle mise en forme du commit comme il a ete evoquer dans le cours