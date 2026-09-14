# EXERCICE 8:  _Construisez le même projet dans les deux configurations et comparez la taille du binaire produit et le temps de construction. Retrouvez ensuite, dans le .jenga, les lignes qui expliquent les quatre nombres._


Pour realiser ceci, je devrais d'abord dans un premier temps construire le fichier en utiisant le **--config Debug** relever la **taille** du binaire et le **temps** de construction

## DEBUG

### CONSTRUCTION
Pour cela j'utiliserai la commande suivante:
```
jenga build --target MonEssai --config Debug
```

Resultat:
```
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (17 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  11. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  12. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  13. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  14. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  15. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  17. MonEssai [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.56s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.14s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.25s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.12s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.26s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.35s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.28s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 31 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           3.88s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

#### TEMPS DE CONSTRUCTION
```
Time:           3.88s
```

#### TAILLE DU BINAIRE PRODUIT
Pour cela je me sers de la commande suivante:
```
$debug = (Get-ChildItem ".\Build\Lib\Debug-Windows" -Recurse -File | Measure-Object Length -Sum).Sum

"Debug   : {0} octets | {1} Mo" -f $debug, [math]::Round($debug / 1MB, 3)
```
Cette commande a ete obtenu apres une recherche personnelle effectuee sur IA
```
Debug   : 31909358 octets | 30,431 Mo
```

## RELEASE
### CONSTRUCTION
Pour cela j'utiliserai la meme commande mais en remplacant le "Debug" par "Release" comme suit:
```
jenga build --target MonEssai --config Release
```

Resutat obtenu:
```
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Release
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (17 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  11. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  13. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  14. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  15. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  17. MonEssai [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkCGXDetect.cpp
✓   [2/7] Compiled: NkArchDetect.cpp
✓   [3/7] Compiled: NkEndianness.cpp
✓   [4/7] Compiled: NkCompilerDetect.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkCPUFeatures.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: wgl.c
✓   [2/2] Compiled: gl.c
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKGlad.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.59s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkTraits.cpp
✓   [3/5] Compiled: NkAssert.cpp
✓   [4/5] Compiled: NkBits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKCore.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGlobalOperators.cpp
✓   [2/14] Compiled: NkProfiler.cpp
✓   [3/14] Compiled: NkFunction.cpp
✓   [4/14] Compiled: NkHash.cpp
✓   [5/14] Compiled: NkMultiLevelAllocator.cpp
✓   [6/14] Compiled: NkFunctionSIMD.cpp
✓   [7/14] Compiled: NkMemory.cpp
✓   [8/14] Compiled: NkGc.cpp
✓   [9/14] Compiled: NkContainerAllocator.cpp
✓   [10/14] Compiled: NkTag.cpp
✓   [11/14] Compiled: NkPoolAllocator.cpp
✓   [12/14] Compiled: NkUtils.cpp
✓   [13/14] Compiled: NkTracker.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.79s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBTree.cpp
✓   [2/43] Compiled: NkArray.cpp
✓   [3/43] Compiled: NkPool.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkPriorityQueue.cpp
✓   [6/43] Compiled: NkTrie.cpp
✓   [7/43] Compiled: NkBinaryTree.cpp
✓   [8/43] Compiled: NkUnorderedSet.cpp
✓   [9/43] Compiled: NkSet.cpp
✓   [10/43] Compiled: NkUnorderedMap.cpp
✓   [11/43] Compiled: NkHashMap.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkBind.cpp
✓   [14/43] Compiled: NkPair.cpp
✓   [15/43] Compiled: NkTuple.cpp
✓   [16/43] Compiled: NkFunction.cpp
✓   [17/43] Compiled: NkIterator.cpp
✓   [18/43] Compiled: NkInitializerList.cpp
✓   [19/43] Compiled: NkFunctional.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkVector.cpp
✓   [22/43] Compiled: NkQuadTree.cpp
✓   [23/43] Compiled: NkEncoding.cpp
✓   [24/43] Compiled: NkGraph.cpp
✓   [25/43] Compiled: NkASCII.cpp
✓   [26/43] Compiled: NkUTF32.cpp
✓   [27/43] Compiled: NkUTF16.cpp
✓   [28/43] Compiled: NkDeque.cpp
✓   [29/43] Compiled: NkList.cpp
✓   [30/43] Compiled: NkDoubleList.cpp
✓   [31/43] Compiled: NkBase64.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkOptional.cpp
✓   [34/43] Compiled: NkResult.cpp
✓   [35/43] Compiled: NkVariant.cpp
✓   [36/43] Compiled: NkFormat.cpp
✓   [37/43] Compiled: NkSpan.cpp
✓   [38/43] Compiled: NkBasicString.cpp
✓   [39/43] Compiled: NkStringView.cpp
✓   [40/43] Compiled: NkString.cpp
✓   [41/43] Compiled: NkStringHash.cpp
✓   [42/43] Compiled: NkStringBuilder.cpp
✓   [43/43] Compiled: NkStringUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkSIMD.cpp
✓   [2/12] Compiled: NkFunctions.cpp
✓   [3/12] Compiled: NkAngle.cpp
✓   [4/12] Compiled: NkRange.cpp
✓   [5/12] Compiled: NkEulerAngle.cpp
✓   [6/12] Compiled: NkMat.cpp
✓   [7/12] Compiled: NkQuat.cpp
✓   [8/12] Compiled: NkRandom.cpp
✓   [9/12] Compiled: NkSegment.cpp
✓   [10/12] Compiled: NkRectangle.cpp
✓   [11/12] Compiled: NkColor.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkRecursiveMutex.cpp
✓   [2/12] Compiled: NkEvent.cpp
✓   [3/12] Compiled: NkBarrier.cpp
✓   [4/12] Compiled: NkSharedMutex.cpp
✓   [5/12] Compiled: NkLatch.cpp
✓   [6/12] Compiled: NkSemaphore.cpp
✓   [7/12] Compiled: NkConditionVariable.cpp
✓   [8/12] Compiled: NkMutex.cpp
✓   [9/12] Compiled: NkThread.cpp
✓   [10/12] Compiled: NkSpinLock.cpp
✓   [11/12] Compiled: NkReaderWriterLock.cpp
✓   [12/12] Compiled: NkThreadPool.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKThreading.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.13s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkLogLevel.cpp
✓   [2/14] Compiled: NkLoggerFormatter.cpp
✓   [3/14] Compiled: NkSink.cpp
✓   [4/14] Compiled: NkDistributingSink.cpp
✓   [5/14] Compiled: NkFileSink.cpp
✓   [6/14] Compiled: NkLogMessage.cpp
✓   [7/14] Compiled: NkLog.cpp
✓   [8/14] Compiled: NkRegistry.cpp
✓   [9/14] Compiled: NkAsyncSink.cpp
✓   [10/14] Compiled: NkConsoleSink.cpp
✓   [11/14] Compiled: NkDailyFileSink.cpp
✓   [12/14] Compiled: NkLogger.cpp
✓   [13/14] Compiled: NkNullSink.cpp
✓   [14/14] Compiled: NkRotatingFileSink.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKLogger.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.26s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkFileWatcher.cpp
✓   [2/5] Compiled: NkPath.cpp
✓   [3/5] Compiled: NkFileSystem.cpp
✓   [4/5] Compiled: NkFile.cpp
✓   [5/5] Compiled: NkDirectory.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKFileSystem.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.91s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkFontDetect.cpp
✓   [2/8] Compiled: NkFontSizeCache.cpp
✓   [3/8] Compiled: NkFontRasterizer.cpp
✓   [4/8] Compiled: NkUtils.cpp
✓   [5/8] Compiled: NkFontParser.cpp
✓   [6/8] Compiled: NkFontMesh.cpp
✓   [7/8] Compiled: NkFontAtlas.cpp
✓   [8/8] Compiled: NkFontEmbedded.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKFont.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.62s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkDate.cpp
✓   [2/8] Compiled: NkDuration.cpp
✓   [3/8] Compiled: NkClock.cpp
✓   [4/8] Compiled: NkTimeSpan.cpp
✓   [5/8] Compiled: NkTimeZone.cpp
✓   [6/8] Compiled: NkSystemClock.cpp
✓   [7/8] Compiled: NkChrono.cpp
✓   [8/8] Compiled: NkTimes.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKTime.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.12s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkConsoleStream.cpp
✓   [2/4] Compiled: NkStream.cpp
✓   [3/4] Compiled: NkBinaryStream.cpp
✓   [4/4] Compiled: NkFileStream.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKStream.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.24s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkEvent.cpp
✓   [2/10] Compiled: NkMouseEvent.cpp
✓   [3/10] Compiled: NkEventState.cpp
✓   [4/10] Compiled: NkWindowEvent.cpp
✓   [5/10] Compiled: NkKeyboardEvent.cpp
✓   [6/10] Compiled: NkDropSystem.cpp
✓   [7/10] Compiled: NkGamepadMappingPersistence.cpp
✓   [8/10] Compiled: NkEventDispatcher.cpp
✓   [9/10] Compiled: NkGamepadSystem.cpp
✓   [10/10] Compiled: NkEventSystem.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKEvent.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.20s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓   [1/13] Compiled: NkTGACodec.cpp
✓   [2/13] Compiled: NkICOCodec.cpp
✓   [3/13] Compiled: NkQOICodec.cpp
✓   [4/13] Compiled: NkBMPCodec.cpp
✓   [5/13] Compiled: NkPPMCodec.cpp
✓   [6/13] Compiled: NkHDRCodec.cpp
✓   [7/13] Compiled: NkGIFCodec.cpp
✓   [8/13] Compiled: NkPNGCodec.cpp
✓   [9/13] Compiled: NkEXRCodec.cpp
✓   [10/13] Compiled: NkJPEGCodec.cpp
✓   [11/13] Compiled: NkSVGCodec.cpp
✓   [12/13] Compiled: NkWebPCodec.cpp
✓   [13/13] Compiled: NkImage.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKImage.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.69s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkLauncher.cpp
✓   [2/9] Compiled: NkWindowCursor.cpp
✓   [3/9] Compiled: NkDialogs.cpp
✓   [4/9] Compiled: NkWindowClipboardImage.cpp
✓   [5/9] Compiled: NkWindowClipboard.cpp
✓   [6/9] Compiled: NkContext.cpp
✓   [7/9] Compiled: NkWESystem.cpp
✓   [8/9] Compiled: NkWin32EventSystem.cpp
✓   [9/9] Compiled: NkWin32Window.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKWindow.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 31 source file(s)
✓   [1/31] Compiled: NkSoftwareComputeContext.cpp
✓   [2/31] Compiled: NkDX11ComputeContext.cpp
✓   [3/31] Compiled: NkDX12ComputeContext.cpp
✓   [4/31] Compiled: NkOpenGLContext.cpp
✓   [5/31] Compiled: NkOpenGLComputeContext.cpp
✓   [6/31] Compiled: NkDX11Renderer2D.cpp
✓   [7/31] Compiled: NkDX12Renderer2D.cpp
✓   [8/31] Compiled: NkDX11Context.cpp
✓   [9/31] Compiled: NkCanvasApp.cpp
✓   [10/31] Compiled: NkOpenGLRenderer2D.cpp
✓   [11/31] Compiled: NkDX12Context.cpp
✓   [12/31] Compiled: NkVulkanRenderer2D.cpp
✓   [13/31] Compiled: NkVulkanComputeContext.cpp
✓   [14/31] Compiled: NkRenderer2DTypes.cpp
✓   [15/31] Compiled: NkSoftwareContext.cpp
✓   [16/31] Compiled: NkGpuPolicy.cpp
✓   [17/31] Compiled: NkBatchRenderer2D.cpp
✓   [18/31] Compiled: NkVulkanContext.cpp
✓   [19/31] Compiled: NkFont.cpp
✓   [20/31] Compiled: NkSoftwareRenderer2D.cpp
✓   [21/31] Compiled: NkRenderer2DFactory.cpp
✓   [22/31] Compiled: NkContextFactory.cpp
✓   [23/31] Compiled: NkShader.cpp
✓   [24/31] Compiled: NkShape.cpp
✓   [25/31] Compiled: NkRenderTarget.cpp
✓   [26/31] Compiled: NkTexture.cpp
✓   [27/31] Compiled: NkSprite.cpp
✓   [28/31] Compiled: NkRenderTexture.cpp
✓   [29/31] Compiled: NkUICanvasBackend.cpp
✓   [30/31] Compiled: NkRenderWindow.cpp
✓   [31/31] Compiled: NkRenderWindowCapture.cpp
ℹ Linking...
✓ Built: Build\Lib\Release-Windows\NKCanvas.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 10.62s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Release-Windows\MonEssai\MonEssai.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.63s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           50.79s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

### TEMPS DE CONSTRUCTION
```
Time:           50.79s
```

### TAILLE DU BINAIRE OBTENU
```
Release : 7690690 octets | 7,334 Mo
```
obtenu apres avoir taper la commande
```
$release = (Get-ChildItem ".\Build\Lib\Release-Windows" -Recurse -File | Measure-Object Length -Sum).Sum

"Release : {0} octets | {1} Mo" -f $release, [math]::Round($release / 1MB, 3)
```
## EXPLICATION DE L'OBSERVATION
Voici l'ensemble des lignes qui ressortent cette difference
```
    with filter("config : Debug"):
        defines(["DEBUG"]); optimize("Off"); symbols(True)

    with filter ("config : Release"):
        defines(["NDEBUG"]) ; optimize("Speed"); symbols (False)
```

**Apres observations et rigueur et apres avoir modifier la commande precedente qui etait "(Get-Item ".\Build\Bin\Debug-Windows\MonEssai\MonEssai.exe").Length / 1MB" pour chacune des configurations     , il revient a dire que leurs executables ont des tailles differentes.**