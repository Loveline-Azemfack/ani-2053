# EXERCICE 4:
Pour celui ci, il m'a ete demander de mettre des modifications dans le fichier etd'en faire deux commit separes, pour dela, j'ai modifier mon fichier1 en ceci:  
**Ancienne version:**
```
//creation de mon premier fichier

#include <iostream>

int main()
{
    int a = 05;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;
    //modification2

    std::cout << a + b << std::endl;

    return 0;
}
```
**Nouvelle version:**
```
//creation de mon premier fichier

#include <iostream>

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;
    int f = 60;

    std::cout << a + b << std::endl;

    return 0;
}
```

##  en faire deux commits séparés avec git add -p

Pour ceci j'ai utiliser la commande git add -p  comme recommandee et voici l'enseble de mes operations:
```
diff --git a/fichier1.cpp b/fichier1.cpp
index aac865f..8027efd 100644
--- a/fichier1.cpp
+++ b/fichier1.cpp
@@ -4,12 +4,12 @@
 
 int main()
 {
-    int a = 10;
+    int a = 05;
     int b = 20;
     int c = 30;
     int d = 40;
     int e = 50;
-    int f = 60;
+    //modification2
 
     std::cout << a + b << std::endl;
 
(1/1) Stage this hunk [y,n,q,a,d,s,e,p,P,?]? s
Split into 2 hunks.
@@ -4,8 +4,8 @@
 
 int main()
 {
-    int a = 10;
+    int a = 05;
     int b = 20;
     int c = 30;
     int d = 40;
     int e = 50;
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y
@@ -8,8 +8,8 @@
     int b = 20;
     int c = 30;
     int d = 40;
     int e = 50;
-    int f = 60;
+    //modification2
 
     std::cout << a + b << std::endl;
 
(2/2) Stage this hunk [y,n,q,a,d,K,J,g,/,e,p,P,?]? n
```
**ici, j'ai d'abord choisit  s pour separer (split) et ensuite n pour ne ps ajouter au bloc du prochain commit**
## HISTORIQUE
je l'ai fait avec la ligne
```
git log --oneline
```

Resultat:
```
71ef3d6 (HEAD -> main) modif
98767fd modification du fichier1
a7fd8e0 creation de mon troisieme fichier
467d24f creation de mon deuxieme fichier
e8ea254 creation de mon premier fichier
```
Puis, pour voir que mes commit etaient bien separes, j'ai utiliser un **git show** je l'es fait pour mes deux nouvels identifiants comme ceci:

```
git show 71ef3d6 
```
Resultat:
```
commit 71ef3d67cd3393f9d97834b6443bd9dd1abba6dc (HEAD -> main)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Wed Sep 16 20:25:12 2026 +0100

    modif

diff --git a/fichier1.cpp b/fichier1.cpp
index 10b2d3b..aac865f 100644
--- a/fichier1.cpp
+++ b/fichier1.cpp
@@ -1 +1,17 @@
 //creation de mon premier fichier
+
+#include <iostream>
+
+int main()
+{
+    int a = 10;
+    int b = 20;
+    int c = 30;
+    int d = 40;
+    int e = 50;
+    int f = 60;
+
+    std::cout << a + b << std::endl;
+
+    return 0;
+}
\ No newline at end of file
```
De meme, j'ai fais ceci:
```
git show 98767fd
```
Resultat:
```
commit 98767fd5c3d383dd70677fea5f5b901bce1dfb96
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Wed Sep 16 16:55:01 2026 +0100

    modification du fichier1

diff --git a/fichier1.cpp b/fichier1.cpp
index 02e50d0..10b2d3b 100644
--- a/fichier1.cpp
+++ b/fichier1.cpp
@@ -1 +1 @@
-creation de mon premier fichier
+//creation de mon premier fichier
```

Et tout ce ensemble prouve qu'ils ont bien ete separe


# REPONSE AUX OBSERVATIONS:  

Suite aux observations de mon encadrant, je vais refaire l'exercice dans une nouvelle branche afin de montrer correctement que les deux modifications sont bien separées dans deux commits differents.
Cette fois, je vais aussi verifier directement le contenu des deux commits avec leurs nouveaux identifiants.  

##  VERIFICATION DU DEPOT  

Je commence par verifier l'etat de mon depot avec: 
```
git status
```
Resultat:
```
On branch test-rebase-rejouer
nothing to commit, working tree clean
```
On remarque que mon depot est propre, donc je peux commencer une nouvelle tentative sans avoir de modification en cours.

## CREATION D'UNE NOUVELLE BRANCHE
Pour ne pas modifier mes anciens travaux, je cree une nouvelle branche avec:
```
git switch -c exercice4-add-p
```

Cette commande me permet donc de creer une nouvelle branche appelee `exercice4-add-p` et d'y acceder directement.

##  CREATION DES DEUX MODIFICATIONS
Je modifie ensuite mon `fichier1.cpp`.
Je fais d'abord une premiere modification en remplacant:

```
int a = 10;
```
par:
```
int a = 05;
```
Puis je fais une deuxieme modification en remplacant:
```
int f = 60;
```
par:
```
//modification2
```

Les deux modifications sont donc dans le meme fichier mais elles ne concernent pas la meme partie.

##  VERIFICATION AVEC GIT DIFF

Je verifie maintenant mes modifications avec:

```text
git diff
```

Resultat:

```text
diff --git a/fichier1.cpp b/fichier1.cpp
index aac865f..8027efd 100644
--- a/fichier1.cpp
+++ b/fichier1.cpp
@@ -4,12 +4,12 @@

 int main()
 {
-    int a = 10;
+    int a = 05;
     int b = 20;
     int c = 30;
     int d = 40;
     int e = 50;
-    int f = 60;
+    //modification2

     std::cout << a + b << std::endl;
```

