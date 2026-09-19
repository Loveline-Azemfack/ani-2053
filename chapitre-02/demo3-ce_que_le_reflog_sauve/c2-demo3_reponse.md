# DEMO 3:
Pour faire cet exercice, je vais partir dans mon fichier3.cpp de mon espace de travail et je vais faire une modification dessus en ajoutant ceci

```cpp
std::cout << "Bonjour depuis mon travail !" << std::endl;
std::cout << "Cette modification va etre perdue !" << std::endl;
return 0;
```

Je vérifie ensuite la modification avec :

```
git diff
```
maintenant je vais ajuter ce fichier et faire un commit dessus

```
git add fichier3.cpp
```
Qui va mettre on fichier dasn la zone de **adding** zone de preparation

Ensuite je crée le commit :

```
git commit -m "testons le git reset hard"
```

Le commit créé est :

```
49097ff testons le git reset hard
```

## Destruction volontaire du travail

Je fais maintenant un `reset --hard` vers le commit precedent et j'obtiens:

```
git reset --hard 3590358
```

Cette commande déplace `HEAD` vers le commit `3590358` et remet également les fichiers du projet dans l'état de ce commit.

On remarque donc qu'on ne voit plus l''ancien commit sur le test
Le résultat obtenu est :

```
HEAD is now at 3590358 suppression du fichier de 10Mo dans le cadre de l'exercice 11
```

## CONSTATONS LA PERTE 
Je vérifie l'état du dépôt avec :

```
git status
```
Le dépôt est propre.
Je vérifie ensuite les 3 derniers commits avec :
```
git log --oneline -3
```
Le commit **49097ff** n'apparaît plus dans l'historique actuel, le HEAD pointe maintenant sur **3590358** .

## RETROUVONS LE TRAVAIL AVEC REFLOG

Pour cela, j'utilise :

```
git reflog
```

Cette commande permet de voir les déplacements précédents de `HEAD`, même lorsqu'un commit n'apparaît plus dans l'historique normal de la branche.
Resultat :
```
3590358 (HEAD -> integration-rebase) HEAD@{0}: reset: moving to 3590358
49097ff HEAD@{1}: reset: moving to HEAD
49097ff HEAD@{2}: commit: testond le git reset hard
3590358 (HEAD -> integration-rebase) HEAD@{3}: commit: suppression du fichier de 10Mo dans le cadre de l'exercice 11
440c410 HEAD@{4}: commit: ajout d'un fichier de 10Mo dans le cadre de l'exercice 11
c56dfde HEAD@{5}: rebase (finish): returning to refs/heads/integration-rebase
c56dfde HEAD@{6}: rebase (continue): modification dans le cas de rebase
31611ed (integration-merge-et-rebase) HEAD@{7}: rebase (start): checkout integration-merge-et-rebase
a3604d8 HEAD@{8}: commit: modification dans le cas de rebase
89dc22f (print2) HEAD@{9}: checkout: moving from print2 to integration-rebase
89dc22f (print2) HEAD@{10}: checkout: moving from integration-merge-et-rebase to print2
31611ed (integration-merge-et-rebase) HEAD@{11}: commit: modification dans le cas de merge
89dc22f (print2) HEAD@{12}: checkout: moving from print2 to integration-merge-et-rebase
89dc22f (print2) HEAD@{13}: reset: moving to 89dc22f
c10bdfc (origin/print2, origin/HEAD) HEAD@{14}: reset: moving to c10bdfc
89dc22f (print2) HEAD@{15}: reset: moving to 89dc22f
89dc22f (print2) HEAD@{16}: commit: ajout du commentaire pour le travail en cours
c10bdfc (origin/print2, origin/HEAD) HEAD@{17}: reset: moving to HEAD
c10bdfc (origin/print2, origin/HEAD) HEAD@{18}: revert: Revert "anonce 
de la somme de 2 +6"
c204f9a HEAD@{19}: reset: moving to HEAD
c204f9a HEAD@{20}: commit: anonce de la somme de 2 +6
964a08f HEAD@{21}: commit (merge): anonce de la somme de 2 +6
8735c18 HEAD@{22}: commit: anonce de la somme 2 + 4
bfcfe5b HEAD@{23}: commit (merge): conflit de la ligne 5 resolu
3a55bbb HEAD@{24}: commit: affichons bonjour
be7af1a HEAD@{25}: clone: from https://github.com/Loveline-Azemfack/Exe
rcice1-print2.git
```
Remarque: 
```
49097ff HEAD@{2}: commit: testons le git reset hard
```

Le commit `49097ff` correspond donc au travail que j'avais créé avant le `reset --hard`.


Je peux maintenant vérifier le contenu du commit retrouvé avec :

```
git show 49097ff
```


On peut donc retrouver le travail grâce au `reflog`, même après avoir fait un `reset --hard`.
