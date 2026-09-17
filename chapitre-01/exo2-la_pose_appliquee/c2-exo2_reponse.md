#include <iostream>

## Notre structures de base pour manipuler la 3D géométrique comme pour l'exercice 1
struct Point3D {
    double x;
    double y;
    double z;
};

struct Quaternion {
    double x; # Axe X * sin(angle/2)
    double y; # Axe Y * sin(angle/2)
    double z; # Axe Z * sin(angle/2)
    double w; # cos(angle/2)
};

struct Pose {
    Point3D position;        # La translation
    Quaternion orientation;  # La rotation
};

Point3D tournerPoint(Quaternion q, Point3D p) {
    // Étape 1 : On extrait la partie vectorielle du quaternion (l'axe imaginaire)
    double vX = q.x;
    double vY = q.y;
    double vZ = q.z; 
    # Étape 2 : Produit vectoriel entre l'axe du quaternion et notre point (V x P)
    double crossX = vY * p.z - vZ * p.y;
    double crossY = vZ * p.x - vX * p.z;
    double crossZ = vX * p.y - vY * p.x;
    # Étape 3 : Deuxième produit vectoriel pour la double rotation V x (V x P)
    double crossCrossX = vY * crossZ - vZ * crossY;
    double crossCrossY = vZ * crossX - vX * crossZ;
    double crossCrossZ = vX * crossY - vY * crossX;
    # Application de la formule géométrique simplifiée
    Point3D resultat;
    resultat.x = p.x + 2.0 * (q.w * crossX + crossCrossX);
    resultat.y = p.y + 2.0 * (q.w * crossY + crossCrossY);
    resultat.z = p.z + 2.0 * (q.w * crossZ + crossCrossZ); 
    return resultat;
}

## Fonction principale demandée : Rotation PUIS Translation
Point3D appliquerPose(Pose maPose, Point3D monPoint) {
    # On applique d'abord la rotation (l'orientation)
    Point3D pointTourne = tournerPoint(maPose.orientation, monPoint);    
    # On applique une translation (la position)
    Point3D pointFinal;
    pointFinal.x = pointTourne.x + maPose.position.x;
    pointFinal.y = pointTourne.y + maPose.position.y;
    pointFinal.z = pointTourne.z + maPose.position.z; 
    return pointFinal;
}

int main() {
    Pose poseUtilisateur;
    Point3D pointInitial;
    ## Récupération des données entrées par l'utilisateur
    # Position de la pose
    std::cin >> poseUtilisateur.position.x >> poseUtilisateur.position.y >> poseUtilisateur.position.z;
    # Quaternion de la pose
    std::cin >> poseUtilisateur.orientation.x >> poseUtilisateur.orientation.y >> poseUtilisateur.orientation.z >> poseUtilisateur.orientation.w;
    # Le point à modifier
    std::cin >> pointInitial.x >> pointInitial.y >> pointInitial.z;
    
    # Résultat
    Point3D pointTransforme = appliquerPose(poseUtilisateur, pointInitial);
    ## Affichons sur notre console
    std::cout << pointTransforme.x << " " << pointTransforme.y << " " << pointTransforme.z << std::endl;

    return 0;
}
