# DEMO2:

## PROVOCATION DU CONFLIT:

Pour faire ceci, je suis juste entree dans mes deux clones et j'ai modifié mes deux fichiers3.cpp comme ceci:

****PREMIER FICHIER:****

```cpp
//creation de mon troisieme  fichier
#include <iostream>
int main(){
    int a, b;
    a =3;
    b =5;
    std::cout << 3 +5<< std::endl;
    return 0;
}
```

****DEUXIEME FICHIER:****

```cpp
//creation de mon troisieme  fichier
#include <iostream>
int main(){
    int a, b;
    a =3;
    b =5;
    std::cout << "la somme de " << a << " et "<< b << " est  : " <<3 +5<< std::endl;
    return 0;
}
```

Maintenant essayons de pousser ca sur leur depot:

****PREMIER FICHIER:****

```
PS D:\Projets\Rihen\JENGA+NKENTSEU\Exercice1-print2> git add fichier3.cpp
PS D:\Projets\Rihen\JENGA+NKENTSEU\Exercice1-print2> git commit -m "chapitre-02: creer un conflit (clone1)"
[print2 885a2e6] chapitre-02: creer un conflit (clone1)
PS D:\Projets\Rihen\JENGA+NKENTSEU\Exercice1-print2> git push
Enumerating objects: 14, done.
Counting objects: 100% (13/13), done.
Delta compression using up to 12 threads
Compressing objects: 100% (8/8), done.
Writing objects: 100% (8/8), 1.01 KiB | 517.00 KiB/s, done.
Total 8 (delta 3), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (3/3), completed with 1 local object.
To https://github.com/Loveline-Azemfack/Exercice1-print2
   c10bdfc..885a2e6  print2 -> print2
```

****DEUXIEME FICHIER:****

```
PS D:\Projets\Rihen\Exercice1-print2-clone2> git add fichier3.cpp
PS D:\Projets\Rihen\Exercice1-print2-clone2> git commit -m "chapitre-02: creer un conflit (clone2)"
[print2 788488c] chapitre-02: creer un conflit (clone2)
 1 file changed, 11 insertions(+), 1 deletion(-)
PS D:\Projets\Rihen\Exercice1-print2-clone2> git push
To https://github.com/Loveline-Azemfack/Exercice1-print2.git
 ! [rejected]        print2 -> print2 (fetch first)
error: failed to push some refs to 'https://github.com/Loveline-Azemfack/Exercice1-print2.git'
hint: Updates were rejected because the remote contains work that you do not
have locally. This is usually caused by another repository pushing to
the same ref. If you want to integrate the remote changes, use
'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

On remarque que le `git push` a détecté que le dépôt distant contenait des modifications absentes de mon deuxième clone. Le push est donc refusé. Je dois maintenant recupérer et integrer les modifications du dépôt distant afin que Git puisse comparer les deux versions et détecter les éventuels conflits.

Nous allons donc résoudre ce conflit en ces différentes étapes:

## Lecture des marqueurs

Pour cela nous allons d'abord faire un git status dans notre deuxieme clone pour voir ce qui s'affiche:

```
On branch print2
Your branch is ahead of 'origin/print2' by 2 commits.
  (use "git push" to publish your local commits)
nothing to commit, working tree clean
```

Oups, on m'affiche travail propre, ce qui ne devrait pas être le cas. Mon git push venait pourtant d'être refusé parce que le dépôt distant contenait une modification que mon clone ne connaissait pas encore.

Cela s'explique par le fait que origin/print2 correspond à l'information que mon clone possède sur la branche distante. Pour mettre à jour cette information, il faut utiliser :
```
git fetch origin
```
Qui récupère les nouvelles informations du dépôt distant sans modifier directement mes fichiers. 

Je vais donc verifier mes commits pour voir ce qu'il y a:

```
git log --oneline -8
```

Regardons les 8 dernieres lignes:

```
* 788488c (HEAD -> print2) chapitre-02: creer un conflit (clone2)
| * c8e470c (origin/integration-rebase, integration-rebase) chapitre-02: creer un conflit (clone2)
| * 3590358 suppression du fichier de 10Mo dans le cadre de l'exercice 11
| * 440c410 ajout d'un fichier de 10Mo dans le cadre de l'exercice 11
| * c56dfde modification dans le cas de rebase
| * 31611ed (integration-merge-et-rebase) modification dans le cas de merge
|/
* 89dc22f ajout du commentaire pour le travail en cours
| * 885a2e6 (origin/print2, origin/HEAD) chapitre-02: creer un conflit (clone1)
| |\
| |/
|/
```

Ah, on voit que je travaille sur une version distante puisque j'avais deja cree deux autres branches pour les exercices precedents. Pas grave, on va demander à Git de fusionner mon depot distant avec ma branche actuelle avec:

```
git merge origin/print2
```

Resultat:

```
Auto-merging fichier2.cpp
CONFLICT (content): Merge conflict in fichier2.cpp
Auto-merging fichier3.cpp
CONFLICT (content): Merge conflict in fichier3.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

On voit bien que cette fois Git a localisé les conflits et a affiché les marqueurs suivants dans mon deuxieme clone:

```text
<<<<<<< HEAD
    std::cout << "la somme de " << a << " et "<< b << " est  : " <<3 +5<< std::endl;
=======
    std::cout << 3 +5<< std::endl;
>>>>>>> origin/print2
```

D'apres ces marqueurs, voici ma version que je veux mettre sur GitHub: **std::cout << "la somme de " << a << " et "<< b << " est  : " <<3 +5<< std::endl;**

Ce qui crée une confusion, car une autre version a deja ete ecrite dans le depot distant et indique ceci:

