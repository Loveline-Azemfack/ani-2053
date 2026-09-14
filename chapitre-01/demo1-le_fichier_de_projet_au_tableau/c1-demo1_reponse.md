# DEMO1 : PRESENTATION D'UN .JENGA
## cas de NKMath.jenga
### Lectures
```
from Jenga import *
from jengaconfig import *

with project("NKMath"):
    language("C++")
    cppdialect("C++17")
    location(".")

    nkentseudependson(
        ["NKCore", "NKPlatform", "NKContainers", "NKMemory"],
        selfexport="NKMath",
        extra_includes=["src", "pch"],
    )

    pchheader("pch/pch.h")
    pchsource("pch/pch.cpp")

    files([
        "src/NKMath/**.cpp",
        "src/NKMath/**.h",
    ])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")

    with filter("system:Windows && options:windows-runtime=uwp"):
        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
        usetoolchain(TC_WINDOWS)
    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
        usetoolchain("xbox-clang")
    with filter("system:macOS"):
        usetoolchain("clang-native")
    with filter("system:Android"):
        # Workaround: disable PCH on Android (NDK r27 + clang 18 + libc++)
        pchheader("")
        pchsource("")
        usetoolchain("android-ndk")
    with filter("system:HarmonyOS"):
        # PCH desactive (NDK OHOS clang, meme contrainte qu'Android)
        pchheader("")
        pchsource("")
        usetoolchain("ohos-ndk")
    with filter("system:Web"):
        usetoolchain("emscripten")
    with filter("system:XboxSeries || system:XboxOne"):
        usetoolchain("xbox-clang")

    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG"])
        optimize("Off")
        symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)

    # Tests unitaires/benchmarks (desktop uniquement)
    with filter("(system:Linux || system:macOS || (system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne)) && !system:Android && !system:iOS || system:Web"):
        with test():
            testfiles(["tests/**.cpp"])
```
### Presentation du fichier
**NKMath.jenga** est un fichier de configuration jenga qui appartient au module NKMath. Dependants ainsi de certains autres modles, sa construction depends de ces autres modules la. Alors ce fichier est retrouvable dans le projet **Nkentseu** selon le chemin d'acces suivant:
```
Nkentseu\Kernel\Foundation\NKMath\NKMath.jenga
```

### Ce qu'il declare
Alors, ce fichier prends pour mission de declarer ce qu'est le projet en fournissant son type, le language utiliser, la version du langage a utiliser a travers **_le cppdialect_**, les differentes outils a utiliser a travers la **_la toolchain_** les fichiers  qui seront compilé a travers la partie **_with files(...)_**. les dossiers qui devront etre cree et les filtres a adopter en fonction du systeme. Par exemple dans le cas de NKMath.jenga, il montre que le projet dans lequel il faut travailler a pour nom **NKMath** et le langage utiliser ici c'est le **C++** et la version **17**,  les fichiers a compiler ici sont  indique dans cette partie:
```
files([
        "src/NKMath/**.cpp",
        "src/NKMath/**.h",
    ])
```

En ce qui concerne la creation des dossier ou fichier qui devront etre cree, on le remarque sur cette partie:
```
objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
```
### Ce qu'il filtre

NKMath.jenga,  filtre les tests unitaires et les differentes configurations a effectuer en fonctions des systemes de meme,  il le fait pour la gestion des configurations (Dans le cas de **Debug** et ou de **Release**)  
Par exemple si on prend par exemple ce cas:
```
with filter("system:macOS"):
        usetoolchain("clang-native")
```

En ce qui concerne les tests unitaires,  on peut le remarquer avec la partie:
```
with filter("(system:Linux || system:macOS || (system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne)) && !system:Android && !system:iOS || system:Web"):
        with test():
            testfiles(["tests/**.cpp"])
```
Qui est senser compiler les fichiers .cpp se trouvant dans le dossier tests
Cette extrait presente que pour le system macOS l'outil a utiliser donc la toolchain est **clang-native**

### ce qu'il délègue
Ici on peut dire qu'il delegue certaines de ses fonctions a travers sa partie :
```
nkentseudependson(
        ["NKCore", "NKPlatform", "NKContainers", "NKMemory"],
        selfexport="NKMath",
        extra_includes=["src", "pch"],
    )
```

Ce qui l'aides a gere ses autres dependances, donc les projets auxquels le projet depend et d'apres cette ecriture on remarque qu'ils sont entre autre: **NKCore, NKPlatform, NKContainers, NKMemory.**

### où est décidé que ce module est une bibliothèque statique
on peut le faire lorsqu'on introduit la partie StaticLib() j'essaierai de retouver ou s'est situer.

#### comprehension de chaque ligne de code
```
from Jenga import *
```
importe toute les fonctions et outil de jenga
```
from jengaconfig import *
```
importe toute les configurations

```
with project("NKMath"):
    language("C++")
    cppdialect("C++17")
    location(".")
```
Declaration du projet, en introduisnt le nom, le languge utilisé, sa version, et l'emplacement
```
    nkentseudependson(
        ["NKCore", "NKPlatform", "NKContainers", "NKMemory"],
        selfexport="NKMath",
        extra_includes=["src", "pch"],
    )
    pchheader("pch/pch.h")
    pchsource("pch/pch.cpp")
```
cette partie gere automatiquement les dependances et indique a quel endroit on peut importer les autres fichiers 

```
    files([
        "src/NKMath/**.cpp",
        "src/NKMath/**.h",
    ])
```
se  sont les fichiers du projets

```
    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
```
Ici c'est ou jenga va placer les fichiers  objets

```
    with filter("system:Windows && options:windows-runtime=uwp"):
        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
        usetoolchain(TC_WINDOWS)
    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
        usetoolchain("xbox-clang")
    with filter("system:macOS"):
        usetoolchain("clang-native")
    with filter("system:Android"):
        # Workaround: disable PCH on Android (NDK r27 + clang 18 + libc++)
        pchheader("")
        pchsource("")
        usetoolchain("android-ndk")
    with filter("system:HarmonyOS"):
        # PCH desactive (NDK OHOS clang, meme contrainte qu'Android)
        pchheader("")
        pchsource("")
        usetoolchain("ohos-ndk")
    with filter("system:Web"):
        usetoolchain("emscripten")
    with filter("system:XboxSeries || system:XboxOne"):
        usetoolchain("xbox-clang")

    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG"])
        optimize("Off")
        symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)

    # Tests unitaires/benchmarks (desktop uniquement)
    with filter("(system:Linux || system:macOS || (system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne)) && !system:Android && !system:iOS || system:Web"):
        with test():
            testfiles(["tests/**.cpp"])
```
Cette partie c'est pour la gestion des filtres de maniere optimiser en fonction des systemes  e qui fait intervenir les configurations, la toolchain et les tests unitaires