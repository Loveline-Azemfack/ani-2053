# EXERCICE 6:
Pour faire ceci, j'ai prefere mettre le premier travail que j'ai fait sur github en creant le repository et en liant le debut de mon travail nomme **Exercice1-print2**  je l'ai fait parce que lorsque je suis partie chercher le lien pour cloner je n'ai pas vu, je suis donc aller tester dans mon terminal un git push pour voir mais ca ne donnait pas du coup j'ai tape **git remote -v** et ca m'a afficher un autre message que **fetch** et **push** , c'est donc a ce moment que j'ai fait un git remote add origine **nom_du lien :**
```
git remote add origin https://github.com/Loveline-Azemfack/Exercice1-print2  
```

Ensuite j'ai cloner dans un autre emplacement que celui du premier pour faire le travail.

## modification de  la même ligne d'un même fichier
Pour ceci, j'ai ajouter des donnees aux lignes 5 de chacun des fichiers, comme ceci:
```
 std::cout <<"bonjour a tous !"<< std::endl;
```
d,une part et d'autre part:
```
 std::cout<<"bonjour a tous!";
```

j'ai d'abord pousser pour le premier cas avec:
```
git add fichier2.cpp
```
et j'ai commit comme ceci:
```
 git commit -m "affichons bonjour a tous"
```

Puis je suis allee add et commit le deuxieme comme ceci:
```
 git commit -m "affichons bonjour"
```
Et lorsque j'ai voulu pousser ca m'a afficher ce message;
```
To https://github.com/Loveline-Azemfack/Exercice1-print2.git
 ! [rejected]        print2 -> print2 (fetch first)
error: failed to push some refs to 'https://github.com/Loveline-Azemfack/Exercice1-print2.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

c'est donc ceci qui  represente le **refus** demandé.

## CONFLIT DEMANDE
Pour ceci, j'ai fait un **git pull --no rebase**  pour recuperer les changements sur github et ne pas rebase, et voici le resultat:

```
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 3 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 392 bytes | 23.00 KiB/s, done.
From https://github.com/Loveline-Azemfack/Exercice1-print2
   be7af1a..42a5715  print2     -> origin/print2
Auto-merging fichier2.cpp
CONFLICT (content): Merge conflict in fichier2.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

## RESOLVONS LE CONFLIT

Pour resoudre le conflit, je vais donc choisir une meilleure version, et j'ai garder celle ci
```
 std::cout <<"bonjour a tous !"<< std::endl;
```

Puis, j'ai fait un **git add** et ensuite un **git commit** 
```
 git add fichier2.cpp
git commit -m "conflit de la ligne 5 resolu"
```
puis j'ai fais le **git push**, et le push a finalement marché.
```
Enumerating objects: 8, done.
Counting objects: 100% (8/8), done.
Delta compression using up to 12 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 591 bytes | 591.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/Loveline-Azemfack/Exercice1-print2.git
   42a5715..bfcfe5b  print2 -> print2
```