# Réponse Exercice 7 - Les dépendances du moteur

### 1. Groupe 1 : Celles dont le nom suffit à deviner le rôle
Ces modules gèrent les fonctionnalités standards et vitales du système via des conventions de nommage explicites :
* **NKWindow** : Gère la création de la fenêtre d'affichage, le contexte graphique et les interactions de base avec l'OS.
* **NKMemory** : Système d'allocation et de gestion personnalisée de la mémoire vive pour éviter la fragmentation.
* **NKThreading** : Gère le multi-threading et la répartition des tâches sur les différents cœurs du processeur.
* **NKLog** : Système de journalisation (logs) pour le débogage et le suivi des événements du moteur.
* **NKMath** : Bibliothèque mathématique indispensable (vecteurs, matrices, transformations géométriques 3D).
* **NKInput** : Capture et centralise les entrées utilisateur (clavier, souris, manettes).
* **NKTime** : Gestion du temps, calcul du Delta Time et stabilisation du framerate.

### 2. Groupe 2 : Celles dont on a une idée sans certitude (Précisions technologiques)
Ces modules demandent une intuition technique qui se confirme par l'étude de l'architecture des moteurs portables :
* **NKRHI (Render Hardware Interface)** : Couche d'abstraction cruciale entre le moteur et les API graphiques bas niveau (Vulkan, DirectX, Metal). Elle garantit la portabilité du rendu.
* **NKSL (NK Shader Language)** : Langage de shader interne et intermédiaire propre au moteur, servant de pivot avant la traduction vers les backends spécifiques.
* **NKGlad** : Chargeur de pointeurs de fonctions OpenGL, basé sur la bibliothèque standard très répandue GLAD.
* **NKFileSystem** : Abstraction de la gestion des fichiers et des assets de manière multiplateforme.
* **NKResources** : Gestionnaire de ressources (cache, chargement et libération des textures/meshs en mémoire).

### 3. Groupe 3 : Celles dont on ne sait rien (Analyse fine de la chaîne de shaders)
Ces modules nécessitent une expertise pointue dans le domaine du rendu 3D moderne. Ils forment ensemble le pipeline de compilation des shaders :
* **NKGLSlang** : Module chargé de l'analyse et de la compilation du code GLSL (le langage de shader d'OpenGL) vers un format intermédiaire.
* **NKSPIRVCross** : Outil de réflexion et de conversion du bytecode SPIR-V (format intermédiaire de Vulkan) vers d'autres langages cibles (HLSL, MSL, GLSL). Il complète parfaitement NKSL et NKGLSlang pour adapter le code source des shaders au backend graphique actif.

---

### Conclusion générale
Cette taxonomie met en évidence une règle claire en ingénierie logicielle : les composants génériques (gestion mémoire, fenêtrage, entrées) adoptent des noms standardisés immédiatement identifiables. À l'inverse, les composants liés à des technologies graphiques pointues (RHI, GLSL, SPIR-V) exigent une connaissance approfondie du domaine pour être décodés, car ils reflètent la complexité de la portabilité matérielle moderne.