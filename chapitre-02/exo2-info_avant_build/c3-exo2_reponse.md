### Sortie de la commande **jenga info**

```text
C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal>jenga info

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
```

### Ce qu'il nous apprend de plus:
Il nous precise qu'il ya un seul projet (MaSalle)de type windoewedApp ecrit en c++. Pas de test configures(Test: NO), pas de dependances externe. 
A vailable Toolchains: deux chaines de compilation disponibles pour compiler de projet: host-gcc= GCC, cible windos, Architecture x86_64, environnement mingw.
Status Not running: le demon de jenga (le processus qui gere les buils en arriere-plan cache) n'est pas actif actuellement.