# EXERCICE 6:
Pour faire cet exercie, mon travail comme toujours  a reposer sur des rechrches, d'abord comment diviser une fenetre et ensuite je me suis servie de NKentseu pour le faire j'ai d'abord visiter le fichier NkWindowCursor.cpp mais je n'ai vraiment pas remarquer tres grandes chose qui pouvait m'aider pour cet exercie, des lors, je suis partie faire **ctrl+shift+f** pour faire la recherche de cursor et quand je parcourait les resultata je suis tombee dans le fichier NKWindow.h dans lequel j'ai remarque ceci:
```cpp
enum class NkCursorType {
				Arrow = 0,	///< fl�che standard
				TextInput,	///< I-beam (saisie texte)
				Hand,		///< main (lien)
				ResizeNS,	///< redimensionnement vertical  ↕
				ResizeWE,	///< redimensionnement horizontal ↔
				ResizeNWSE, ///< diagonale ↘↖
				ResizeNESW	///< diagonale ↗↙
			};
```

C'est donc ca qui ma permis de sonfiguere le comportment du curseur en fonction des zones

# DESCRIPTION DE CE QUI SE PASSE AU SURVOLE
Lorsque je survole chacune de ces  zones, je remarque que le curseur change en fonction de la zone comme par exemple dans la :
### ZONE 1
J'ai la fleche normale du curseur, celle qu'on utilise sur l'interface windows la. 

### ZONE2
Le curseur prend la forme de celui qui est mis pour la saisie, celui qu'on utilise soit pour faire des recherches ou pour ecrire dans word.

### ZONE 3
pour la 3e zone j'obtiens une main, le pointeur celle qui est souvent utiliser pour cliquer sur les liens la.

### ZONE 4
Ici, je remarque une possibilite de redimensionnement verticale, le symbole d'equivalence vertivale la qui aide souvent a agrandir les fenetres ou les reduire, enfaite redimensionner **↕**

### ZONE 5

j'obtiens presque la meme chose qu'a la zone 4 mais c'est juste que cette fois elle est horizontale **↔**

### ZONE 6
C'est toujours presque la meme chose que les deux precedente mais c'est juste que cette fois est en diagonale tendant au cote gauche en haut et droit en bas (cette direction ci **↘↖**)

### ZONE 7
C'est a peu pres la  meme chose que la precedente a la seule difference que ca diagonale tend au cote droit en haut et cote gauche en bas (cette direction ci **↗↙**)