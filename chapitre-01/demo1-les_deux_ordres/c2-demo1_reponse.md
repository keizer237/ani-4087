#include <iostream>
#include <fstream>
#include <filesystem>

int main() {
    ##  coordonnées (x, y)
    int x1 = 0, y1 = 0; // Cas 1 : Tourne (regarde à gauche) puis avance de 5
    x1 -= 5; 
    # Cas 2 : On avance de 5 vers le haut puis tourne
    int x2 = 0, y2 = 0; 
    y2 += 5;
    ##  Écriture directe des résultats calculés dans le rapport
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

## RAPPORT :
### Cas 1 : "Je tourne puis j'avance"
- **Étape 1 (Tourner à gauche) :** L'orientation change vers la **Gauche**. Position : `(0, 0)`.
- **Étape 2 (Avancer de 5 pas) :** L'objet se déplace sur l'axe X négatif.
- **Résultat Final :** Position **(-5, 0)**, Direction : **Gauche**.

### Cas 2 : "J'avance puis je tourne"
- **Étape 1 (Avancer de 5 pas) :** L'objet progresse sur l'axe Y positif. Position : `(0, 5)`.
- **Étape 2 (Tourner à gauche) :** L'orientation finale change vers la **Gauche**.
- **Résultat Final :** Position **(0, 5)**, Direction : **Gauche**.

## 2. Conclusion Mathématique

L'orientation finale est identique (`Gauche`), mais les coordonnées bien distinct :
- Cas 1 : `(-5, 0)` 
- Cas 2 : `(0, 5)` 
L'ordre des instructions change complètement le résultats final
Cela prouve de façon définitive que les transformations géométriques (les matrices de rotation et de translation) ne sont **pas commutatives**.
