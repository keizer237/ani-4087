#include <iostream>
#include <iomanip>

## représentation  d'un vecteur ou d'un point en 3D
struct Vecteur {
    double x;
    double y;
    double z;
};

Vecteur Avant() {
    return Vecteur{1.0, 0.0, 0.0};
}

Vecteur Haut() {
    return Vecteur{0.0, 1.0, 0.0};
}

Vecteur Droite() {
    return Vecteur{0.0, 0.0, 1.0};
}

##  Fonction utilitaire pour le produit notre scalaire 
double produitScalaire(Vecteur a, Vecteur b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

int main() {
    Vecteur point;

    ## Pour lire nos trois réel (le point envoyé par la plateforme de test)
    if (!(std::cin >> point.x >> point.y >> point.z)) {
        return 1; 
    }

    ## Récupérons nos vecteur
    Vecteur vAvant  = Avant();
    Vecteur vHaut   = Haut();
    Vecteur vDroite = Droite();

    ## Calculons less produits scalaires
    double psAvant  = produitScalaire(point, vAvant);
    double psHaut   = produitScalaire(point, vHaut);
    double psDroite = produitScalaire(point, vDroite);

    ## Pour configurer l'affichage : 
    std::cout << std::fixed << std::setprecision(4);

    ## Affichage sur nos trois lignes 
    std::cout << psAvant << "\n";
    std::cout << psHaut << "\n";
    std::cout << psDroite << "\n";

    return 0;
}
