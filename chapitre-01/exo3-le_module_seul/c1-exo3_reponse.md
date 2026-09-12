# EXERCICE3

J'ai construit le projet `NKMath` avec la commande :

```
jenga build --target NKMath --config Debug
```
## l'ordre de construction
Jenga a affiché l'ordre de construction suivant :

```
1. NKPlatform
2. NKCore
3. NKMemory
4. NKContainers
5. NKMath
```

```text
NKPlatform → NKCore → NKMemory → NKContainers → NKMath
```

## Maintenant presentons cela sous forme d'arbre

D'apres ceci
```
Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)
```
sous forme d'arbre on peut representer comme ceci;

```
NKMath
|── NKContainers
│   |── NKMemory
│   │   
│   |── NKCore
│   |── NKPlatform
|
|── NKMemory
│   |── NKCore
│   
|── NKCore
│   |── NKPlatform
└── NKPlatform
```


Donc l'ensemble de dependance montre que NKMath depend de tous les autres NK


