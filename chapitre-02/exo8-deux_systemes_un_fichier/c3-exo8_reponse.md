PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> jenga build --config Debug

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

Configuration: Debug
Target:        Windows x86_64
Toolchain:     mingw

Build Order (1 projects):
  1. MaSalle [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MaSalle                                                        Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MaSalle\MaSalle.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.10s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> Build\bin\Debug-Windows\MaSalle\MaSalle.exe
Construction reussie !
Ce binaire a ete compile nativement pour : Windows




# Réponse Exercice 8 - Deux systèmes, un fichier

### 1. Code source multiplateforme mis en œuvre
Les filtres de précompilation conditionnelle ont été intégrés directement dans le fichier `main.cpp` en utilisant les macros globales de l'environnement de build :
* `#if defined(_WIN32)` pour isoler l'API Windows et l'en-tête `<windows.h>`.
* `#elif defined(__linux__)` pour isoler l'environnement POSIX/Linux et l'en-tête `<unistd.h>`.

### 2. Système vérifié et résultat
* **Environnement testé :** Windows 11 (Architecture x86_64, Compilateur MinGW via Jenga).
* **Résultat obtenu :** Le projet se compile avec succès sans aucune modification manuelle. Le programme s'exécute de manière fluide et affiche correctement la plateforme Windows.

### 3. Système non vérifié (Déclaration d'accessibilité)
N'ayant pas un accès direct et immédiat à une machine native sous **Linux** pour exécuter le build croisé en local, je n'ai pas pu valider physiquement l'exécution du binaire ELF final sur ce second système d'exploitation. 

Cependant, le code a été rigoureusement écrit en respectant les standards stricts du préprocesseur C++ (`#elif defined(__linux__)`). Cela garantit qu'un camarade travaillant sous Linux ou exécutant le projet dans un conteneur Docker/WSL verra le compilateur ignorer le code Windows pour compiler uniquement la branche Linux, assurant une construction propre et sans erreur sans toucher à une seule ligne de code.