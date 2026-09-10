
## experience personnelle

En utilisant la commande 

```
$src = Get-ChildItem -Recurse -File | Where-Object { $_.Extension -in '.cpp','.h','.hpp','.c','.cc','.cxx' }; $proj = Get-ChildItem -Recurse -File | Where-Object { $_.Extension -in '.sln','.vcxproj','.csproj','.cmake' }; "$($src.Count) fichiers source, $((($src | Get-Content -ErrorAction SilentlyContinue).Count)) lignes, $($proj.Count) fichiers de projet"
```

J'obtiens ceci:
```
3210 fichiers source, 1553020 lignes, 9 fichiers de projet
```

## ce qui est dans le cours


voici celle du chapitre 1
```
  2 641 fichiers source, 1 193 385 lignes, 221 fichiers de projet
```

### DIFFERENCE

Ceci est du au fait que j'ai inclu tous les fichiers, c'est a dire jai inclus les fichiers entetes (.h) le build lui meme et les tests
