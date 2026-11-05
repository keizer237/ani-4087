
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int acceptees = 0;
    int occupes = 0;
    int gauche = 0;
    int droit = 0;
    int sansNom = 0;

    for (int i = 0; i < N; i++) {
        int largeur, hauteur, images, oeil;
        string nom;

        cin >> largeur >> hauteur >> images >> oeil >> nom;

        string nomAffiche = (nom == "-" ? "SANS-NOM" : nom);

        if (largeur == 0 || hauteur == 0) {
            cout << "REFUSEE " << nomAffiche << " TAILLE\n";
        }
        else if (images == 0 || images > 4) {
            cout << "REFUSEE " << nomAffiche << " IMAGES\n";
        }
        else {
            string cote = (oeil == 0 ? "GAUCHE" : "DROIT");

            cout << "CHAINE " << nomAffiche << " "
                 << largeur << " " << hauteur << " "
                 << images << " " << cote << "\n";

            acceptees++;
            occupes += images;

            if (oeil == 0) gauche++;
            else droit++;

            if (nom == "-") sansNom++;
        }
    }

    cout << "ACCEPTEES " << acceptees << "\n";
    cout << "EMPLACEMENTS " << acceptees * 4 << "\n";
    cout << "OCCUPES " << occupes << "\n";
    cout << "GAUCHE " << gauche << "\n";
    cout << "DROIT " << droit << "\n";
    cout << "SANS NOM " << sansNom << "\n";

    return 0;
}
