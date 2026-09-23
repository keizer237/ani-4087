#include <iostream>

// Décommentez la ligne ci-dessous pour le Test 2 (Condition vraie)
#define MON_PROPRE_DEFINE

int main() {
#ifdef MON_PROPRE_DEFINE
    std::cout << "PROUVE : La condition est VRAIE, la definition est appliquee !" << std::endl;
#else
    std::cout << "PROUVE : La condition est FAUSSE, la definition n'est pas appliquee." << std::endl;
#endif
    return 0;
}