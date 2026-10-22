#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

namespace nkentseu {

struct TeteTestable {
    float32 lacetRad = 0.0f;
    float32 tangageRad = 0.0f;
    math::NkVec3f position = math::NkVec3f(0.0f, 0.0f, 0.0f);

    void PoserTete(float32 lacet, float32 tangage, const math::NkVec3f& nouvellePosition) {
        lacetRad = lacet;
        tangageRad = tangage;
        position = nouvellePosition;
    }

    math::NkVec3f Regard() const {
        return math::NkVec3f(
            -std::sin(lacetRad) * std::cos(tangageRad),
             std::sin(tangageRad),
            -std::cos(lacetRad) * std::cos(tangageRad));
    }
};

inline bool PresqueEgal(float32 a, float32 b, float32 epsilon = 0.0005f) {
    return std::fabs(a - b) <= epsilon;
}

inline bool VecteurPresqueEgal(const math::NkVec3f& a, const math::NkVec3f& b) {
    return PresqueEgal(a.x, b.x) && PresqueEgal(a.y, b.y) && PresqueEgal(a.z, b.z);
}

inline bool EpreuveTete(const char* nom, float32 lacetDeg, float32 tangageDeg,
                        const math::NkVec3f& attendu) {
    constexpr float32 degVersRad = 3.14159265358979323846f / 180.0f;
    TeteTestable tete;
    tete.PoserTete(lacetDeg * degVersRad, tangageDeg * degVersRad,
                   math::NkVec3f(1.0f, 2.0f, 3.0f));
    const math::NkVec3f obtenu = tete.Regard();
    const bool ok = VecteurPresqueEgal(obtenu, attendu);
    std::printf("%s : attendu (%.4f, %.4f, %.4f), obtenu (%.4f, %.4f, %.4f), %s\n",
        nom, static_cast<double>(attendu.x), static_cast<double>(attendu.y),
        static_cast<double>(attendu.z), static_cast<double>(obtenu.x),
        static_cast<double>(obtenu.y), static_cast<double>(obtenu.z), ok ? "OK" : "ECHEC");
    return ok;
}

inline int ExecuterTestsTete() {
    // Attendus écrits en dur, déduits de la convention avant = -Z, haut = +Y.
    bool ok = true;
    ok &= EpreuveTete("lacet 90, tangage 0", 90.0f, 0.0f,
                      math::NkVec3f(-1.0f, 0.0f, 0.0f));
    ok &= EpreuveTete("lacet 0, tangage 30", 0.0f, 30.0f,
                      math::NkVec3f(0.0f, 0.5f, -0.8660254f));
    // Cette épreuve échoue si le signe du lacet est inversé dans Regard().
    ok &= EpreuveTete("lacet -90, tangage 0", -90.0f, 0.0f,
                      math::NkVec3f(1.0f, 0.0f, 0.0f));
    std::printf("Résultat des tests : %s\n", ok ? "OK" : "ECHEC");
    return ok ? 0 : 1;
}

inline bool ModeTestTeteDemande() {
    const char* valeur = std::getenv("MASALLE_TEST");
    return valeur != nullptr && std::string(valeur) == "1";
}

} // namespace nkentseu