```
std::cout << 3 +5<< std::endl;
```

Il faudrait donc que je choisisse quelle ligne garder:

## décision

Pour ceci, je prefere choisir le message le plus explicite qui est celui-ci:

```text
std::cout << "la somme de " << a << " et "<< b << " est  : " <<3 +5<< std::endl;
```

Je le choisis tout d'abord parce que le message permet de savoir sur quoi on travaille concretement. Il est tres explicite et adapte pour plusieurs executables, tandis que le premier affichera simplement une somme dont on ne saurait pas d'ou elle sort. Une personne tierce venant de l'exterieur et n'ayant pas travaille avec nous ne comprendra pas l'objectif de l'affichage d'une valeur quelconque, tandis qu'avec ce message, on sait directement de quoi il s'agit.

## reconstruction

Maintenant que j'ai choisi, je vais reconstruire mon fichier fichier3.cpp. Je supprime donc les marqueurs du conflit et je garde uniquement la version que j'ai choisie.

Le fichier fichier3.cpp reconstruit devient alors :
```
//creation de mon troisieme fichier

#include <iostream>

int main(){

    int a, b;
    a =3;
    b =5;

    std::cout << "la somme de " << a << " et "<< b << " est  : " <<3 +5<< std::endl;

    return 0;
}
```
On voit maintenant que les marqueurs <<<<<<<, ======= et >>>>>>> ont disparu et qu'il ne reste que la version finale que j'ai choisie.

Ensuite, je fais :
```
git add fichier3.cpp
```
Puis je vérifie l'état du travail avec :
```
git status
```
resultat:

```
On branch print2
Your branch and 'origin/print2' have diverged,
and have 2 and 3 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)
You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)
Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   fichier2.cpp
no changes added to commit (use "git add" and/or "git commit -a")
```

Puisque j'etais entrain de travailler dans la branche print2, lorsque j'ai fait un **git merge** de toute la branche, cela a localisé tout mon travail du coup le **git status** considère aussi tout mon travail et cela signale un autre conflit dans le fichier2.cpp. On va donc aller voir de quoi il s'agit:

```
<<<<<<< HEAD
//travail en cours qu'il faut mettre de coted
=======
//travail en cours qu'il faut mettre de cote
//deuxieme modification pour rebase
>>>>>>> origin/print2
```

Les erreurs sont donc liees a mes precedents commentaires et d'apres ce qu'on montre c'est un conflit lié à la faute d'orthographe, donc je vais prendre le (incoming change), donc ceci:

```
//travail en cours qu'il faut mettre de cote
//deuxieme modification pour rebase
```

Maintenant allons faire notre **git add .** et **git status** et voici ce qui s'affiche:

```
On branch print2
Your branch and 'origin/print2' have diverged,
and have 2 and 3 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)
All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)
Changes to be committed:
        modified:   fichier2.cpp
```

Maintenant puisque j'ai deja signale que j'ai faites mes modifications, je vais commit et revoir encore l'etat de mon trvail comme ceci:
```
PS D:\Projets\Rihen\Exercice1-print2-clone2> git commit -m "chapitre-02: creer un conflit (clone2), conflit resolu"
[print2 a464635] chapitre-02: creer un conflit (clone2), conflit resolu
PS D:\Projets\Rihen\Exercice1-print2-clone2> git status
On branch print2
Your branch is ahead of 'origin/print2' by 3 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
PS D:\Projets\Rihen\Exercice1-print2-clone2> 
```

## Validation 
Allons maintenant verifier que notre commit a bien reussi avec :
```
git log --oneline --graph --all
```
Resultat:
```
*   a464635 (HEAD -> print2) chapitre-02: creer un conflit (clone2), conflit resolu
|\  
| *   885a2e6 (origin/print2, origin/HEAD) chapitre-02: creer un conflit (clone1)
| |\  
| * | 18f5950 chapitre-02: creer un conflit (clone1)
| * | 3e8532b declaration d'un ajout pour modification
* | | 788488c chapitre-02: creer un conflit (clone2)
| | | * c8e470c (origin/integration-rebase, integration-rebase) chapitre-02: creer un conflit (clone2)
| | | * 3590358 suppression du fichier de 10Mo dans le cadre de l'exercice 11
| | | * 440c410 ajout d'un fichier de 10Mo dans le cadre de l'exercice 11
| | | * c56dfde modification dans le cas de rebase
| | | * 31611ed (integration-merge-et-rebase) modification dans le cas de merge
| |_|/  
|/| |   
* | | 89dc22f ajout du commentaire pour le travail en cours
| |/  
|/|   
* | c10bdfc Revert "anonce de la somme de 2 +6"
| | * 4b1fa6d (refs/stash) WIP on print2: c204f9a anonce de la somme de 2 +6
| |/| 
|/| | 
| | * c8ffaf0 index on print2: c204f9a anonce de la somme de 2 +6
| |/  
|/|   
* | c204f9a anonce de la somme de 2 +6
* | 964a08f anonce de la somme de 2 +6
|\| 
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
Apres ceci, on remarque bien entete qu'on a notre commit,
Maintenant on va pousser le travail avec `git push`  
Resultat:
```
Enumerating objects: 12, done.
Counting objects: 100% (12/12), done.
Delta compression using up to 12 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 691 bytes | 691.00 KiB/s, done.
Total 6 (delta 3), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (3/3), completed with 3 local objects.
To https://github.com/Loveline-Azemfack/Exercice1-print2.git
   885a2e6..a464635  print2 -> print2
```
On remarque bien que notre push a reuss, plus de conflit localisé, donc notre push a ete valide.