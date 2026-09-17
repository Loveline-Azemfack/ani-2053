# EXERCICE 5:
Cet exercice nous emmene a creer une branche et faire trois commit dessus puis mesurer la placer gagner dans le disque.  
## EN CE QUI CONCERNE  LA BRANCHE
J'ai creer une branche appellee print2, a travers les deux commandes successives:  
```
git branch print2  
git switch  print2
```
La premiere pour creer et la deuxieme pour acceder, on  aurait bien pu faire en une seule ligne comme ceci
```
git switch -c print2
```
Mais pour un processus mieux detailler, j'ai preferee la premiere methode.

## EN CE QUI CONCERNE MES TROIS COMMIT
Lorsque je faisais une modification je faisais un git add nom_fichier et ensuite un git commit:  

### Premier commit:
J'ai juste mis un commentaire dans la premiere ligne de mon deuxieme fichier
```
git add fichier2.cpp
```
Puis:
```
git commit -m "premiere modification"
```
Resultat:
```
[print2 4eb1ced] premiere modification
 1 file changed, 1 insertion(+), 1 deletion(-)
```

### Deuxieme commit:
Ici j'ai juste fais un #include
```
git add fichier2.cpp   
```              
```
git commit -m "ajout de iostream"    
```
Resultat:
```
[print2 79b5cd1] ajout de iostream
 1 file changed, 1 insertion(+)
```

### Troisiseme commit:
La j'ai just fais un main vide
```
git add fichier2.cpp
```
```             
git commit -m "premier main vide"
```
Resultat:
```
[print2 be7af1a] premier main vide
 1 file changed, 4 insertions(+)
```

## Maintenant mesure de la taille
Pour cette partie, j'ai utilisé la commande:
```
(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum
```
Cette commande permet de mesurer la taille de chaque fixhier et sous dossier inclus dans le .git et de sommer les differentes valeurs obtenues.  
Suite a ceci, j'ai obtenu:
```
36973 octets
```

## EXPLICATION

Lorsqu'on effectue une mesure apres les commits, on obtient 36973 octets, orr, ayant oublier de mesurer avant de faire mes commits, je me suis donc renseigner pour obtenir une commade qu'on peut taper afin d'avoir la taille avant le commit et ca m'a fournis cette commande **git switch --detach 4eb1ced^** pour acceder a mon contenu avant mes commit et puis, retaper la commande que j'ai tape pour retrouver la taille et ca m'a fourni ceci **36684 octets** on remarque donc une difference de 289 octets donc la nouvelle branche a travers ses 3 commits a ajouter 289 octets a la taille qui existait deja, ceci peut etre due a l'ajout des **3 commits**