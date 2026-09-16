#include <iostream>
#include <fstream>
#include <filesystem>

int main() {
    // 1. Simulation mathématique des coordonnées (x, y)
    int x1 = 0, y1 = 0; // Cas 1 : Tourne (regarde à gauche) puis avance de 5
    x1 -= 5; 

    int x2 = 0, y2 = 0; // Cas 2 : On avance de 5 vers le haut puis tourne
    y2 += 5;

    // 2. Création automatique du dossier exigé par l'énoncé
    std::filesystem::create_directories("ani-4087/chapitre-01/demo1-les_deux_ordres");

    // 3. Écriture directe des résultats calculés dans le rapport
    std::ofstream f("ani-4087/chapitre-01/demo1-les_deux_ordres/c1-demo1_reponse.md");
    if (f.is_open()) {
        f << "# Réponses - Exercice 2\n\n";
        f << "## 1. Simulation\n";
        f << "- **Cas 1 (Tourner puis Avancer)** : Position (" << x1 << ", " << y1 << "), Orienté Gauche\n";
        f << "- **Cas 2 (Avancer puis Tourner)** : Position (" << x2 << ", " << y2 << "), Orienté Gauche\n\n";
        f << "## 2. Conclusion\n";
        f << "L'orientation reste la même, mais les positions finales sont différentes.\n";
        f << "L'ordre des transformations géométriques n'est pas commutatif.";
        f.close();
        std::cout << "Simulation terminee et fichier cree avec succes !\n";
    }
    return 0;
}
