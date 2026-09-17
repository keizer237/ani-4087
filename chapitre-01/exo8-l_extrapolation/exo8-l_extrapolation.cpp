#include <iostream>
#include <cmath>

struct Vecteur3D {
    double x, y, z;
};

struct Quaternion {
    double x, y, z, w;
};

struct Pose {
    Victeur3D position;
    Quaternion orientation;
};

# Fonction appliquant l'extrapolation linéaire et angulaire
Pose extrapolerPose(Pose initiale, Vecteur3D vLin, Vecteur3D vAng, double dt) {
    Pose resultat;

    # 1. Extrapolation linéaire simple de la position
    resultat.position.x = initiale.position.x + vLin.x * dt;
    resultat.position.y = initiale.position.y + vLin.y * dt;
    resultat.position.z = initiale.position.z + vLin.z * dt;

    # Extrapolation angulaire 
    # Calcul de la norme de la vitesse angulaire
    double normeW = std::sqrt(vAng.x * vAng.x + vAng.y * vAng.y + vAng.z * vAng.z);
    if (normeW < 1e-7) {
        
        resultat.orientation = initiale.orientation;
    } else {
        
        double theta = normeW * dt;

      
        double sinDemi = std::sin(theta / 2.0);
        double dq_w = std::cos(theta / 2.0);
        double dq_x = (vAng.x / normeW) * sinDemi;
        double dq_y = (vAng.y / normeW) * sinDemi;
        double dq_z = (vAng.z / normeW) * sinDemi;

        # Application du produit de Hamilton : q_nouveau = dq * q_initial
        Quaternion q = initiale.orientation;
        resultat.orientation.w = dq_w * q.w - dq_x * q.x - dq_y * q.y - dq_z * q.z;
        resultat.orientation.x = dq_w * q.x + dq_x * q.w + dq_y * q.z - dq_z * q.y;
        resultat.orientation.y = dq_w * q.y - dq_x * q.z + dq_y * q.w + dq_z * q.x;
        resultat.orientation.z = dq_w * q.z + dq_x * q.y - dq_y * q.x + dq_z * q.w;
    }

    return resultat;
}

int main() {
    Pose poseInitiale;
    Vecteur3D vLin, vAng;
    double dt;

    # Entrées de l'exercice
    std::cin >> poseInitiale.position.x >> poseInitiale.position.y >> poseInitiale.position.z;
    std::cin >> poseInitiale.orientation.x >> poseInitiale.orientation.y >> poseInitiale.orientation.z >> poseInitiale.orientation.w;
    std::cin >> vLin.x >> vLin.y >> vLin.z;
    std::cin >> vAng.x >> vAng.y >> vAng.z;
    std::cin >> dt;

    # Calcul de la prédiction
    Pose poseFuture = extrapolerPose(poseInitiale, vLin, vAng, dt);

    std::cout << poseFuture.position.x << " " << poseFuture.position.y << " " << poseFuture.position.z << std::endl;
    std::cout << poseFuture.orientation.x << " " << poseFuture.orientation.y << " " << poseFuture.orientation.z << " " << poseFuture.orientation.w << std::endl;

    return 0;
}
