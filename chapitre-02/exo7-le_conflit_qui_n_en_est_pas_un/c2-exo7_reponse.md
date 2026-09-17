# EXERCICE 7:
Il est question ici de modifier differentes ligne dans le meme fichier et de montrer que git les assemble, pour cefait j'ai donc modifier differentes lignes de mes fichiers comme ceci:
Pour ma part, j'ai modifier les lignes 6 et 7  

**D'UNE PART, j'ai:**
```
//creation de mon deuxieme  fichier
#include <iostream>
int main()
{
    std::cout <<"bonjour a tous !"<< std::endl;

    std::cout<< "je viens de faire 2 +6" << std::endl;
    return 0;
}
```
ET puis j'ai fais les commandes suivantes:
```
git add fichier2.cpp
 git commit -m "anonce de la somme de 2 +6"
git push
```
RESULTAT:
```                                 
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 12 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 477 bytes | 477.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 1 local object.
To https://github.com/Loveline-Azemfack/Exercice1-print2
   bfcfe5b..5d0b8b0  print2 -> print2
```  
**ET D'AUTRE PART j'ai:**
```
//creation de mon deuxieme  fichier
#include <iostream>
int main()
{
    std::cout <<"bonjour a tous !"<< std::endl;
    std::cout<< "je viens de faire 2 +4" << std::endl;

    return 0;
}
```

Et puis j'ai fais les commandes suivantes:
```
git add fichier2.cpp
 git commit -m "anonce de la somme de 2 +4"

 git push  
```
RESULTAT:
```                                
Enumerating objects: 8, done.
Counting objects: 100% (8/8), done.
Delta compression using up to 12 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 479 bytes | 479.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 1 local object.
To https://github.com/Loveline-Azemfack/Exercice1-print2.git
   5d0b8b0..964a08f  print2 -> print2
```
on remarque bien que les deux modifications sont bien allees dans le repos:
## VERIFICATION;
Pour verifier cette operation j'ai cherché a voir l'ensemble des commits a travers cette commandes:
```
git log --oneline
```
Et j'obtiens bien, l'ensemble de  mes commit comme ceci:
```
git log --oneline
5d0b8b0 (HEAD -> print2, origin/print2, origin/HEAD) anonce de la somme de 2 +4
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

**En conclusion:** J'ai bien modifier les differentes lignes dans les deux fichiers, respectivement 6 et 7 et lorsque j'ai push et verifier j'ai bien obtenu l'ensemble de mes commits qui ont ete pousses. on peut alors  bien remarquer quand modifiant differentes lignes dans le meme repos par deux personnes, git n'aura aucun probleme donc ne trouvera aucun conflit.