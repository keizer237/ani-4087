#include <iostream>
#include <string>
using namespace std;

struct Position {
    long long x, y, z;
};

// centre d'un objet de hauteur sy posé au sol en (x, z)
Position PoserAuSol(long long x, long long sy, long long z) {
    return {x, sy / 2, z};
}

// centre d'un objet de hauteur sy posé sur un dessus à la hauteur H
Position PoserSurTable(long long x, long long sy, long long z, long long H) {
    return {x, H + sy / 2, z};
}

int main() {
    long long L, P, H, ep, pied, tx, tz;
    cin >> L >> P >> H >> ep >> pied >> tx >> tz;

    // le plateau repose sur le haut des pieds, qui est à H - ep
    Position plateau = PoserSurTable(tx, ep, tz, H - ep);
    cout << "PLATEAU " << plateau.x << " " << plateau.y << " " << plateau.z << "\n";

    long long dx = L / 2 - pied;
    long long dz = P / 2 - pied;
    long long hauteurPied = H - ep;

    long long signesX[4] = {-1, 1, -1, 1};
    long long signesZ[4] = {-1, -1, 1, 1};
    for (int i = 0; i < 4; i++) {
        Position p = PoserAuSol(tx + signesX[i] * dx, hauteurPied, tz + signesZ[i] * dz);
        cout << "PIED " << p.x << " " << p.y << " " << p.z << "\n";
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string nom, ou;
        long long sx, sy, sz, x, z;
        cin >> nom >> sx >> sy >> sz >> x >> z >> ou;

        Position p;
        if (ou == "TABLE") p = PoserSurTable(x, sy, z, H);
        else p = PoserAuSol(x, sy, z);

        cout << nom << " " << p.x << " " << p.y << " " << p.z << "\n";
    }
    return 0;
}
