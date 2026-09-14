# EXERCICE 11: _Introduisez une faute de syntaxe dans un fichier de NKMath et reconstruisez. Notez : combien de temps met la construction à s'arrêter, quels projets ont quand même été construits, et ce que le message d'erreur vous apprend sur l'ordre de construction. Remettez ensuite le fichier en état._

Alors pour cet exercice, j'ai decide d'introduire l'erreur dans le fichier **NKAngle.cpp** du dossier **NKMath**

Et je l'ai faite a la ligne 14 de ce fichier en changeant:
```
#include <ostream>
```
par:
```
include <ostream>
```

Maintenant, passons a la reconstruction:

## Reconstruction de NKMath

Pour cela, nous utilisons la commande:  
```
jenga build --target NKMath
```

Resultat obtenu:
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

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.41s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: NkAngle.cpp                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp:14:10: error:      ║
║ unknown type name 'ostream'; did you mean 'std::ostream'?                                    ║
║    14 | include <ostream>                                                                    ║
║       |          ^~~~~~~                                                                     ║
║       |          std::ostream                                                                ║
║ C:/msys64/ucrt64/include/c++/15.2.0/iosfwd:145:33: note: 'std::ostream' declared here        ║
║   145 |   typedef basic_ostream<char>           ostream;                                     ║
║       |                                         ^                                            ║
║ D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp:14:1: error: no    ║
║ template named 'include'                                                                     ║
║    14 | include <ostream>                                                                    ║
║       | ^                                                                                    ║
║ D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp:16:1: error:       ║
║ expected unqualified-id                                                                      ║
║    16 | namespace nkentseu {} // namespace nkentseu                                          ║
║       | ^                                                                                    ║
║ 3 errors generated.                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.84s  │
│ Errors: 3  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/5
Failed:         1
Errors:         3
Time:           1.44s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKMath

```

### Temps de construction
voici alors le temps de construction:
```
Time:           1.44s
```

### Les Projets Produits
Jenga devait produire 5 projets qui sont:
1. NKPlatform
2. NKCore
3. NKMemory
4. NKContainers
5. NKMath

Malgre l'erreur de syntax, les projets qui ont quand meme ete produits sont de **4/5** et sont  les suivants:
1. NKPlatform
2. NKCore
3. NKMemory
4. NKContainers

### ce que le message d'erreur apprend sur l'ordre de construction

Quand on regarde le message d'erreur:
```
ℹ Found 12 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: NkAngle.cpp                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp:14:10: error:      ║
║ unknown type name 'ostream'; did you mean 'std::ostream'?                                    ║
║    14 | include <ostream>                                                                    ║
║       |          ^~~~~~~                                                                     ║
║       |          std::ostream                                                                ║
║ C:/msys64/ucrt64/include/c++/15.2.0/iosfwd:145:33: note: 'std::ostream' declared here        ║
║   145 |   typedef basic_ostream<char>           ostream;                                     ║
║       |                                         ^                                            ║
║ D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp:14:1: error: no    ║
║ template named 'include'                                                                     ║
║    14 | include <ostream>                                                                    ║
║       | ^                                                                                    ║
║ D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkAngle.cpp:16:1: error:       ║
║ expected unqualified-id                                                                      ║
║    16 | namespace nkentseu {} // namespace nkentseu                                          ║
║       | ^                                                                                    ║
║ 3 errors generated.                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

```

**_On voit qu'il appartient au projet NKMath mais cela n'a pas empecher la construction des 4 autres projets et si on remarque bien ces 4 autres sont les dependances de NKMath, cela prouve que la construction d'un projet commence d'abord par celle de ses dependances et une erreur dans ce projet la n'empechera pas la construction de ses dependances mais elle arrete juste la compilation du projets dans lequel elle se trouve._**

## Remise en etat du fichier

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

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.11s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.41s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [12/12] Compiled: NkAngle.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.92s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           1.51s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

**CONCLUSION:**
Lorsqu'on introduit une faute dans le fichier dans NKMath, le temps de compilation est donc de : **1.44s** Les projets qui ont quand meme ete construits sont : **NKPlatform
NKCore
NKMemory
NKContainers**. Et le messages d'erreur nous apprend que **la construction d'un projet commence d'abord par celle de ses dependances**.