
#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int n, N;
    uint32_t v;

    cin >> n >> v >> N;

    uint32_t variables[26];

    for (int i = 0; i < 26; i++) {
        variables[i] = v;
    }

    int prochaine = 0;
    bool empruntee = false;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "acquire") {
            char x;
            cin >> x;

            int indice = x - 'a';

            if (empruntee) {
                cout << "ACQUIRE FAUX " << x << " "
                     << variables[indice] << "\n";
            } else {
                variables[indice] = prochaine;
                empruntee = true;

                cout << "ACQUIRE VRAI " << x << " "
                     << variables[indice] << "\n";
            }
        }
        else if (cmd == "release") {
            if (!empruntee) {
                cout << "RELEASE FAUX\n";
            } else {
                prochaine = (prochaine + 1) % n;
                empruntee = false;
                cout << "RELEASE VRAI\n";
            }
        }
        else if (cmd == "last") {
            int j = (prochaine + n - 1) % n;
            cout << "LAST " << j << "\n";
        }
    }

    cout << "EMPRUNTEE " << (empruntee ? "OUI" : "NON") << "\n";
    cout << "PROCHAINE " << prochaine << "\n";

    return 0;
}
