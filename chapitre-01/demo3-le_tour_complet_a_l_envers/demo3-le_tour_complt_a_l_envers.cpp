#include <iostream>
#include <fstream>
#include <filesystem>

int main() {
    // 1. Création automatique du dossier exact demandé par l'exercice
    std::string cheminDossier = "chapitre-01/demo03-le_tour_complet_a_l_envers";
    std::filesystem::create_directories(cheminDossier);
    std::ofstream fichier(cheminDossier + "/c2-demo3_reponse.md");
    if (fichier.is_open()) {
        fichier << "Sans le forçage du chemin court, un delta minuscule est interprété à l'envers.\n";
        fichier << "Le calcul brut prend la trajectoire longue au lieu du complément direct.\n";
        fichier << "L'objet effectue une rotation complète dans le sens opposé pour atteindre sa cible.\n";
        fichier.close();
        std::cout << "Fichier genere avec succes !" << std::endl;
    } else {
        std::cerr << "Erreur lors de la creation du fichier." << std::endl;
    }
    return 0;
}
