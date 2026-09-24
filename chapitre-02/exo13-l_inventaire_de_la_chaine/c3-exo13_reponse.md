PS C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal> jenga info -v

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

[Loader] Loading workspace from C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\MaSalle.jenga
[Loader] Workspace 'MaSalleWks' post-processed.
========================= Jenga Workspace: MaSalleWks ==========================

Location: C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal
Entry file: C:\Users\Bouetou\ani-4087\chapitre-02\exo1-le_projet_minimal\MaSalle.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: 
Target Architectures: 


Projects
------------------------------------------------------------
Name           Kind         Language   Test   External
======================================================
MaSalle        ConsoleApp   C++        No     No
27_nk_window   ConsoleApp   C++        No     No


Available Toolchains
------------------------------------------------------------
Name       Family   Target OS   Arch     Env  
==============================================
host-gcc   gcc      Windows     x86_64   mingw
mingw      gcc      Windows     x86_64   mingw


Daemon
------------------------------------------------------------
Status: Not running


System
------------------------------------------------------------
Host OS: Windows
Host Architecture: x86_64
Host Environment: msvc
Host Triple: x86_64-pc-windows-msvc
Python: 3.12.2 (tags/v3.12.2:6abddd9, Feb  6 2024, 21:26:36) [MSC v.1937 64 bit (AMD64)]
Jenga version: 2.8.0

# Réponse Exercice 13 - Inventaire de la chaîne de compilation

### 1. Tableau complet des chaînes de compilation (Available Toolchains)

| Name | Family | Target OS | Arch | Env | Statut sur la machine |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **host-gcc** | gcc | Windows | x86_64 | mingw | **✓ Présent** |
| **mingw** | gcc | Windows | x86_64 | mingw | **✓ Présent** |

### 2. Inventaire : Ce qui est présent et ce qui manque

* **Ce qui est présent :** Les chaînes de compilation basées sur GCC pour Windows (**`host-gcc`** et **`mingw`**) sont pleinement disponibles et opérationnelles dans l'environnement `mingw` pour l'architecture `x86_64`. Ce sont elles qui assurent la construction réussie de vos projets depuis le début du TP.
* **Ce qui manque :** Toutes les autres toolchains spécifiques ou cross-compilateurs tiers (tels que *Clang/LLVM*, *MSVC natif*, ou *Emscripten WebAssembly*) ne sont pas détectés ou installés dans le PATH de l'environnement Jenga actuel.

### 3. Informations système complémentaires
* **Host OS :** Windows
* **Host Architecture :** x86_64
* **Host Environment :** msvc
* **Jenga Version :** 2.8.0