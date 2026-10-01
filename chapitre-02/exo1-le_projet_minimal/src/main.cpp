// #include <iostream>
// #include <chrono>
// #include <cmath>

// int main() {
// std::cout << "Debut du calcul lourd..." << std::endl;

// Démarrage du chronomètre
// auto start = std::chrono::high_resolution_clock::now();

// Calcul lourd fictif
// double resultat = 0.0;
// for (int i = 0; i < 100000000; ++i) {
// resultat += std::sin(i) * std::cos(i);
//}

// Fin du chronomètre
// auto end = std::chrono::high_resolution_clock::now();
// std::chrono::duration<double, std::milli> temps = end - start;

// std::cout << "Resultat du calcul : " << resultat << std::endl;
// std::cout << "Temps d'execution : " << temps.count() << " ms" << std::endl;

// return 0;
//}

#ifdef __ANDROID__

#include "android_native_app_glue.h"

void android_main(struct android_app *app)
{
    (void)app;
}

#else

#include <iostream>

int main()
{
    std::cout << "MaSalle" << std::endl;
    return 0;
}

#endif