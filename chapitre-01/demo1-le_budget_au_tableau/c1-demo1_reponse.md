### Exercice : Le budget au tableau

### 1. Répartition à l'échelle des 20 millisecondes (barre de 20 cm)

Pour représenter visuellement notre budget total de 20 ms sur une ligne de 20 cm (où 1 cm correspond exactement à 1 ms), voici le découpage géométrique des 
étapes du pipeline : 
- **1cm ~1 ms**
* **Lecture des entrées (Inputs / Capteurs) :** 1 cm 
* **Calculs de la logique et de l'IA :** 7 cm (~7 ms)
* **Moteur physique et détection des collisions :** 4 cm 
* **Préparation du rendu (CPU / Draw Calls) :** 5 cm 
* **Marge / Temps disponible restant pour notre code :** 3 cm 

### 2. Ce qui reste pour le code et constat

Une fois toutes ces étapes fondamentales exécutées par le système, on remarque qu'il ne reste qu'une infime portion de temps ( ~**3 millisecondes**) 
pour exécuter le script général de notre application. 

**Réaction et analyse :**
Ce graphique met en évidence la contrainte extrême du développement en temps réel. Si un seul calcul ou un script d'intelligence artificielle est mal optimisé 
et prend 4 ms de trop, l'application dépasse son budget global. L'image saute, le système subit une latence ("framerate drop") et l'illusion d'interactivité 
est brisée. En art numérique et en IA interactive, l'optimisation n'est pas un confort technique, c'est ce qui permet à l'expérience d'exister de manière fluide.
