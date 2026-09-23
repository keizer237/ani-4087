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

PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> CD ..
PS C:\Users\Bouetou\ani-4087\chapitre-02> GIT ADD .
git: 'ADD' is not a git command. See 'git --help'.
PS C:\Users\Bouetou\ani-4087\chapitre-02> git add .
warning: in the working copy of 'chapitre-02/exo1-le_projet_minimal/MaSalle.jenga', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of 'chapitre-02/exo1-le_projet_minimal/src/main.cpp', LF will be replaced by CRLF the next time Git touches it
PS C:\Users\Bouetou\ani-4087\chapitre-02> git commit -m "Ajout complet du chapitre 2"
[main 6e9eb11] Ajout complet du chapitre 2
 11 files changed, 178 insertions(+), 14 deletions(-)
 delete mode 100644 chapitre-02/exo1-le_projet_minimal/.jenga/main.cpp
 create mode 100644 chapitre-02/exo1-le_projet_minimal/src/MaClasse.hpp
 delete mode 100644 chapitre-02/exo1-le_projet_minimal/src/helloworld.cpp
 create mode 100644 chapitre-02/exo5-le_define_qui_manque/MonProjet.jenga
 create mode 100644 chapitre-02/exo5-le_define_qui_manque/c3-exo5_reponse.md
PS C:\Users\Bouetou\ani-4087\chapitre-02> git push origin main
Enumerating objects: 37, done.
Counting objects: 100% (37/37), done.
Delta compression using up to 16 threads
Compressing objects: 100% (18/18), done.
Writing objects: 100% (22/22), 26.17 KiB | 4.36 MiB/s, done.
Total 22 (delta 5), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (5/5), completed with 5 local objects.                                                                                               
To https://github.com/keizer237/ani-4087.git
   6c05b25..6e9eb11  main -> main
PS C:\Users\Bouetou\ani-4087\chapitre-02> cd exo1-le_projet_minimal
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
│  ✓ Build Successful                                                             Time: 0.62s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.62s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> Build\bin\Debug-Windows\MaSalle\MaSalle.exe
PROUVE : La condition est FAUSSE, la definition n'est pas appliquee.
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
│  ✓ Build Successful                                                             Time: 0.68s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.68s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> Build\bin\Debug-Windows\MaSalle\MaSalle.exe
PROUVE : La condition est VRAIE, la definition est appliquee !

# Réponse Exercice 6 - Le filtre qui ne sera jamais activé

### Sortie du programme - Test 1 (Condition Fausse)
```text
PROUVE : La condition est FAUSSE, la definition n'est pas appliquee.
```

### Sortie du programme - Test 2 (Condition Vraie)
```text
PROUVE : La condition est VRAIE, la definition est appliquee !
```


### Conclusion de l'exercice 6

Cette manipulation prouve de manière indiscutable l'effet des directives de préprocesseur conditionnelles (`#ifdef`) :

1. **Vérification comportementale :** Les outils d'inspection statiques comme `jenga info` ou `jenga build --verbose` s'avèrent incapables de révéler si une macro interne au code source est active ou non, car leur sortie textuelle reste strictement identique dans les deux situations.
2. **Preuve par le programme :** Seule l'exécution de l'exécutable compilé permet d'obtenir une confirmation fiable. Les affichages obtenus démontrent que le compilateur opère un choix binaire lors de la phase de pré-traitement : il applique ou rejette des blocs entiers de code machine selon que la condition logique associée est évaluée à vraie ou à fausse.