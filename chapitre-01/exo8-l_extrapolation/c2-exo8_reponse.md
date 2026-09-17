### Exercice 8 : L'extrapolation - Gestion des Cas Limites

### 1. Algorithme d'extrapolation linéaire et angulaire

L'extrapolation de la position se fait par une translation rectiligne uniforme basique. L'orientation est mise à jour en créant un quaternion de variation 
angulaire (Δ𝑞) calculé à partir de l'axe et de la magnitude de la vitesse angulaire, appliqué à l'ancienne orientation via un produit de Hamilton. 

### 2. Traitement du cas limite (Vitesse angulaire nulle)

Pour calculer l'axe unitaire de la rotation, l'algorithme doit normalement diviser chaque composante de la vitesse angulaire par sa norme (magnitude). 

* **Le problème :** Si l'objet n'a aucune rotation, sa norme vaut précisément 0, provoquant un crash critique de l'application (division par zéro).
* **La solution implémentée :** Une condition de sécurité vérifie si la norme est inférieure à un seuil infime (1e-7). Si c'est le cas, le programme ignore
* l'étape de calcul d'axe et conserve directement l'orientation d'origine inchangée. Cela élimine tout risque de division par zéro.
