#include <iostream>
#include <fstream>
#include <filesystem>

// Structure pour une matrice 2x2 simple (pour l'exemple)
struct Matrice2x2 {
    double a, b, c, d;

    // Fonction qui fait l'inversion "qui ment"
    Matrice2x2 inverser() {
        // Calcul du déterminant
        double det = (a * d) - (b * c);

        // Si le déterminant est 0, la matrice est dégénérée
        if (det == 0.0) {
            // Rendre l'identité, SANS AUCUN MESSAGE (pas de cout, pas d'erreur)
            return {1.0, 0.0, 0.0, 1.0};
        }

        // Sinon, on fait l'inversion normale
        return {d / det, -b / det, -c / det, a / det};
    }
};

int main() {
    // Exemple avec une matrice dégénérée (lignes proportionnelles)
    Matrice2x2 matDegeree = {2.0, 4.0, 1.0, 2.0};
    
    // On lance l'inversion
    Matrice2x2 resultat = matDegeree.inverser();

    // --- CRÉATION DU DOSSIER ET DU RAPPORT SUR GITHUB ---
    std::filesystem::create_directories("ani-4087/chapitre-01/demo2-1_inversion_qui_ment");
    std::ofstream f("ani-4087/chapitre-01/demo2-1_inversion_qui_ment/c1-demo2_reponse.md");
    
    if (f.is_open()) {
        f << "# Réponses - Démo 2 : L'inversion qui ment\n\n";
        f << "## 1. Comportement du code\n";
        f << "Lorsque la matrice est dégénérée, le programme renvoie la matrice identité sans aucun message d'erreur.\n\n";
        f << "## 2. Effet dans le casque de VR\n";
        f << "Dans un casque, cela provoquerait un comportement étrange pour l'utilisateur :\n";
        f << "- La caméra revient instantanément à l'origine (position 0,0,0).\n";
        f << "- Il n'y a plus aucune rotation.\n";
        f << "- Rien ne l'explique car aucun message de log ou d'erreur n'est généré.\n";
        f.close();
        
        std::cout << "Simulation terminee. Fichier c1-demo2_reponse.md cree avec succes !\n";
    }

    return 0;
}
