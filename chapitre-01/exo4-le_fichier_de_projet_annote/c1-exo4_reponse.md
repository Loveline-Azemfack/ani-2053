# EXERCICE 4

En ce qui concerne cet exercice, pour un fichier .jenga du module qui  n'a pas ete presente dans le chapitre, je choisi celui du module **NkPlatforme** qui est :  **NKPlatforme.jenga**

Dont le contenu est le suivant:

```
1 : #!/usr/bin/env python3  
2 : # -*- coding: utf-8 -*-  
3 : """
4 : NKPlatform — Détection OS/arch/compilateur/CPU (C++20)
5 : =========================================================
6 : Fondation sans dépendances. Fournit des macros et informations
7 : compilées sur l'environnement d'exécution.
8 : """
9 : 
10 : from Jenga import *
11 : from jengaconfig import *
12 : 
13 : 
14 : with project("NKPlatform"):
15 :     language("C++")
16 :     cppdialect("C++20")
17 :     location(".")
18 : 
19 :     nkentseudependson(
20 :         [],
21 :         selfexport="NKPlatform",
22 :         extra_includes=["src", "pch"],
23 :     )
24 : 
25 :     pchheader("pch/pch.h")
26 :     pchsource("pch/pch.cpp")
27 : 
28 :     files([
29 :         "src/NKPlatform/**.cpp",
30 :         "src/NKPlatform/**.h",
31 :     ])
32 : 
33 :     objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
34 :     targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
35 : 
36 :     with filter("system:Windows && options:windows-runtime=uwp"):
37 :         objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
38 :         targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")
39 : 
40 :     with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
41 :         usetoolchain(TC_WINDOWS)
42 :     with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
43 :         usetoolchain("xbox-clang")
44 :     with filter("system:macOS"):
45 :         usetoolchain("clang-native")
46 :     with filter("system:Android"):
47 :         # Workaround: disable PCH on Android (NDK r27 + clang 18 + libc++)
48 :         pchheader("")
49 :         pchsource("")
50 :         usetoolchain("android-ndk")
51 :     with filter("system:HarmonyOS"):
52 :         # PCH desactive (NDK OHOS clang, meme contrainte qu'Android)
53 :         pchheader("")
54 :         pchsource("")
55 :         usetoolchain("ohos-ndk")
56 :     with filter("system:Web"):
57 :         usetoolchain("emscripten")
58 :     with filter("system:XboxSeries || system:XboxOne"):
59 :         usetoolchain("xbox-clang")
60 : 
61 :     with filter("config:Debug"):
62 :         defines(["_DEBUG", "DEBUG", "NKENTSEU_DEBUG"])
63 :         optimize("Off")
64 :         symbols(True)
65 :     with filter("config:Release"):
66 :         defines(["NDEBUG", "NKENTSEU_RELEASE"])
67 :         optimize("Speed")
68 :         symbols(False)
69 : 
70 :     # Tests unitaires/benchmarks (desktop uniquement)
71 :     with filter("(system:Linux || system:macOS || (system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne)) && !system:Android && !system:iOS || system:Web"):
72 :         with test():
73 :             testfiles(["tests/**.cpp"])
PS D:\Projets\Rihen\Nkentseu> 
```
ceci a ete obtenu, apres avoir lancer la ommande suivante, pour obtenir, non seulement le contenu mais aussi aves le numero des lignes  
```
 $i=1; Get-Content .\Kernel\Foundation\NKPlatform\NKPlatform.jenga | ForEach-Object { "$i : $_"; $i++ }
```

### INFORMATIONS DEMANDES
#### type
Type de NKPlatforme: NkPlatforme  est de type "StaticLib"

#### sources
les sources de celui ci sont tous les .cpp et tous les .h comme ecris dans son .jenga qui sont:
```

NkArchDetect.cpp
NkArchDetect.h
NkCGXDetect.cpp
NkCGXDetect.h
NkCompilerDetect.cpp
NkCompilerDetect.h
NkCPUFeatures.cpp
NkCPUFeatures.h
NkEndianness.cpp
NkEndianness.h
NkEnv.cpp
NkEnv.h
NkFoundationLog.h
NKPlatform.h
NkPlatformConfig.cpp
NkPlatformConfig.h
NkPlatformDetect.h
NkPlatformExport.h
NkPlatformInline.h
NkX11Clean.h

```

qui sont des noms obtenus apres avoir taper la commande:
```
Get-ChildItem .\Kernel\Foundation\NKPlatform -Recurse -Include *.cpp,*.h -File | Select-Object Name
```
Cependant je n'ai tenu compte que de ceux qui etaient dans le dossier src.

#### dependances
NKPlatforme ne depend d'aucun autre projet c'est plutot le contraire car, les autres projets dependent plutot de lui

#### filtres

Lorsqu'on observe tous les filters de NKPlatforme.jenga,  on remarque que les differents filtres qui en ressortenet sont:
```
Windows
UWP
macOS
Android
HarmonyOS
Web
XboxSeries
XboxOne
Debug
Release
```

#### Tests

Dans le dossier test de NKPlatforme, on observe de fichier, un .sh et celui .cpp
Mais dans le jenga le with test concerne tous les .cpp alors comme test ici on a :
```
temoin_noms_additifs.cpp
```

#### Marquons d'un point d'interrogation tout ce que nous ne comprennons pas encore

```
? (je ne comprends pas bien le role de selfexport) :         nkentseudependson(
        20 :         [],
        21 :         selfexport="NKPlatform",
        22 :         extra_includes=["src", "pch"],
        23 :     )
        24 : 
        25 :     pchheader("pch/pch.h")
        26 :     pchsource("pch/pch.cpp")
        27 : 
```
?  (ici je ne comprends pas par quoi se traduit le tiret entre ceci %{cfg.buildcfg}-%{cfg.system} ):
```
targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
```

? (qu'est ce qui se passe lorsqu'on laisse les guillemets vides):
```
# Workaround: disable PCH on Android (NDK r27 + clang 18 + libc++)
48 :         pchheader("")
49 :         pchsource("")
50 :         usetoolchain("android-ndk")
```

?(a quoi servent symboles et optimize) :
```
with filter("config:Debug"):
62 :         defines(["_DEBUG", "DEBUG", "NKENTSEU_DEBUG"])
63 :         optimize("Off")
64 :         symbols(True)
```