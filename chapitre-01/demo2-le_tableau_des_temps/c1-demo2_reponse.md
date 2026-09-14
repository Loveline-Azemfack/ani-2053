# DEMO2:

## construction complète à froid

D'apres mes recherches, une reconstruction complete a froid renvoie a remttre tout a zero, du coup, je vais d'abord verifier s'il y a encore un dosier buil avec la commande :
```
Test-Path .\Build
```
Je l'ai obtenu par mes recherches faites sur IA
 et cette commande renvoie **true** donc on va supprimer ce dossier et tout reprendre a zero, on supprime avec la commande:
 ```
 Remove-Item .\Build -Recurse -Force
 ```

 et quand on verifie avec la meme commande mentionner plus haut, ca renvoie **false** donc ca a bien ete executee

Maintenant on va remttre le workspace a zero depuis la commande:
```
Measure-Command { jenga build }
```
Resultat:
```

Days              : 0
Hours             : 0
Minutes           : 2
Seconds           : 19
Milliseconds      : 919
Ticks             : 1399197997
TotalDays         : 0,00161944212615741
TotalHours        : 0,0388666110277778
TotalMinutes      : 2,33199666166667
TotalSeconds      : 139,9197997
TotalMilliseconds : 139919,7997
```

### Temps relever de  la construction complete a froid
**TotalSeconds      : 139,9197997s**

## Construction complete a chaud

Ici on ne va rien changer car ceci consiste a faire une nouvelle construction sans toutefois remettre a zero, donc on va encore utiliser la meme construction que celle a froid
```

Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 12
Milliseconds      : 758
Ticks             : 127586237
TotalDays         : 0,000147669255787037
TotalHours        : 0,00354406213888889
TotalMinutes      : 0,212643728333333
TotalSeconds      : 12,7586237
TotalMilliseconds : 12758,6237
```

### Temps relever de  la Construction complete a chaud
**TotalSeconds      : 12,7586237s**

## construction après modification d'un seul fichier source
### Cas de NKMath
Cette fois, on utilisera la commande suivante:
```
Measure-Command { jenga build --target NKMath} 
```
Resultat:
```
Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 5
Milliseconds      : 198
Ticks             : 51980489
TotalDays         : 6,01626030092593E-05
TotalHours        : 0,00144390247222222
TotalMinutes      : 0,0866341483333333
TotalSeconds      : 5,1980489
TotalMilliseconds : 5198,0489

```
### Temps relever de  la construction après modification d'un seul fichier source
**TotalSeconds      : 5,1980489s**

## construction après modification d'un seul en-tête
```

Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 5
Milliseconds      : 241
Ticks             : 52410696
TotalDays         : 6,06605277777778E-05
TotalHours        : 0,00145585266666667
TotalMinutes      : 0,08735116
TotalSeconds      : 5,2410696
TotalMilliseconds : 5241,0696
```
### Temps relever de  la construction après modification d'un seul en-tête
**TotalSeconds      : 5,2410696s**

## EXPLICATION
ici on remarque que lorsqu'on modifie un ficher source, le temps de construction est superieur a celui dont on modifie le fichier entete, ceci s'explique simplement par le fait que lorsqu'on modifie pour le fichier source lors de la reconstruction, ca ne va pas prendre assez de temps car c'est uniquement sur ce fichier tantdis que lorsqu'on le fait dans  un fichier entete, le temps de reconstruction est superieur car plusieurs autre projet peuvent dependre d'un fichier entete du coup, on est aussi obligee de recompiler ces projets, donc ici, c'est la notion de dependances qui tue le temps.