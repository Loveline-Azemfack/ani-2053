# EXERCICE2:
Pour cet exercice, dans le quel il fallait faire un git status apres modification, add et commit, voici l'ensemble de mes differentes taches:

## GIT STATUS  apres modification
Ici, j'ai modifier mon fichier1.cpp en mettant juste les commentaires dans la premiere ligne de mon fichier qui est celle ci:
```
//creation de mon premier fichier
```
Voici le resultat de mon git status:
```
On branch main
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier1.cpp
```

## GIT STATUS APRES ADD
Puis, ici j'ai fait un add 
```
git add fichier1.cpp
```
et puis un git status et voici le resultat:
```
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   fichier1.cpp

```

## GIT STATUT APRES COMMIT
Pour cette partie, voici mon commit:
```
 git commit -m "modification du fichier1"
```

Resultat du **git commit**:
```
[main 98767fd] modification du fichier1
 1 file changed, 1 insertion(+), 1 deletion(-)
```

Resultat du **git status**:
```
On branch main
nothing to commit, working tree clean
```

## CE QUI CHANGE
Ici, on remarque quand on modifie le fichier1.cpp et qu'on fait un git status, ca nous propose de faire un git add pour mettre a jour ce qui sera commit, ou de faire un git restore, et ca m'affiche directement le message qui prouve que mon fichier a ete modifier **modified:   fichier1.cpp** mais ca affiche en rouge car la modification n'a pas encore ete mise sur le repository en ligne. Puis quand je fais ensuite un git add fichier1.cpp ca affiche le meme message mais en vert cette fois et ca propose toujours un  git restore. Et par la fin quand je fais un git commit ca affiche le message qe j'ai mis comme identifiant pour ma modification. Donc ce processus permet de remarque l'evolution de son travail a chaque tache precise