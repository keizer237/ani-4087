
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n = 2;
    int T = 8;
    long long x0 = 0;
    long long v = 10;
    string modes = "DPDPDPDP";

    vector<int> images(n, 0);
    int prochaine = 0;
    bool precedent = false;
    long long positionPrecedente = 0;
    vector<long long> sauts;

    for (int t = 1; t <= T; t++) {
        int empruntee = prochaine;
        images[empruntee] = t;

        int index;

        if (modes[t - 1] == 'A') {
            index = empruntee;
        }
        else if (modes[t - 1] == 'P') {
            index = (prochaine + n - 1) % n;
        }
        else {
            prochaine = (prochaine + 1) % n;
            index = (prochaine + n - 1) % n;
        }

        if (modes[t - 1] != 'D') {
            prochaine = (prochaine + 1) % n;
        }

        int f = images[index];

        if (f == 0) {
            cout << t << " NOIR -\n";
            precedent = false;
        } else {
            long long position = x0 + v * f;

            if (!precedent) {
                cout << t << " " << position << " -\n";
            } else {
                long long saut = position - positionPrecedente;
                cout << t << " " << position << " " << saut << "\n";
                sauts.push_back(saut);
            }

            positionPrecedente = position;
            precedent = true;
        }
    }

    if (sauts.empty()) {
        cout << "SAUTS AUCUN\n";
    } else {
        long long mini = *min_element(sauts.begin(), sauts.end());
        long long maxi = *max_element(sauts.begin(), sauts.end());

        cout << "SAUT MIN " << mini << "\n";
        cout << "SAUT MAX " << maxi << "\n";
        cout << "TREMBLE " << (mini != maxi ? "OUI" : "NON") << "\n";
    }

    return 0;
}
