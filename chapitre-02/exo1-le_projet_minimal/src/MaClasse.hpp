#pragma once
#include <iostream>

#ifdef MON_PROPRE_DEFINE
// Si le define est posé : classe complète
class MaClasse {
public:
    void afficher() {
        std::cout << "Le define est POSE : Classe complete active." << std::endl;
    }
};
#else
// Si le define n'est pas posé : coquille vide
class MaClasse {};
#endif