# EXERCICE 11:
Pour cet execice, il faudra donc que je choisisse un fichier pour cela, je n evais pas e faire uisque je n'ai pas de fichier ayant ce poids, je vais donc en cree un avec la commande suivante:
```
 $bytes = New-Object byte[] (10MB); [System.IO.File]::WriteAllBytes("Monfichier.bin", $bytes) 
```
Si vous voulez, vous mettez une autre extension de fichier, il y aura pas de probleme. alors pour bien verifier que ce fichier pese exactement la taille demandé:  
```
Get-Item Monfichier.bin | Select-Object Name, Length 
```
Et on voit exactement :
```
Name             Length
----             ------
Monfichier.bin 10485760
```
On voit bien qu'il pese 10 Mega-octet

Mesurons d'abord a taille du commit present:
```
(Get-ChildItem -Recurse -File .git | Measure-Object -Property Length -Sum).Sum
```
Resultat:
```
53700 octets
```
Maintenant on va le  commiter et voici mon commit:
```
git commit -m "ajout d'un fichier de 10Mo dans le cadre de l'exercice 11" 
```

Maintenant le resultat:
```
[integration-rebase 440c410] ajout d'un fichier de 10Mo dans le cadre de l'exercice 11
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Monfichier.bin
```
Passons maintenant a la mesure de notre .git actuel:
```
(Get-ChildItem -Recurse -File .git | Measure-Object -Property Length -Sum).Sum
```
qui nous permettra de mesurer la taille des element de notre .git  et de les sommer:
```
99942
```
Maintenant, supprimons notre fichier **Monfichier.bin** avec **rm Monfichier.bin**, faisons un git status pour verifier que cela a ete fait, on obtient ceci :
```
On branch integration-rebase                       
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        deleted:    Monfichier.bin
``` 
Et cela a bien reussi, maitenant, faisons un nouveau commit et remesurons:
```
git commit -m "suppression du fichier de 10Mo dans le cadre de l'exercice 11"
```
on obtient:
```
[integration-rebase 3590358] suppression du fichier de 10Mo dans le cadre de l'exercice 11
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 Monfichier.bin
```

Mesure:
```
(Get-ChildItem -Recurse -File .git | Measure-Object -Property Length -Sum).Sum
```

Resultat:
```
98082 octets
```

## CONCLUSION:
Face aux differentes mesures obtenues avant le commit du fichier cree, apres commit et apres suppression qui sont respectivement **53700 octets**, **99942 octets**, **98082 octets**, On remarque donc qu'apres avoir supprimé le fichier, la taille de .git est toujours supérieure à sa taille initiale de 53700 octets. Cela montre que la suppression du fichier du projet ne supprime pas automatiquement les données correspondantes de l'historique Git. Le fichier reste present dans les anciens commits.
Par ailleurs On remarque également que mon fichier faisait 10 485 760 octets, alors que la taille de .git n'a augmenté que de 46 242 octets après le premier commit. Cela s'explique par le fait que le fichier créé était rempli de zéros, et git a donc facilement compresse ces donnees la.


# REACTION FACE A L'OBSERVATION 
Pour cet execice, il faudra donc que je choisisse un fichier pour cela, je ne vais pas le faire puisque je n'ai pas de fichier ayant ce poids, je vais donc en creer un avec les commandes suivantes:

```powershell
$bytes = New-Object byte[] (10MB)
[System.Security.Cryptography.RandomNumberGenerator]::Fill($bytes)
[System.IO.File]::WriteAllBytes("Monfichier.bin", $bytes)
```
Si vous voulez, vous mettez une autre extension de fichier, il n'y aura pas de probleme. Alors pour bien verifier que ce fichier pese exactement la taille demandée:
```
(Get-Item Monfichier.bin).Length
```
Et on voit exactement:
```
10485760
```
On voit bien qu'il pese 10 Mega-octet.

Maintenant on va le commiter et voici mon commit:

```
git add Monfichier.bin
git commit -m "ajout Monfichier.bin qui pese 10 mega"
```
resultat:
```
[print2 ce975c7] ajout Monfichier.bin qui pese 10 mega
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Monfichier.bin
```
Passons maintenant a la mesure de notre .git actuel:
```powershell
(Get-ChildItem -Recurse -File .git | Measure-Object -Property Length -Sum).Sum
```
qui nous permettra de mesurer la taille des element de notre .git et de les sommer:
```
10548633
```
Maintenant, supprimons notre fichier **Monfichier.bin** avec **git rm Monfichier.bin**, faisons un git status pour verifier que cela a ete fait.
Ensuite, faisons un nouveau commit et remesurons:

```
git rm Monfichier.bin
git commit -m "suppression du fichier de 10Mo"
```
On obtient:
```
[print2 ccdd070] suppression du fichier de 10Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 Monfichier.bin
```
Mesure:
```
(Get-ChildItem -Recurse -File .git | Measure-Object -Property Length -Sum).Sum
```
Resultat:
```
10549074 octets
```
## CONCLUSION:

Face aux differentes mesures obtenues avant le commit du fichier cree, apres commit et apres suppression qui sont respectivement **10485760octets**, **10548633 octets**, **10549074 octets**, on remarque donc qu'apres avoir supprimé le fichier, la taille de .git est toujours supérieure à sa taille initiale de 10548633 octets. Cela montre que la suppression du fichier du projet ne supprime pas automatiquement les données correspondantes de l'historique Git. Le fichier reste present dans les anciens commits.
