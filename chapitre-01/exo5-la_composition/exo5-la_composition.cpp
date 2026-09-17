#include <iostream>
#include <cmath>

struct Point3D {
    double x, y, z;
};

struct Quaternion {
    double x, y, z, w;
};

struct Pose {
    Point3D position;
    Quaternion orientation;
};

# Fonction de rotation
Point3D tournerPoint(Quaternion q, Point3D p) {
    double vX = q.x;
    double vY = q.y;
    double vZ = q.z;
    
    double crossX = vY * p.z - vZ * p.y;
    double crossY = vZ * p.x - vX * p.z;
    double crossZ = vX * p.y - vY * p.x;
    
    double crossCrossX = vY * crossZ - vZ * crossY;
    double crossCrossY = vZ * crossX - vX * crossZ;
    double crossCrossZ = vX * crossY - vY * crossX;
    
    Point3D res;
    res.x = p.x + 2.0 * (q.w * crossX + crossCrossX);
    res.y = p.y + 2.0 * (q.w * crossY + crossCrossY);
    res.z = p.z + 2.0 * (q.w * crossZ + crossCrossZ);
    return res;
}

# Appliquons une seule pose à un point (Rotation puis Translation)
Point3D appliquerPose(Pose pose, Point3D p) {
    Point3D tourne = tournerPoint(pose.orientation, p);
    Point3D res;
    res.x = tourne.x + pose.position.x;
    res.y = tourne.y + pose.position.y;
    res.z = tourne.z + pose.position.z;
    return res;
}

# Composons deux quaternions ensemble (Multiplication de Hamilton)
Quaternion multiplierQuaternions(Quaternion a, Quaternion b) {
    Quaternion res;
    res.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
    res.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
    res.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
    res.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
    return res;
}

# FONCTION DE COMPOSITION DES DEUX POSES (A o B)
Pose composerPoses(Pose a, Pose b) {
    Pose res;
    res.orientation = multiplierQuaternions(a.orientation, b.orientation);
    
    Point3D positionB_tournee = tournerPoint(a.orientation, b.position);
    res.position.x = a.position.x + positionB_tournee.x;
    res.position.y = a.position.y + positionB_tournee.y;
    res.position.z = a.position.z + positionB_tournee.z;
    
    return res;
}

int main() {
    Pose poseA, poseB;
    Point3D monPoint;

    # Données de la Pose A (Position puis Quaternion)
    std::cin >> poseA.position.x >> poseA.position.y >> poseA.position.z;
    std::cin >> poseA.orientation.x >> poseA.orientation.y >> poseA.orientation.z >> poseA.orientation.w;
    # Données de la Pose B (Position puis Quaternion)
    std::cin >> poseB.position.x >> poseB.position.y >> poseB.position.z;
    std::cin >> poseB.orientation.x >> poseB.orientation.y >> poseB.orientation.z >> poseB.orientation.w;
  
    std::cin >> monPoint.x >> monPoint.y >> monPoint.z;

    # MÉTHODE 1 : Appliquer l'une après l'autre (D'abord B, ensuite A)
    Point3D ptApresB = appliquerPose(poseB, monPoint);
    Point3D ptFinalMethode1 = appliquerPose(poseA, ptApresB);

    # MÉTHODE 2 : Composer d'abord puis appliquer la pose combinée
    Pose poseComposee = composerPoses(poseA, poseB);
    Point3D ptFinalMethode2 = appliquerPose(poseComposee, monPoint);

    # Calcul de l'écart géométrique (Distance euclidienne entre les deux points finaux)
    double dx = ptFinalMethode1.x - ptFinalMethode2.x;
    double dy = ptFinalMethode1.y - ptFinalMethode2.y;
    double dz = ptFinalMethode1.z - ptFinalMethode2.z;
    double ecart = std::sqrt(dx*dx + dy*dy + dz*dz);

    # Affichage des deux points et de l'écart
    std::cout << ptFinalMethode1.x << " " << ptFinalMethode1.y << " " << ptFinalMethode1.z << std::endl;
    std::cout << ptFinalMethode2.x << " " << ptFinalMethode2.y << " " << ptFinalMethode2.z << std::endl;
    std::cout << ecart << std::endl;

    return 0;
}
