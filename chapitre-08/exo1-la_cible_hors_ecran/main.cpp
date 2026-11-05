
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, H, F, N;
    cin >> L >> H >> F >> N;

    vector<int> largeur(1), hauteur(1);
    vector<bool> pris(F, false);

    bool offscreen = false;
    bool gele = false;
    int nbCibles = 0;
    int destination = 0;
    int w = L, h = H;
    int images = 0;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (gele) continue;

        if (cmd == "allume") {
            string nom;
            cin >> nom;
            if (nom == "OFFSCREEN") offscreen = true;
        }
        else if (cmd == "cible") {
            int a, b;
            cin >> a >> b;

            if (!offscreen) {
                cout << "CIBLE NULLE\n";
            } else {
                nbCibles++;
                largeur.push_back(a);
                hauteur.push_back(b);
                cout << "CIBLE " << nbCibles << " " << a << " " << b << "\n";
            }
        }
        else if (cmd == "vers") {
            int k;
            cin >> k;

            if (k < 0 || k > nbCibles) {
                cout << "VERS REFUSE\n";
            } else {
                destination = k;
            }
        }
        else if (cmd == "taille") {
            cin >> w >> h;
        }
        else if (cmd == "image") {
            int n = images + 1;
            int tampon = (n - 1) % F;

            if (pris[tampon]) {
                cout << "BLOQUE " << n << "\n";
                gele = true;
            } else {
                images++;

                if (destination == 0) {
                    cout << "IMAGE " << n << " FENETRE\n";
                } else {
                    cout << "IMAGE " << n << " CIBLE " << destination << "\n";

                    if (w > largeur[destination] || h > hauteur[destination]) {
                        pris[tampon] = true;
                    }
                }
            }
        }
    }

    cout << "IMAGES " << images << "\n";
    cout << "ETAT " << (gele ? "BLOQUE" : "LIBRE") << "\n";

    return 0;
}
