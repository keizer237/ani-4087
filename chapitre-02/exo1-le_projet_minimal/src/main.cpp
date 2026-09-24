#include <iostream>

// --- SECTION MULTIPLATEFORME (PRÉPROCESSEUR) ---
#if defined(_WIN32) || defined(_WIN64)
    // Bibliothèques et configurations spécifiques à Windows
    #include <windows.h>
    #define SYSTEM_NAME "Windows"
#elif defined(__linux__)
    // Bibliothèques et configurations spécifiques à Linux
    #include <unistd.h>
    #define SYSTEM_NAME "Linux"
#else
    #define SYSTEM_NAME "Système inconnu"
#endif

int main() {
    std::cout << "Construction reussie !" << std::endl;
    std::cout << "Ce binaire a ete compile nativement pour : " << SYSTEM_NAME << std::endl;

    // Exemple d'utilisation d'une fonction système selon l'OS
#if defined(_WIN32) || defined(_WIN64)
    Sleep(1000); // Fonction Windows (pause de 1000 ms)
#elif defined(__linux__)
    sleep(1);    // Fonction Linux (pause de 1 seconde)
#endif

    return 0;
}