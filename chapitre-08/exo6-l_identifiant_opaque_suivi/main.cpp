
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdint>
using namespace std;

int main() {
    int n, N;
    cin >> n >> N;

    vector<uint64_t> images(n, 0);
    unordered_set<uint64_t> textures;

    int mortes = 0;
    int larges = 0;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "cree") {
            uint64_t h;
            cin >> h;
            textures.insert(h);
        }
        else if (cmd == "detruit") {
            uint64_t h;
            cin >> h;
            textures.erase(h);
        }
        else if (cmd == "set") {
            uint64_t index, h;
            cin >> index >> h;

            if (index >= static_cast<uint64_t>(n)) {
                cout << "SET IGNORE " << index << "\n";
            } else {
                images[index] = h;

                if (h > 4294967295ULL) {
                    larges++;
                }
            }
        }
        else if (cmd == "get") {
            uint64_t index;
            cin >> index;

            uint64_t h = 0;

            if (index < static_cast<uint64_t>(n)) {
                h = images[index];
            }

            if (h == 0) {
                cout << "GET " << index << " 0 VIDE\n";
            }
            else if (textures.count(h)) {
                cout << "GET " << index << " " << h << " VIVANTE\n";
            }
            else {
                cout << "GET " << index << " " << h << " MORTE\n";
                mortes++;
            }
        }
    }

    cout << "MORTES " << mortes << "\n";
    cout << "LARGES " << larges << "\n";

    return 0;
}
