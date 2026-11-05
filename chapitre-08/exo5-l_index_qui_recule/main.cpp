
#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int N;
    cin >> N;

    int refusees = 0;
    int fauxSigne = 0;
    int fauxNonSigne = 0;

    for (int i = 0; i < N; i++) {
        int n;
        uint64_t r;
        cin >> n >> r;

        if (n == 0 || n > 4) {
            cout << n << " " << r << " REFUSEE\n";
            refusees++;
        } else {
            int prochaine = static_cast<int>(r % n);

            int juste = (prochaine + n - 1) % n;
            int signe = (prochaine - 1) % n;

            uint32_t valeur = static_cast<uint32_t>(prochaine) - 1u;
            uint32_t nonsigne = valeur % static_cast<uint32_t>(n);

            cout << n << " " << r << " "
                 << prochaine << " " << juste << " "
                 << signe << " " << nonsigne << "\n";

            if (signe != juste) fauxSigne++;
            if (nonsigne != static_cast<uint32_t>(juste)) fauxNonSigne++;
        }
    }

    cout << "REFUSEES " << refusees << "\n";
    cout << "FAUX SIGNE " << fauxSigne << "\n";
    cout << "FAUX NON SIGNE " << fauxNonSigne << "\n";

    return 0;
}