On voit donc bien les deux modifications que je veux separer.

## UTILISATION DE GIT ADD -P

Je vais maintenant utiliser:
```
git add -p
```
Git me presente d'abord les deux modifications dans un meme bloc. Je choisis:

```
s
```
pour separer le bloc en deux.
Git me presente alors deux hunks.
Pour le premier hunk, correspondant a la modification de `a`, je choisis:

```
y
```
pour l'ajouter au premier commit.
Pour le deuxieme hunk, correspondant a la modification de `f`, je choisis:
```
n
```
pour ne pas l'ajouter au premier commit.
J'ai donc utilisé:
```
s
y
n
```

Ici, `s` permet de separer les modifications, `y` permet d'ajouter la premiere modification et `n` permet de laisser la deuxieme modification de cote.

## VERIFICATION AVANT LE PREMIER COMMIT

Je verifie ensuite l'etat du depot avec:
```
git status
```
Resultat:

```
On branch exercice4-add-p
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   fichier1.cpp

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier1.cpp
```

On remarque donc qu'une modification est staged et qu'une autre ne l'est pas encore.
Cela montre que `git add -p` a bien separe mes deux modifications avant meme de faire le premier commit.

##  PREMIER COMMIT

Je fais maintenant mon premier commit avec:

```
git commit -m "modifications de la valeur de a"
```
Resultat:
```text
[exercice4-add-p d40e9b1] modifications de la valeur de a
 1 file changed, 1 insertion(+), 1 deletion(-)
```
Ce premier commit contient donc seulement la modification de la valeur de `a`.

##  PREPARATION DU DEUXIEME COMMIT

La deuxieme modification est toujours presente dans mon fichier mais elle n'a pas encore ete commitée.
Je l'ajoute avec:
```
git add fichier1.cpp
```
Je verifie ensuite avec:
```
git status
```
Resultat:
```
On branch exercice4-add-p
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   fichier1.cpp
```

La deuxieme modification est maintenant prete pour le deuxieme commit.

## DEUXIEME COMMIT
Je fais alors mon deuxieme commit avec:
```
git commit -m "ajout du commentaire a la place de la valeur de f"
```
Resultat:
```
[exercice4-add-p 8570b02] ajout du commentaire a la place de la valeur de f
 1 file changed, 1 insertion(+), 1 deletion(-)
```
J'ai maintenant deux commits differents qui correspondent aux deux modifications.

## VERIFICATION DE L'HISTORIQUE

Je verifie maintenant mon historique avec:

```
git log --oneline
```

Resultat:

```
8570b02 (HEAD -> exercice4-add-p) ajout du commentaire a la place de la valeur de f
d40e9b1 modifications de la valeur de a
d49209f (test-rebase-rejouer) modification pour rejouer
a2e0563 (test-merge) Merge branch 'test-rebase' into test-merge
5c585fb (test-rebase) modification pour le rebase tentative2
cc39a56 (test-merge) modification pour le merge tentative2
a464635 (origin/print2, origin/HEAD, print2) chapitre-02: creer un conflit (clone2), conflit resolu
788488c chapitre-02: creer un conflit (clone2)
885a2e6 chapitre-02: creer un conflit (clone1)
18f5950 chapitre-02: creer un conflit (clone1)
89dc22f ajout du commentaire pour le travail en cours
```

On voit maintenant les deux nouveaux commits en haut de l'historique:

```
8570b02 ajout du commentaire a la place de la valeur de f
d40e9b1 modifications de la valeur de a
```

## VERIFICATION DU PREMIER COMMIT

Pour verifier que le premier commit contient seulement son sujet, je fais:
```text
git show d40e9b1
```
Resultat:
```text
diff --git a/fichier1.cpp b/fichier1.cpp
index aac865f..056033a 100644
--- a/fichier1.cpp
+++ b/fichier1.cpp
@@ -4,7 +4,7 @@

 int main()
 {
-    int a = 10;
+    int a = 05;
     int b = 20;
     int c = 30;
     int d = 40;
```

On remarque que ce commit contient uniquement la modification de la valeur de `a`.

## VERIFICATION DU DEUXIEME COMMIT

Je verifie ensuite le deuxieme commit avec:

```text
git show 8570b02
```
Resultat:
```text
commit 8570b0243f13db9fd058403c45417a55f35af1ee (HEAD -> exercice4-add-p)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 20:03:56 2026 +0100

    ajout du commentaire a la place de la valeur de f

diff --git a/fichier1.cpp b/fichier1.cpp
index 056033a..8027efd 100644
--- a/fichier1.cpp
+++ b/fichier1.cpp
@@ -9,7 +9,7 @@ int main()
     int c = 30;
     int d = 40;
     int e = 50;
-    int f = 60;
+    //modification2

     std::cout << a + b << std::endl;
```

On remarque que ce deuxieme commit contient uniquement la modification de `f`.

## CONCLUSION DE LA NOUVELLE TENTATIVE
Cette nouvelle tentative permet de montrer les deux commits que mon utilisation de `git add -p` devait produire.
Le premier commit est:
```
d40e9b1 modifications de la valeur de a
```
et contient uniquement la modification de `a`.
Le deuxieme commit est:
```
8570b02 ajout du commentaire a la place de la valeur de f
```
et contient uniquement la modification de `f`.
Cette fois, la verification avec `git log --oneline` et les deux commandes `git show` permet donc de prouver que les deux modifications ont bien ete separees dans deux commits differents.
