#include "NKImage/Core/NkImage.h"
#include "NKTime/NkChrono.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

using namespace nkentseu;

namespace {

    struct Filtre {
        const char *nom;
        NkResizeFilter filtre;
        const char *fichier;
    };

    const int kRepetitions = 20;

    // Nombre de pixels qui diffèrent sur au moins un canal.
    long long Differences(const NkImage &a, const NkImage &b) {
        long long total = 0;
        for (int y = 0; y < a.Height(); ++y) {
            for (int x = 0; x < a.Width(); ++x) {
                const auto pa = a.GetPixel(x, y);
                const auto pb = b.GetPixel(x, y);
                if (pa.r != pb.r || pa.g != pb.g || pa.b != pb.b || pa.a != pb.a) {
                    ++total;
                }
            }
        }
        return total;
    }

} // namespace

int main() {
    // La photo de départ
    NkImage photo;
    if (!photo.Load("mur.jpeg")) {
        std::cerr << "Erreur : impossible de charger mur.jpeg.\n";
        return 1;
    }

    // La source : la photo mise en 2048 x 2048
    NkImage source = photo.Resize(2048, 2048);
    if (!source.IsValid() || source.Width() != 2048 || source.Height() != 2048) {
        std::cerr << "Erreur : la source 2048 x 2048 n'a pas pu etre creee.\n";
        return 1;
    }

    const Filtre filtres[4] = {
        { "NK_NEAREST",  NkResizeFilter::NK_NEAREST,  "nearest.png"  },
        { "NK_BILINEAR", NkResizeFilter::NK_BILINEAR, "bilinear.png" },
        { "NK_BICUBIC",  NkResizeFilter::NK_BICUBIC,  "bicubic.png"  },
        { "NK_LANCZOS3", NkResizeFilter::NK_LANCZOS3, "lanczos3.png" }
    };

    NkImage resultats[4];
    double moyennes[4] = { 0.0, 0.0, 0.0, 0.0 };

    // Vingt réductions par filtre, et la moyenne en microsecondes
    for (int i = 0; i < 4; ++i) {
        double somme = 0.0;
        for (int n = 0; n < kRepetitions; ++n) {
            NkChrono chrono;
            NkImage reduite = source.Resize(256, 256, filtres[i].filtre);
            somme += chrono.Elapsed().ToMicroseconds();
            if (n == kRepetitions - 1) {
                resultats[i] = std::move(reduite);
            }
        }
        moyennes[i] = somme / kRepetitions;

        if (!resultats[i].SavePNG(filtres[i].fichier)) {
            std::cerr << "Erreur : " << filtres[i].fichier << " n'a pas ete ecrit.\n";
        }
    }

    // La comparaison, pixel par pixel, avec le bilinéaire (indice 1)
    std::ofstream sortie("mesures.txt");
    for (int i = 0; i < 4; ++i) {
        const long long diff = Differences(resultats[i], resultats[1]);
        const long long us = std::llround(moyennes[i]);

        const std::string ligne = std::string(filtres[i].nom) + " : " + std::to_string(us)
                                + " us, differences : " + std::to_string(diff);
        sortie << ligne << "\n";
        std::cout << ligne << "\n";
    }

    return 0;
}
