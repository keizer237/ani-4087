#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unsigned long long valeurDrapeau(string drapeau) {
    if (drapeau == "RENDER2D") return 1;
    if (drapeau == "RENDER3D") return 2;
    if (drapeau == "TEXT") return 4;
    if (drapeau == "UI") return 8;
    if (drapeau == "SHADOW") return 16;
    if (drapeau == "POST_PROCESS") return 32;
    if (drapeau == "ALL") return 4294967295ULL;
    return 0;
}

int main() {
    string nom1, nom2;
    int k1, k2;
    unsigned long long v1 = 0, v2 = 0;
    long long t1[10], t2[10];

    cin >> nom1 >> k1;
    for (int i = 0; i < k1; i++) {
        string drapeau;
        cin >> drapeau;
        v1 |= valeurDrapeau(drapeau);
    }

    for (int i = 0; i < 10; i++)
        cin >> t1[i];

    cin >> nom2 >> k2;
    for (int i = 0; i < k2; i++) {
        string drapeau;
        cin >> drapeau;
        v2 |= valeurDrapeau(drapeau);
    }

    for (int i = 0; i < 10; i++)
        cin >> t2[i];

    sort(t1, t1 + 10);
    sort(t2, t2 + 10);

    long long mediane1 = (t1[4] + t1[5]) / 2;
    long long mediane2 = (t2[4] + t2[5]) / 2;

    long long somme1 = 0, somme2 = 0;

    for (int i = 0; i < 10; i++) {
        somme1 += t1[i];
        somme2 += t2[i];
    }

    long long moyenne1 = somme1 / 10;
    long long moyenne2 = somme2 / 10;

    cout << nom1 << " VALEUR " << v1 << "\n";
    cout << nom1 << " MEDIANE " << mediane1 << "\n";
    cout << nom1 << " MOYENNE " << moyenne1 << "\n";

    cout << nom2 << " VALEUR " << v2 << "\n";
    cout << nom2 << " MEDIANE " << mediane2 << "\n";
    cout << nom2 << " MOYENNE " << moyenne2 << "\n";

    cout << "ECART MEDIANES " << mediane1 - mediane2 << "\n";
    cout << "ECART MOYENNES " << moyenne1 - moyenne2 << "\n";

    return 0;
}