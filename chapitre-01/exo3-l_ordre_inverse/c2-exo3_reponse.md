#include <iostream>

struct Point3D {
    double x;
    double y;
    double z;
};

struct Quaternion {
    double x;
    double y;
    double z;
    double w;
};

struct Pose {
    Point3D position;
    Quaternion orientation;
};

# Fonction de rotation géométrique issue de l'exercice précédent
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
    
    Point3D resultat;
    resultat.x = p.x + 2.0 * (q.w * crossX + crossCrossX);
    resultat.y = p.y + 2.0 * (q.w * crossY + crossCrossY);
    resultat.z = p.z + 2.0 * (q.w * crossZ + crossCrossZ);
    
    return resultat;
}

## PREMIÈRE FONCTION : Rotation PUIS Translation
Point3D appliquerPoseRotationEnPremier(Pose maPose, Point3D monPoint) {
    Point3D pointTourne = tournerPoint(maPose.orientation, monPoint);
    
    Point3D pointFinal;
    pointFinal.x = pointTourne.x + maPose.position.x;
    pointFinal.y = pointTourne.y + maPose.position.y;
    pointFinal.z = pointTourne.z + maPose.position.z;
    
    return pointFinal;
}

## NOTRE DEUXIÈME FONCTION : Translation D'ABORD puis Rotation ENSUITE
Point3D appliquerPoseTranslationEnPremier(Pose maPose, Point3D monPoint) {
    # D'abord une translation
    Point3D pointDeplace;
    pointDeplace.x = monPoint.x + maPose.position.x;
    pointDeplace.y = monPoint.y + maPose.position.y;
    pointDeplace.z = monPoint.z + maPose.position.z;
    
    # Appliquons la rotation ensuite sur le point déjà déplacé
    Point3D pointFinal = tournerPoint(maPose.orientation, pointDeplace);
    
    return pointFinal;
}

int main() {
    Pose poseUtilisateur;
    Point3D pointInitial;

    # Lecture de nos donnees d'entree
    std::cin >> poseUtilisateur.position.x >> poseUtilisateur.position.y >> poseUtilisateur.position.z;
    std::cin >> poseUtilisateur.orientation.x >> poseUtilisateur.orientation.y >> poseUtilisateur.orientation.z >> poseUtilisateur.orientation.w;
    std::cin >> pointInitial.x >> pointInitial.y >> pointInitial.z;

    # Calcule de nos deux methode
    Point3D resultat1 = appliquerPoseRotationEnPremier(poseUtilisateur, pointInitial);
    Point3D resultat2 = appliquerPoseTranslationEnPremier(poseUtilisateur, pointInitial);

    # Affichage de nos deux resultats :
    std::cout << resultat1.x << " " << resultat1.y << " " << resultat1.z << std::endl;
    std::cout << resultat2.x << " " << resultat2.y << " " << resultat2.z << std::endl;

    return 0;
}
