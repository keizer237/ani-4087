#include <iostream>
#include <cmath>

struct Quaternion {
    double x, y, z, w;
};

## Calcule de la vitesse angulaire moyenne
double obtenirVitesse(Quaternion q1, Quaternion q2, double dt, bool avecForcage) {
    # Calcul du produit scalaire (proximité entre les deux quaternions)
    double dot = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
    
    # Forçage du chemin court : si négatif, on inverse les signes
    if (avecForcage && dot < 0.0) {
        dot = -dot; 
    }
    
    # Sécurité pour la fonction acos
    if (dot > 1.0) dot = 1.0;
    if (dot < -1.0) dot = -1.0;
    
    # Formule mathématique simplifiée de la vitesse angulaire
    double angle = std::acos(dot);
    return (2.0 * angle) / dt;
}

int main() {
    Quaternion q1, q2;
    double dt;

    # Lecture des entrées de la console
    std::cin >> q1.x >> q1.y >> q1.z >> q1.w;
    std::cin >> q2.x >> q2.y >> q2.z >> q2.w;
    std::cin >> dt;

    # Calculs avec et sans forçage
    double resAvec = obtenirVitesse(q1, q2, dt, true);
    double resSans = obtenirVitesse(q1, q2, dt, false);

    # Affichage des résultats
    std::cout << resAvec << " " << resSans << std::endl;

    return 0;
}

### Exercice 9 : Le chemin court

### 1. Deux quaternions absurdes sans forçage

* **Quaternion 1 (q1) :** 0 0 0 1 (Position de départ, pas de rotation)
* **Quaternion 2 (q2) :** 0 0 0 -1 (Géométriquement, c'est exactement la même position)

### 2. Pourquoi le résultat devient absurde ?

En 3D, un quaternion possède une double identité : q et -q représentent exactement le même angle visuel. 

* **Avec le forçage :** Le code comprend que l'objet n'a pas bougé. La distance est de 0 et la vitesse est de 0 rad/s.
* **Sans le forçage :** Le code fait une erreur de calcul. Il croit que l'objet a fait un tour complet sur lui-même à toute vitesse pendant le temps dt, alors qu'il est resté parfaitement immobile.
