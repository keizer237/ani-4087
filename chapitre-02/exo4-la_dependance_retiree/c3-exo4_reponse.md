C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal>jenga build --config Debug

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

ℹ Found 2 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: main.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp: In function 'int  ║
║ main()':                                                                                     ║
║ C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp:3:2: error:        ║
║ 'helloWorld' was not declared in this scope                                                  ║
║     3 |  helloWorld();                                                                       ║
║       |  ^~~~~~~~~~                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp
✓   [2/2] Compiled: helloworld.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.56s  │
│ Errors: 1  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         1
Time:           0.56s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ MaSalle


## Interpretation
# Réponse Exercice 4 - La dépendance retirée

### Message d'erreur exact
C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp: In function 'int main()':
C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp:3:2: error: 'helloWorld' was not declared in this scope
    3 |  helloWorld();
      |  ^~~~~~~~~~

### Étape de la chaîne de construction
Ce message d'erreur appartient à l'étape de la **compilation**.

### Justification
L'erreur survient lors de l'analyse syntaxique du fichier `main.cpp`. Le compilateur ne trouve aucune déclaration pour la fonction `helloWorld()` dans la portée actuelle (*scope*). Même si la fonction est définie dans un autre fichier, chaque fichier source doit inclure la déclaration (le prototype) des fonctions externes qu'il utilise pour pouvoir être compilé avec succès.