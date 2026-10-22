// BLOC À INTÉGRER à la salle complète pour l'exercice de dérive.
#include "NKEvent/NkEventDispatcher.h"
#include "NKTime/NkChrono.h"
#include <cmath>
#include <cstdio>

namespace nkentseu {

class MesureDeriveProvoquee {
public:
    // Sensibilité en radians par compte du capteur : conservez la même valeur
    // pendant toute la mesure.
    explicit MesureDeriveProvoquee(float32 sensibilite = 0.002f)
        : mSensibilite(sensibilite) {}

    void UneImage() {
        // Version volontairement fautive : on rejoue à chaque image la valeur
        // brute conservée par le module, sans accumuler les événements.
        mLacet += static_cast<float32>(NkInput.MouseRawDeltaX()) * mSensibilite;
        mTangage += static_cast<float32>(NkInput.MouseRawDeltaY()) * mSensibilite;
        ++mImages;
    }

    NkVec3f Direction() const {
        return NkVec3f(
            -std::sin(mLacet) * std::cos(mTangage),
             std::sin(mTangage),
            -std::cos(mLacet) * std::cos(mTangage));
    }

    float32 LacetDegres() const { return mLacet * 180.0f / 3.14159265358979323846f; }

    // À appeler une fois par image. Imprime au plus une ligne par seconde.
    void ImprimerChaqueSeconde() {
        const auto ms = mHorloge.Elapsed().ToMilliseconds();
        if (ms - mDernierAffichageMs < 1000) return;
        mDernierAffichageMs = ms;
        std::printf("t = %.1f s, images = %llu, brut = %d, lacet = %.1f deg\n",
            static_cast<double>(ms) / 1000.0,
            static_cast<unsigned long long>(mImages),
            static_cast<int>(NkInput.MouseRawDeltaX()),
            static_cast<double>(LacetDegres()));
    }

private:
    float32 mSensibilite;
    float32 mLacet = 0.0f;
    float32 mTangage = 0.0f;
    unsigned long long mImages = 0;
    NkChrono mHorloge;
    decltype(mHorloge.Elapsed().ToMilliseconds()) mDernierAffichageMs = 0;
};

} // namespace nkentseu
