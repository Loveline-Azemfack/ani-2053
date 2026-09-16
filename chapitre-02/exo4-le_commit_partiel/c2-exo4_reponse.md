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