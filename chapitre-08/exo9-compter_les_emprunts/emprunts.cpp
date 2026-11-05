
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 3;
    int N = 10;

    (void)n;

    string modes[10] = {
        "normal",
        "normal",
        "double",
        "normal",
        "sortie",
        "normal",
        "normal",
        "normal",
        "normal",
        "normal"
    };

    bool empruntee = false;

    int reussies = 0;
    int refusees = 0;
    int liberations = 0;
    int premiereFuite = 0;

    for (int i = 1; i <= N; i++) {
        string mode = modes[i - 1];

        if (empruntee) {
            cout << i << " BLOQUEE\n";
            refusees++;
        } else {
            empruntee = true;
            reussies++;

            if (mode == "normal") {
                cout << i << " OK\n";
                empruntee = false;
                liberations++;
            }
            else if (mode == "double") {
                cout << i << " DOUBLE\n";
                refusees++;
                empruntee = false;
                liberations++;
            }
            else if (mode == "sortie") {
                cout << i << " FUITE\n";
                if (premiereFuite == 0) {
                    premiereFuite = i;
                }
            }
        }
    }

    cout << "REUSSIES " << reussies << "\n";
    cout << "REFUSEES " << refusees << "\n";
    cout << "LIBERATIONS " << liberations << "\n";
    cout << "ECART " << reussies - liberations << "\n";

    if (premiereFuite == 0) {
        cout << "PREMIERE FUITE AUCUNE\n";
    } else {
        cout << "PREMIERE FUITE " << premiereFuite << "\n";
    }

    return 0;
}
