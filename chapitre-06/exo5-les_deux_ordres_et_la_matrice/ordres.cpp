#include <cstdio>

inline void CalculerEtAfficherOrdres() {
    const float32 lacetDeg = 45.0f;
    const float32 tangageDeg = 30.0f;
    const NkQuatf qLacet = NkQuatf::RotateY(NkAngle(lacetDeg));
    const NkQuatf qTangage = NkQuatf::RotateX(NkAngle(tangageDeg));
    const NkVec3f avant(0.0f, 0.0f, -1.0f);

    const NkQuatf lacetPuisTangage = qLacet * qTangage;
    const NkQuatf tangagePuisLacet = qTangage * qLacet;
    const NkVec3f regardLT = lacetPuisTangage * avant;
    const NkVec3f regardTL = tangagePuisLacet * avant;

    const NkMat4f rotation = NkMat4f::RotationY(NkAngle(lacetDeg)) *
                             NkMat4f::RotationX(NkAngle(tangageDeg));
    const NkQuatf qMatrice = NkQuatf(rotation).Normalized();
    const NkVec3f regardMatrice = qMatrice * avant;

    std::printf("lacet*tangage : (%.4f, %.4f, %.4f)\n",
        static_cast<double>(regardLT.x), static_cast<double>(regardLT.y),
        static_cast<double>(regardLT.z));
    std::printf("tangage*lacet : (%.4f, %.4f, %.4f)\n",
        static_cast<double>(regardTL.x), static_cast<double>(regardTL.y),
        static_cast<double>(regardTL.z));
    std::printf("matrices : (%.4f, %.4f, %.4f)\n",
        static_cast<double>(regardMatrice.x), static_cast<double>(regardMatrice.y),
        static_cast<double>(regardMatrice.z));

    // Vérification à la main : lever les yeux de 30° donne y = sin(30°) = 0.5.
}
