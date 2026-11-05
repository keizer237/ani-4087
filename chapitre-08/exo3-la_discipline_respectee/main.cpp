
#include <iostream>
using namespace std;

int main() {
    int n, N;
    cin >> n >> N;

    int prochaine = 0;
    int empruntee = -1;
    int derniere = -1;
    int soumises = 0, refus = 0, hors = 0;

    bool dessinee = false;
    bool disponible = false;
    bool derniereDessinee = false;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "acquire") {
            if (empruntee != -1) {
                cout << "ACQUIRE REFUSE\n";
                refus++;
            } else {
                empruntee = prochaine;
                dessinee = false;
                cout << "ACQUIRE " << empruntee << "\n";
            }
        }
        else if (cmd == "draw") {
            if (empruntee == -1) {
                cout << "DRAW HORS EMPRUNT\n";
                hors++;
            } else {
                dessinee = true;
                cout << "DRAW " << empruntee << "\n";
            }
        }
        else if (cmd == "release") {
            if (empruntee == -1) {
                cout << "RELEASE REFUSE\n";
                refus++;
            } else {
                derniere = empruntee;
                derniereDessinee = dessinee;
                disponible = true;
                prochaine = (prochaine + 1) % n;
                empruntee = -1;
                cout << "RELEASE OK\n";
            }
        }
        else if (cmd == "submit") {
            if (empruntee != -1) {
                cout << "SUBMIT REFUSE EMPRUNTEE\n";
                refus++;
            } else if (!disponible) {
                cout << "SUBMIT REFUSE RIEN\n";
                refus++;
            } else {
                cout << "SUBMIT " << derniere;
                if (!derniereDessinee) cout << " VIDE";
                cout << "\n";
                soumises++;
                disponible = false;
            }
        }
    }

    cout << "SOUMISES " << soumises << "\n";
    cout << "REFUS " << refus << "\n";
    cout << "HORS EMPRUNT " << hors << "\n";

    return 0;
}
