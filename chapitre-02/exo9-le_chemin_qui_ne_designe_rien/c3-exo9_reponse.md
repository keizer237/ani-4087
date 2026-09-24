# Test 1 avec jenga info
PS C:\Users\Bouetou\ani-4087\chapitre-02> cd exo1-le_projet_minimal
PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> jenga info

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

========================= Jenga Workspace: MaSalleWks ==========================

Location: C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal
Entry file: C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\MaSalle.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: 
Target Architectures: 


Projects
------------------------------------------------------------
Name      Kind          Language   Test   External
==================================================
MaSalle   WindowedApp   C++        No     No


Available Toolchains
------------------------------------------------------------
Name       Family   Target OS   Arch     Env  
==============================================
host-gcc   gcc      Windows     x86_64   mingw
mingw      gcc      Windows     x86_64   mingw


Daemon
------------------------------------------------------------
Status: Not running

# Test 2 avec jenga build --config debug
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
│  ✓ Build Successful                                                             Time: 2.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.05s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


# Réponse Exercice 9 - Le chemin qui ne désigne rien

### Comparaison des commandes

* **`jenga info` (Instantané)** : Cette commande effectue une analyse purement théorique. Elle valide la syntaxe du projet sans vérifier l'existence réelle des fichiers ou des dossiers sur le disque dur. Elle induit en erreur en affichant que tout est correct malgré les chemins fictifs.
* **`jenga build` (2.05 secondes)** : Cette commande est concrète et se confronte à la réalité. Elle scanne physiquement le projet et indique textuellement **`Found 1 source file(s)`**, ignorant d'elle-même le fichier fantôme qui n'existe pas.

### Conclusion : Lequel fait gagner du temps ?

C'est la commande **`jenga build`** qui fait gagner du temps lors du développement.

Bien que `jenga info` soit plus rapide à s'exécuter, il est trompeur. Si une faute de frappe est commise dans un chemin d'accès, `jenga info` ne la signalera pas, ce qui peut faire perdre de nombreuses heures de recherche. En revanche, `jenga build` permet de détecter immédiatement une anomalie en affichant le nombre exact de fichiers sources réellement détectés sur le disque.