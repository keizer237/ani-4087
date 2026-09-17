### Exercice 9 : Le chemin court

### 1. Deux quaternions absurdes sans forçage

* **Quaternion 1 (q1) :** 0 0 0 1 (Position de départ, pas de rotation)
* **Quaternion 2 (q2) :** 0 0 0 -1 (Géométriquement, c'est exactement la même position)

### 2. Pourquoi le résultat devient absurde ?

En 3D, un quaternion possède une double identité : q et -q représentent exactement le même angle visuel. 

* **Avec le forçage :** Le code comprend que l'objet n'a pas bougé. La distance est de 0 et la vitesse est de 0 rad/s.
* **Sans le forçage :** Le code fait une erreur de calcul. Il croit que l'objet a fait un tour complet sur lui-même à toute vitesse pendant le temps dt, alors qu'il est resté parfaitement immobile.
