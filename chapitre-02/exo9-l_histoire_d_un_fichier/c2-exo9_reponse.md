# EXERCICE 9

Ici nous allons travailler dans **Nkentseu**.
Pour ce travail je choisis le fichier **NKAngle.cpp** de **Nkentseu**.
Alors nous allons lire l’histoire de ce fichier à travers les différentes opérations suivantes.

## Reconstruction de sa création

Reconstruire un fichier ici ne consiste pas à le recréer mais à comprendre son processus de création. Ainsi, pour cette tâche, nous allons d’abord afficher tous les commits liés au fichier et j’utiliserai la commande suivante :

```
git log --follow --oneline d:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp
```

Cette commande me permet de suivre le fichier et d’afficher tous les commits qui ont été faits pour celui-ci. J’obtiens :

```
f0456467 Licence : uniformiser les en-têtes sur « All Rights Reserved »
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
d557314e update
1d4f072b refactor 002
f1e536a5 refactor 001
9c49f79f bug fix vulkan opengl dx11 current bug software and dx12
```

Donc voici tous ces commits. Maintenant, nous allons rechercher le moment où notre fichier a été enregistré pour la première fois, car c’est là que débute sa création. Nous utiliserons cette commande :

```
git log --follow --diff-filter=A --oneline -- d:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp
```

Cette commande nous permettra de retrouver le moment où le fichier a été enregistré pour la première fois à travers la partie de la commande **--diff-filter=A**, où **A** est mis pour **Added**.

Ainsi, le résultat de cette commande est :

```
9c49f79f bug fix vulkan opengl dx11 current bug software and dx12
```

Alors ici, on peut dire que le fichier **NKAngle.cpp** a été créé le **21 mars 2026**, dans le commit **9c49f79f**, intitulé « bug fix vulkan opengl dx11 current bug software and dx12 ».

Là maintenant, nous devons passer à l’historique des changements mais cette fois de manière très détaillée. Pour cette partie, nous utiliserons la commande suivante :

```
git log --follow --stat -- d:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp
```

Cette commande nous permettra de voir les fichiers modifiés ainsi que les lignes qui ont été ajoutées ou supprimées. En bref, cette commande offre beaucoup de détails.

Après avoir obtenu les résultats, nous pouvons résumer le nombre d’ajouts et de suppressions dans le tableau suivant :

| Commit     | Ajouts | Suppressions | Total modifié |
| ---------- | -----: | -----------: | ------------: |
| `f0456467` |      1 |            1 |         **2** |
| `bdda350a` |      1 |            3 |         **4** |
| `d557314e` |      0 |            0 |         **0** |
| `1d4f072b` |      2 |           95 |        **97** |
| `f1e536a5` |    110 |            9 |       **119** |
| `9c49f79f` |     14 |            0 |        **14** |

## Les trois moments où il a le plus changé

Les 3 moments où le fichier a le plus changé se retrouvent simplement en regardant le tableau précédent, et là, on obtient :

* D’abord, d’après le commit dont l’identifiant est **f1e536a5**, on remarque au total **119 modifications**, parmi lesquelles **110 ajouts et 9 suppressions**.

* Ensuite, **1d4f072b**, où on remarque **2 ajouts et 95 suppressions**, donc au total **97 modifications**.

* Enfin, **9c49f79f** : ici, on a **14 modifications**, parmi lesquelles **14 ajouts et 0 suppression**.

## Ce que les messages disent des raisons

Pour cette partie, nous allons utiliser une commande pour afficher le message de chaque commit, et c’est celle-ci :

```
git show -s --format=fuller ID_du_commit
```

### f1e536a5

La commande est donc :

```
git show -s --format=fuller f1e536a5
```

Le résultat nous montre notamment :

```
commit f1e536a58890ac267b12ab7df1004d0a43270c48
Author: LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Wed Apr 29 10:39:16 2026 +0100
Commit: LeTeguis <teuguiasederis@gmail.com>
CommitDate: Wed Apr 29 10:39:16 2026 +0100

    refactor 001
```

Là, on remarque que le commit affiche l’auteur qui est **LeTeguis [teuguiasederis@gmail.com](mailto:teuguiasederis@gmail.com)** et que le message du commit est **« refactor 001 »**. Ce message indique donc qu’il s’agit d’une refactorisation, mais il ne précise pas exactement la raison de cette modification.

### 1d4f072b

Commande :

```
git show -s --format=fuller 1d4f072b
```

Le résultat donne :

```
commit 1d4f072b3ca1af774f191889211cc51fc224e24e
Author: LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Thu Apr 30 08:44:44 2026 +0100
Commit: LeTeguis <teuguiasederis@gmail.com>
CommitDate: Thu Apr 30 08:44:44 2026 +0100

    refactor 002
```

Ici, il en va de même qu’au premier commit, c’est juste que la date change, et le message est **« refactor 002 »**. Le message indique donc également une refactorisation, mais ne donne pas plus de détails sur sa raison.

### 9c49f79f

Commande :

```
git show -s --format=fuller 9c49f79f
```

Le résultat donne :

```
commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author: LeTeguis <teuguiasederis@gmail.com>
AuthorDate: Sat Mar 21 03:25:48 2026 +0100
Commit: LeTeguis <teuguiasederis@gmail.com>
CommitDate: Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12
```

Ici, il en va de même qu’au premier commit concernant l’auteur, mais le message est différent. Il est **« bug fix vulkan opengl dx11 current bug software and dx12 »**. On comprend donc à travers ce message que le changement était lié à une **correction de bug** concernant Vulkan, OpenGL, DX11, le mode software et DX12.

Ainsi, à travers ces différentes opérations, nous avons pu reconstruire l’histoire de **NKAngle.cpp** : nous avons retrouvé sa création, identifié les trois moments où il a le plus changé et analysé les messages associés afin de comprendre les raisons indiquées pour ces changements.

Mais face a mes differentes difficultes je me suis servis de l'IA pour mieux m'expliquer et pour m'aider avec certaines commandes git comme pour afficher l moment ou le fichier a ete modifie pour la premiere fois et bien evidemment j;ai compris cette commandes.