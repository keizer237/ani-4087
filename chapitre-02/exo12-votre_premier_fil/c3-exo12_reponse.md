# Réponse Exercice 12 - Votre premier fil

### 1. Structure du fichier de projet prévisionnel
Le fichier de configuration Jenga a été enrichi pour planifier l'ensemble du développement futur de l'application. Chaque jalon important est documenté par un bloc de commentaires décrivant les intégrations à venir (du Sprint 3 au Sprint 17) :
* **Sprint 3 & 4** : Gestion des fenêtres/événements (`NKWindow`) et mise en place du rendu graphique (`NKRHI`).
* **Sprints intermédiaires (5 à 15)** : Gestion des ressources multimédias, de la stéréoscopie XR, des cadences d'affichage, des interactions et du multi-utilisateur.
* **Sprint 16 & 17** : Finalisation, phase de build, livraison du projet et approfondissements.

### 2. Processus de manipulation (Décochage progressif)
Chaque commentaire sert de balise structurelle. Au fur et à mesure que nous avancerons dans le projet, ces blocs de commentaires seront "décochés" (activés) un par un pour se transformer en véritables instructions de compilation et de chaînage de modules graphiques, sans perturber le code existant.

### 3. Conclusion sur l'organisation en "fil conducteur"
Cette méthode offre une vision à long terme de l'architecture logicielle. Au lieu de recréer un fichier de projet pour chaque TP, nous faisons évoluer un unique fil conducteur à travers les sprints. Cela évite les régressions et modélise fidèlement la gestion de projet en ingénierie logicielle.