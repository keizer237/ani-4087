#include <iostream>

# Pour stocker les dimensions en 3D (Largeur, Profondeur, Hauteur)
struct Dimensions {
    double largeur;
    double profondeur;
    double hauteur;
};

int main() {
    # Initialisation des dims
    Dimensions salle = {8.0, 6.0, 3.0};

    # Initialisation des dims reelles
    Dimensions table = {1.2, 0.8, 0.75};

    # Variable pour stocker le multiplicateur d'échelle
    double facteurEchelle;

    # Lecture du facteur depuis l'entrée standard
    std::cin >> facteurEchelle;

    Dimensions salleMiseAEchelle;
    salleMiseAEchelle.largeur = salle.largeur * facteurEchelle;
    salleMiseAEchelle.profondeur = salle.profondeur * facteurEchelle;
    salleMiseAEchelle.hauteur = salle.hauteur * facteurEchelle;

    Dimensions tableMiseAEchelle;
    tableMiseAEchelle.largeur = table.largeur * facteurEchelle;
    tableMiseAEchelle.profondeur = table.profondeur * facteurEchelle;
    tableMiseAEchelle.hauteur = table.hauteur * facteurEchelle;

    # Affichons les dimensions de la salle
    std::cout << salleMiseAEchelle.largeur << " " 
              << salleMiseAEchelle.profondeur << " " 
              << salleMiseAEchelle.hauteur << std::endl;

    # Affichons les dimensions du mobilier
    std::cout << tableMiseAEchelle.largeur << " " 
              << tableMiseAEchelle.profondeur << " " 
              << tableMiseAEchelle.hauteur << std::endl;

    return 0;
}
