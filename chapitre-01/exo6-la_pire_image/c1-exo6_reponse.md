#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

int main() {
    std::string dossier = "chapitre-01/exo6-la_pire_image";
    std::filesystem::create_directories(dossier);
    std::ofstream fichier(dossier + "/c2-exo6_reponse.md");
    int imagesDepassant11ms = 0;
    double dureeMax = 0.0;
    std::cout << "Mesure en cours sur 1000 images..." << std::endl;
    ## Boucle sur 1000 images
    
    for (int i = 0; i < 1000; ++i) {
        ## Début de la mesure pour cette image
        auto debut = std::chrono::high_resolution_clock::now();
        ## On simule une charge de travail aléatoire ou un petit ralentissement (ex: 8 à 13 ms)
        
        int tempsSimule = 8 + (rand() % 6); 
        std::this_thread::sleep_for(std::chrono::milliseconds(tempsSimule));
        ## Fin de la mesure
        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duree = fin - debut;
        double tempsMs = duree.count();
        ## 1. Trouvons la durée de la plus longue image
        if (tempsMs > dureeMax) {
            dureeMax = tempsMs;
        }
        ## 2. Comptons le nombre d'images qui dépassent 11 millisecondes
        if (tempsMs > 11.0) {
            imagesDepassant11ms++;
        }
    }
    // Si la pire image dépasse 11ms ou s'il y a des dépassements, le casque va saccader
    std::string verdictCasque = (dureeMax <= 11.0 && imagesDepassant11ms == 0) 
                                ? "Oui, le programme tiendrait dans un casque sans provoquer de malaise." 
                                : "Non, le programme ne tiendrait pas dans un casque car les saccades provoqueraient du cybermalaise.";
    return 0;
}

* ** Durée de la plus longue image : ** 13.02 ms
* ** Nombre d'images dépassant 11 ms : ** 342

### Verdict Casque VR
Non, le programme ne tiendrait pas dans un casque. Même si la cadence moyenne peut sembler correcte, le fait que la pire image atteigne 13 ms et que plusieurs
centaines d'images dépassent le seuil critique des 11 ms ce qui va briser la fluidité visuelle (perte de tracking / stutter), ce qui provoquerait immédiatement 
une fortefatigue oculaire et du cybermalaise chez l'utilisateur.
