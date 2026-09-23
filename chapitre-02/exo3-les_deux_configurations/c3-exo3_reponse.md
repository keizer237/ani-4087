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

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MaSalle\MaSalle.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.65s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.65s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

## INTERPRETATION DE LA CONSTRUCTION EN DEBUG
Détection des sources : L'outil de build a correctement détecté le code source du projet en affichant le message Found 1 source file(s).
Compilation du code : Le fichier principal a été traité avec succès et sans erreur, validé par la mention [1/1] Compiled: main.cpp.Édition de liens (Linking) : L'étape d'assemblage final s'est déroulée avec succès (Linking...). 
Elle a généré l'application exécutable nommée MaSalle.exe, localisée dans le répertoire de sortie Build\bin\Debug-Windows\MaSalle\.Statut et performance : Le processus global s'est terminé par un succès total (✓ SUCCESS / ✓ Build Successful). 
La compilation effective du code est confirmée par un temps de traitement réel et mesurable de 0.65 seconde.



## INTERPRETATION DE LA CONSTRUCTION EN RELEASE

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

Configuration: Release
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
✓ Built: Build\Bin\Release-Windows\MaSalle\MaSalle.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.20s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.20s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


Configuration et Cible : Le projet a été généré en mode Release pour une architecture Windows x86_64 avec la chaîne d'outils mingw. L'application conserve son type d'application fenêtrée (WINDOWED_APP).
Détection et Compilation : Le compilateur a trouvé le fichier source unique (Found 1 source file(s)) et a validé sa compilation sans erreur ([1/1] Compiled: main.cpp).
Édition de liens (Linking) : L'édition de liens a assemblé le code pour créer l'exécutable final optimisé nommé MaSalle.exe. Il est enregistré dans le répertoire spécifique de production : Build\bin\Release-Windows\MaSalle\.
Statut et Performance : L'opération globale est un succès total (✓ SUCCESS / ✓ Build Successful). Le temps de traitement mesuré est de 0.20 seconde (Time: 0.20s), ce qui est nettement plus rapide que le mode Debug (0.65s) car le compilateur applique des optimisations de code et n'inclut pas les informations lourdes de débogage.


Répertoire de C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\Build\Bin\Release-Windows\MaSalle

23/09/2026  22:05            59 735 MaSalle.exe
               1 fichier(s)           59 735 octets

     Total des fichiers listés :
               2 fichier(s)          119 470 octets
               0 Rép(s)  40 246 657 024 octets libres


### Comparaison des résultats : Mode Debug vs Mode Release

| Caractéristique | Mode Debug | Mode Release |
| :--- | :--- | :--- |
| **Configuration** | `Debug` | `Release` |
| **Fichier cible généré** | `Build\bin\Debug-Windows\MaSalle\MaSalle.exe` | `Build\bin\Release-Windows\MaSalle\MaSalle.exe` |
| **Fichiers sources traités** | 1 (`main.cpp`) | 1 (`main.cpp`) |
| **Taille de l'exécutable** | **59 735 octets** (~59,7 Ko) | **59 735 octets** (~59,7 Ko) |
| **Temps de construction** | **0.65 seconde** | **0.20 seconde** |
| **Statut final** | `✓ SUCCESS` | `✓ SUCCESS` |

### Analyse des observations
Bien que les deux exécutables possèdent strictement la même taille sur le disque pour ce projet minimal, le mode **Release** s'est construit plus de trois fois plus vite (0.20s contre 0.65s). Le compilateur a pu sauter les étapes de génération des tables de symboles lourdes nécessaires à l'analyse pas-à-pas du débogueur.