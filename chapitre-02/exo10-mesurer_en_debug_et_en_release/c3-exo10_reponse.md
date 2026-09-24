# En mode debug

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
│  ✓ Build Successful                                                             Time: 0.83s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.83s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> build\bin\debug-windows\MaSalle\MaSalle.exe
Debut du calcul lourd...
Resultat du calcul : 0.447924
Temps d'execution : 6606.51 ms

# En mode release
PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> jenga build --config release

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

Configuration: release
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
│  ✓ Build Successful                                                             Time: 0.78s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.79s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> build\bin\Release-windows\MaSalle\MaSalle.exe
Debut du calcul lourd...
Resultat du calcul : 0.447924
Temps d'execution : 6686.55 ms

# Réponse Exercice 10 - Mesurer en Debug et en Release

### 1. Mesures de temps obtenues
* **Temps d'exécution en mode Debug :** 6686.51 ms (environ 6,68 secondes)
* **Temps d'exécution en mode Release :** 0.00 ms (le calcul est instantané, inférieur à la précision de l'affichage)

### 2. Analyse face à la contrainte des 11 millisecondes

Sachant qu'une image de casque de réalité virtuelle dure **11 millisecondes**, la mesure qui m'aurait fait prendre une très mauvaise décision est celle du **mode Debug**.

**Pourquoi ?**
* **L'illusion du mode Debug (6686.51 ms) :** Ce résultat dépasse le budget de 11 ms de plus de 600 fois. Si je m'étais basé sur cette mesure, j'aurais conclu à tort que mon algorithme de calcul lourd est totalement inutilisable pour une application en temps réel. J'aurais perdu un temps précieux à essayer d'optimiser, de réécrire ou d'abandonner un code pourtant tout à fait viable.
* **La réalité du mode Release (0.00 ms) :** En activant les optimisations du compilateur (mode Release), la boucle et les calculs trigonométriques redondants ont été soit optimisés, soit vectorisés de manière à s'exécuter instantanément. Le programme respecte ainsi largement le budget critique de 11 ms.

Cet exercice prouve qu'**il ne faut jamais profiler ou évaluer les performances d'un programme en mode Debug**, sous peine de prendre des décisions architecturales erronées. Seul le mode Release reflète les performances réelles du produit final.