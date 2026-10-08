#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Mur {
    long long xmin, xmax, zmin, zmax;
};

struct Angle {
    string nom;
    long long xmin, xmax, zmin, zmax;
};

int main() {
    long long L, e;
    int n;
    cin >> L >> e;
    cin >> n;

    vector<Mur> murs;

    for (int i = 0; i < n; i++) {
        string nom;
        long long cx, cz, sx, sz;
        cin >> nom >> cx >> cz >> sx >> sz;

        Mur m;
        m.xmin = cx - sx / 2;
        m.xmax = cx + sx / 2;
        m.zmin = cz - sz / 2;
        m.zmax = cz + sz / 2;
        murs.push_back(m);

        cout << nom << " " << m.xmin << " " << m.xmax << " " << m.zmin << " " << m.zmax << "\n";
    }

    long long h = L / 2;
    vector<Angle> angles = {
        {"FOND_GAUCHE",   -h - e, -h,     -h - e, -h},
        {"FOND_DROIT",    h,      h + e,  -h - e, -h},
        {"ENTREE_GAUCHE", -h - e, -h,     h,      h + e},
        {"ENTREE_DROIT",  h,      h + e,  h,      h + e}
    };

    int trous = 0;

    for (const Angle& a : angles) {
        bool bouche = false;
        for (const Mur& m : murs) {
            if (m.xmin <= a.xmin && m.xmax >= a.xmax &&
                m.zmin <= a.zmin && m.zmax >= a.zmax) {
                bouche = true;
                break;
            }
        }
        if (!bouche) trous++;
        cout << a.nom << " " << (bouche ? "BOUCHE" : "TROU") << "\n";
    }

    cout << "TROUS " << trous << "\n";
    return 0;
}
