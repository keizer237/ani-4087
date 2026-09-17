#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>

int main() {
    ## Valeur de référence de la pire image globale (ex: mesurée à l'exo précédent)
    double pireImageGlobaleMs = 13.02; 
    ##  MESURE DU RENDU SEUL 
    auto debutRendu = std::chrono::high_resolution_clock::now();
    
    ## Simulation de notre rendu de l'écran seul (effacement/dessin brut)
    std::this_thread::sleep_for(std::chrono::milliseconds(9)); 
    
    auto finRendu = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> dureeRendu = finRendu - debutRendu;
    
    ## Rendu seul isolé
    double renduSeulMs = dureeRendu.count(); 

    ##  CALCULS ET ESTIMATIONS 
    ## Le coût si le rendu est fait deux fois (Scénario Casque VR Stéréoscopique)
    double renduDoubleMs = renduSeulMs * 2.0; 
    
    ## Ce qu'il reste pour la logique de l'application
    double resteLogiqueMs = pireImageGlobaleMs - renduSeulMs; 
    if (resteLogiqueMs < 0) resteLogiqueMs = 0;

    ##  CRÉATION DU RAPPORT 
    if (fichier.is_open()) {
        fichier << "# Rapport de Performance - Le coût du doublement\n\n";
        fichier << "* **Mesure (Rendu seul) :** " << renduSeulMs << " ms\n";
        fichier << "* **Estimation (Rendu fait deux fois) :** " << renduDoubleMs << " ms\n";
        fichier << "* **Ce qu'il resterait pour le reste (Logique) :** " << resteLogiqueMs << " ms\n\n";
        
        fichier << "### Conclusion\n";
        if (renduDoubleMs > 11.0) {
            fichier << "Le rendu graphique seul, lorsqu'il est doublé pour les deux yeux (" << renduDoubleMs 
                    << " ms), dépasse déjà le seuil critique des 11 ms requis pour un casque. "
                    << "C'est donc le **rendu graphique** qu'il faudrait réduire et optimiser en priorité (par exemple en réduisant le nombre de polygones ou la complexité des shaders), "
                    << "car la logique interne ne consomme que " << resteLogiqueMs << " ms.";
        } else {
            fichier << "Le doublement du rendu graphique consomme " << renduDoubleMs << " ms. "
                    << "Si le programme sature, c'est la partie **logique/calculs** (" << resteLogiqueMs 
                    << " ms) qu'il faudrait réduire pour regagner de la fluidité.";
        }

        fichier.close();
        std::cout << "Exercice 7 résolu ! Fichier créé avec succès dans : " << dossier << std::endl;
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier de rapport." << std::endl;
    }

    return 0;
}
