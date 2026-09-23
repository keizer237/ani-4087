
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

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: main.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp: In function 'int  ║
║ main()':                                                                                     ║
║ C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp:5:14: error:       ║
║ 'class MaClasse' has no member named 'afficher'                                              ║
║     5 |     instance.afficher(); // Cette ligne va poser problème si la classe est vide !    ║
║       |              ^~~~~~~~                                                                ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\src\main.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.44s  │
│ Errors: 1  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         1
Time:           0.44s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ MaSalle




# Réponse Exercice 5 - La define qui manque

### 1. Message obtenu SANS le define (Échec)
error: 'class MaClasse' has no member named 'afficher'
   5 |     instance.afficher(); // Cette ligne va poser problème si la classe est vide !
     |              ^~~~~~~~
Statut : X FAILURE (Time: 0.44s)


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
│  ✓ Build Successful                                                             Time: 0.63s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.63s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


# Réponse Exercice 5 - La define qui manque

### 1. Message obtenu SANS le define (Échec)
```text
Compilation Error: main.cpp
error: 'class MaClasse' has no member named 'afficher'
   5 |     instance.afficher();
     |              ^~~~~~~~
Status: X FAILURE (Time: 0.44s)
```

### 2. Message obtenu AVEC le define (Succès)
```text
Found 1 source file(s)
[1/1] Compiled: main.cpp
Linking...
Built: Build\bin\Debug-Windows\MaSalle\MaSalle.exe
✓ Build Successful (Time: 0.63s)
Status: ✓ SUCCESS
```

### 3. Diagnostic sans cet exercice
Sans avoir réalisé cette manipulation, une erreur de type *"class has no member named..."* aurait été très difficile à diagnostiquer pour un débutant. En temps normal, on a tendance à chercher une faute de frappe dans le nom de la fonction ou à vérifier si le fichier est bien sauvegardé. 

Cet exercice permet de comprendre qu'un bloc de code entier peut être masqué au compilateur à cause d'une simple directive de préprocesseur (`#ifdef`) non satisfaite. Le problème ne venait pas de la syntaxe, mais d'une configuration manquante.


### Conclusion générale

Ces exercices démontrent l'importance de comprendre chaque étape de la chaîne de compilation pour résoudre efficacement les bugs. 

Sans ce TP, j'aurais facilement diagnostiqué **l'erreur de l'exercice 4**, car le message indique clairement qu'une fonction est manquante (un grand classique). En revanche, j'aurais été incapable de résoudre **l'erreur de l'exercice 5**. Elle est redoutable car la méthode est visible à l'écran, mais masquée au compilateur à cause du `#ifdef`. Ce TP m'a appris à vérifier les macros de configuration avant de douter de mon code.