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

# Réponse Exercice 14 - Le filtre Android

### 1. Constat avec la commande "jenga info"
La commande `jenga info` ne permet pas de savoir si le filtre Android s'active ou non. Sa sortie textuelle reste strictement identique, que la condition du filtre soit évaluée à vraie ou à fausse, car elle se contente d'afficher la configuration générale du projet sans appliquer les filtres spécifiques à une plateforme cible non demandée.

### 2. Méthode de vérification de l'activation du filtre
Pour vérifier que le filtre s'active correctement pour Android, il faut exécuter la commande de build ou d'information en forçant la plateforme cible à l'aide de l'argument dédié :
`jenga info --platform android` (ou `jenga build --platform android`).