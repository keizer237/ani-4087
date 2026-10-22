#include "NKEvent/NkEventDispatcher.h"
#include "NKEvent/NkMouseEvent.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

namespace nkentseu {

class ControleConeMauvaisOrdre {
public:
    explicit ControleConeMauvaisOrdre(float32 sensibilite = 0.002f)
        : mSensibilite(sensibilite) {
        // MASALLE_LACET fixe le lacet en degrés et désactive la souris.
        if (const char* ordre = std::getenv("MASALLE_ORDRE")) {
            mMauvaisOrdre = (std::string(ordre) == "mauvais");
        }
        if (const char* texte = std::getenv("MASALLE_LACET")) {
            char* fin = nullptr;
            const float valeur = std::strtof(texte, &fin);
            if (fin != texte) {
                mLacetRad = valeur * 3.14159265358979323846f / 180.0f;
                mSourisActive = false;
            }
        }
    }

    void SurEvenement(NkEvent* ev) {
        if (!mSourisActive || ev == nullptr) return;
        if (auto* brut = ev->As<NkMouseRawEvent>()) {
            mDeltaEnAttente += static_cast<float32>(brut->GetDeltaX());
        }
    }

    // Appeler une fois par image, après le traitement des événements.
    void UneImage() {
        if (!mSourisActive) return;
        mLacetRad += mDeltaEnAttente * mSensibilite;
        mDeltaEnAttente = 0.0f;
    }

    void ChangerOrdre() { mMauvaisOrdre = !mMauvaisOrdre; }
    bool MauvaisOrdre() const { return mMauvaisOrdre; }
    float32 LacetRad() const { return mLacetRad; }

    NkQuatf Orientation() const {
        const NkQuatf qLacet = NkQuatf::RotateY(NkAngle(mLacetRad * 180.0f / 3.14159265358979323846f));
        const NkQuatf qTangage = NkQuatf::RotateX(NkAngle(30.0f));
        return mMauvaisOrdre ? (qTangage * qLacet) : (qLacet * qTangage);
    }

    void AppliquerA(const math::NkVec3f& position, math::NkVec3f& target, math::NkVec3f& up) const {
        const NkQuatf q = Orientation();
        target = position + q * math::NkVec3f(0.0f, 0.0f, -1.0f);
        up = q * math::NkVec3f(0.0f, 1.0f, 0.0f);
    }

    static void ImprimerDixHauteurs() {
        const float angles[] = {0.0f, 45.0f, 90.0f, 135.0f, 180.0f};
        for (float yawDeg : angles) {
            const NkQuatf qYaw = NkQuatf::RotateY(NkAngle(yawDeg));
            const NkQuatf qPitch = NkQuatf::RotateX(NkAngle(30.0f));
            const math::NkVec3f avant(0.0f, 0.0f, -1.0f);

            const math::NkVec3f bon = (qYaw * qPitch) * avant;
            const math::NkVec3f mauvais = (qPitch * qYaw) * avant;
            const float bonDeg = std::atan2(bon.y, std::sqrt(bon.x * bon.x + bon.z * bon.z))
                                 * 180.0f / 3.14159265358979323846f;
            const float mauvaisDeg = std::atan2(mauvais.y, std::sqrt(mauvais.x * mauvais.x + mauvais.z * mauvais.z))
                                     * 180.0f / 3.14159265358979323846f;
            std::printf("lacet*tangage, lacet %.0f : hauteur %.4f deg\n", yawDeg, bonDeg);
            std::printf("tangage*lacet, lacet %.0f : hauteur %.4f deg\n", yawDeg, mauvaisDeg);
        }
    }

private:
    float32 mSensibilite;
    float32 mLacetRad = 0.0f;
    float32 mDeltaEnAttente = 0.0f;
    bool mSourisActive = true;
    bool mMauvaisOrdre = false;
};

} // namespace nkentseu
