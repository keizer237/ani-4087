
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int courante = 0;
    int enregistree = 0;
    int prochaine = 101;

    int affichees = 0;
    int noires = 0;
    int perimees = 0;
    int images = 0;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "cible") {
            int w, h;
            cin >> w >> h;

            courante = prochaine;
            cout << "CIBLE " << prochaine << " " << w << " " << h << "\n";
            prochaine++;
        }
        else if (cmd == "chaine") {
            enregistree = 0;
        }
        else if (cmd == "enregistre") {
            enregistree = courante;
        }
        else if (cmd == "image") {
            images++;

            if (enregistree == 0) {
                cout << "IMAGE " << images << " NOIR\n";
                noires++;
            }
            else if (enregistree == courante) {
                cout << "IMAGE " << images << " AFFICHE "
                     << enregistree << "\n";
                affichees++;
            }
            else {
                cout << "IMAGE " << images << " PERIMEE "
                     << enregistree << "\n";
                perimees++;
            }
        }
    }

    cout << "AFFICHEES " << affichees << "\n";
    cout << "NOIRES " << noires << "\n";
    cout << "PERIMEES " << perimees << "\n";

    return 0;
}
