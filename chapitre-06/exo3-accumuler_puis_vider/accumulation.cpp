// Symptôme : le lacet continue d'évoluer quand la souris est immobile.
// Cause : sans vidage, l'accumulateur conserve les anciens déplacements et les réapplique à chaque image.
// Preuve : après l'arrêt, « sans vidage » continue de varier tandis que « vide » reste stable.
// Correction : accumuler chaque événement brut, lire la somme une fois par image, puis la remettre à zéro.

#include "NKEvent/NkEventDispatcher.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKTime/NkChrono.h"
#include <cmath>
#include <cstdio>

namespace nkentseu {

class ComparaisonAccumulation {
public:
    explicit ComparaisonAccumulation(float32 sensibilite = 0.002f)
        : mSensibilite(sensibilite) {}

    // Appeler dans la pompe, pour chaque événement reçu.
    void SurEvenement(NkEvent* ev) {
        if (ev == nullptr) return;
        if (auto* brut = ev->As<NkMouseRawEvent>()) {
            const float32 dx = static_cast<float32>(brut->GetDeltaX());
            mEnAttenteAvecVidage += dx;
            mTotalSansVidage += dx;
        }
    }

    // Appeler exactement une fois par image, après la pompe d'événements.
    void UneImage() {
        // Version fautive : le module conserve la dernière valeur brute.
        mLacetLectureModule += static_cast<float32>(NkInput.MouseRawDeltaX()) * mSensibilite;

        // Version correcte : lire la somme des événements, puis la vider.
        mLacetAvecVidage += mEnAttenteAvecVidage * mSensibilite;
        mEnAttenteAvecVidage = 0.0f;

        // Version fautive : additionner à chaque image une somme historique
        // qui n'est jamais remise à zéro.
        mLacetSansVidage += mTotalSansVidage * mSensibilite;
        ++mImages;
    }

    // La premiere version (lecture directe du module) est celle qui pilote la camera.
    // Le tangage reste nul dans cet exercice : seule la direction horizontale est comparee.
    math::NkVec3f DirectionLectureModule() const {
        return math::NkVec3f(-std::sin(mLacetLectureModule), 0.0f,
                       -std::cos(mLacetLectureModule));
    }

    void ImprimerChaqueSeconde() {
        const auto ms = mHorloge.Elapsed().ToMilliseconds();
        if (ms - mDernierAffichageMs < 1000) return;
        mDernierAffichageMs = ms;
        const float32 facteur = 180.0f / 3.14159265358979323846f;
        std::printf("t = %.1f s, lu = %.1f, vide = %.1f, sans vidage = %.1f\n",
            static_cast<double>(ms) / 1000.0,
            static_cast<double>(mLacetLectureModule * facteur),
            static_cast<double>(mLacetAvecVidage * facteur),
            static_cast<double>(mLacetSansVidage * facteur));
    }

private:
    float32 mSensibilite;
    float32 mEnAttenteAvecVidage = 0.0f;
    float32 mTotalSansVidage = 0.0f;
    float32 mLacetLectureModule = 0.0f;
    float32 mLacetAvecVidage = 0.0f;
    float32 mLacetSansVidage = 0.0f;
    unsigned long long mImages = 0;
    NkChrono mHorloge;
    decltype(mHorloge.Elapsed().ToMilliseconds()) mDernierAffichageMs = 0;
};

} // namespace nkentseu
