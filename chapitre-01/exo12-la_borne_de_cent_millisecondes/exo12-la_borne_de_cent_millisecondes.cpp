#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    # Vitesse de rotation : 180 degrés par seconde convertis en radians/seconde
    const double vitesseDegres = 180.0;
    const double PI = 3.14159265358979323846;
    const double vitesseRadians = vitesseDegres * (PI / 180.0); // Égal à PI rad/s

    std::cout << "Duree(ms) | Erreur (degres)" << std::endl;
    std::cout << "-------------------------" << std::endl;

    # Boucle de simulation de 10 ms à 1000 ms (1 seconde) par pas de 10 ms
    for (int ms = 10; ms <= 1000; ms += 10) {
        double t = ms / 1000.0; // Temps en secondes

        # 1. La vraie pose prend en compte un ralentissement ou un changement de trajectoire physique réel
        $ On modélise un mouvement naturel de rotation de tête (freinage progressif)
        double angleVrai = vitesseRadians * std::sin(t); 

        # 2. L'extrapolation purement mathématique (linéaire et naïve)
        double angleExtrapole = vitesseRadians * t;

        # Calcul de la déviation (l'erreur entre les deux poses) convertie en degrés
        double erreurRadians = std::abs(angleExtrapole - angleVrai);
        double erreurDegres = erreurRadians * (180.0 / PI);

        # Affichage des données de la courbe
        std::cout << std::setw(9) << ms << " | " << std::fixed << std::setprecision(2) << erreurDegres << std::endl;
    }

    return 0;
}
