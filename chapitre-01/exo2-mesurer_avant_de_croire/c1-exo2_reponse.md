

## Exercice 2

J'ai compté les fichiers source `.cpp` et `.h` avec :

```
(Get-ChildItem -Recurse -Include *.cpp,*.h -File).Count
```

Résultat :

```
3168
```

J'ai compté les lignes avec :

```
(Get-ChildItem -Recurse -Include *.cpp,*.h -File | Get-Content).Count
```

Résultat :

```
1435334
```

J'ai compté les fichiers `.jenga` avec :

```
(Get-ChildItem -Recurse -Filter *.jenga -File).Count
```

Résultat :

```
199
```

J'ai vérifié le comptage en excluant le dossier `Build` :

```
(Get-ChildItem -Recurse -Include *.cpp,*.h -File | Where-Object { $_.FullName -notlike "*\Build\*" }).Count
```

Résultat :

```
3168
```

Pour les lignes :

```powershell
(Get-ChildItem -Recurse -Include *.cpp,*.h -File | Where-Object { $_.FullName -notlike "*\Build\*" } | Get-Content).Count
```

Résultat :

```
1435334
```

J'ai aussi compté les fichiers de test :

```
(Get-ChildItem -Recurse -Include *.cpp,*.h -File | Where-Object { $_.FullName -match '\\tests?(\\|$)' }).Count
```

Résultat :

```
162
```

Et leurs lignes :

```
(Get-ChildItem -Recurse -Include *.cpp,*.h -File | Where-Object { $_.FullName -match '\\tests?(\\|$)' } | Get-Content).Count
```

Résultat :

```text
27582
```

Les chiffres du chapitre sont **2641 fichiers source, 1 193 385 lignes et 221 fichiers `.jenga`**.

### EXPLICATION
La différence est : En faisant le compte j'ai bien pris en compte les fichiers `.cpp` et `.h`, donc les fichiers d'en-tête sont inclus. J'ai aussi vérifié le dossier `Build` en l'excluant du comptage. Les résultats ne changent pas : j'obtiens toujours **3168 fichiers** et **1 435 334 lignes**. Les fichiers de test sont également présents dans mon comptage. J'en ai trouvé **162**, avec **27 582 lignes**.

