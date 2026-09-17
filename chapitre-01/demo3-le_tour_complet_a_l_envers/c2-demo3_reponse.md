#include <iostream>
#include <fstream>
#include <filesystem>
#include <cmath>

int main() {
    // 1. Simulation mathématique du problème
    // Un delta minuscule positif (ex: 0.01 rad) sans le filtre du chemin court 
    // correspond en fait à un tour presque complet à l'envers (-2PI + 0.01)
    double delta_minuscule = 0.01; 
    double angle_tour_envers = delta_minuscule - (2 * M_PI); 

    // 2. Création automatique du dossier exact de la Démo 3
    std::filesystem::create_directories("ani-4087/chapitre-01/demo03-le_tour_complet_a_l_envers");

    // 3. Écriture directe des 3 lignes d'analyse demandées dans le rapport
    std::ofstream f("ani-4087/chapitre-01/demo03-le_tour_complet_a_l_envers/c1-demo3_reponse.md");
    
    if (f.is_open()) {
        f << "# Réponses - Démo 3 : Le tour complet à l'envers\n\n";
        f << "## 1. Analyse de la vitesse angulaire\n";
        f << "Sans le forçage du chemin court, un delta minuscule est interprété à l'envers :\n";
        f << "- Le calcul brut prend la trajectoire longue au lieu du complément direct.\n";
        f << "- L'objet effectue une rotation complète dans le sens opposé pour atteindre sa cible.\n";
        f << "- La vitesse angulaire calculée est artificiellement très élevée et inversée.\n";
        
        f.close();
        std::cout << "Simulation terminee. Fichier c1-demo3_reponse.md cree avec succes !\n";
    }

    return 0;
}
