#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    const unsigned long long RENDER2D = 1, RENDER3D = 2, TEXT = 4, UI = 8;
    const unsigned long long SHADOW = 16, POST_PROCESS = 32, VFX = 64;
    const unsigned long long ANIMATION = 128, OVERLAY = 256, SIMULATION = 512;
    const unsigned long long OFFSCREEN = 1024, RAYTRACING = 2048, GPU_CULLING = 4096;

    map<string, unsigned long long> drapeaux = {
        {"RENDER2D", RENDER2D}, {"RENDER3D", RENDER3D}, {"TEXT", TEXT},
        {"UI", UI}, {"SHADOW", SHADOW}, {"POST_PROCESS", POST_PROCESS},
        {"VFX", VFX}, {"ANIMATION", ANIMATION}, {"OVERLAY", OVERLAY},
        {"SIMULATION", SIMULATION}, {"OFFSCREEN", OFFSCREEN},
        {"RAYTRACING", RAYTRACING}, {"GPU_CULLING", GPU_CULLING},
        {"NONE", 0},
        {"2D_ESSENTIALS", RENDER2D | TEXT},
        {"3D_BASE", RENDER3D | SHADOW | POST_PROCESS},
        {"DEBUG", OVERLAY | SIMULATION},
        {"ALL", 4294967295ULL}
    };

    int n;
    cin >> n;

    unsigned long long valeur = 0;
    vector<string> inconnus;

    for (int i = 0; i < n; i++) {
        string nom;
        cin >> nom;
        map<string, unsigned long long>::iterator it = drapeaux.find(nom);
        if (it == drapeaux.end()) {
            inconnus.push_back(nom);
        } else {
            valeur |= it->second;
        }
    }

    if (n == 0) valeur = 4294967295ULL;

    for (size_t i = 0; i < inconnus.size(); i++) {
        cout << "INCONNU " << inconnus[i] << "\n";
    }

    cout << "VALEUR " << valeur << "\n";

    string chiffres = "0123456789ABCDEF";
    string hexa = "";
    for (int i = 7; i >= 0; i--) {
        hexa += chiffres[(valeur >> (i * 4)) & 15];
    }
    cout << "HEXA 0x" << hexa << "\n";

    // dépendances, dans l'ordre : TEXT, UI, SHADOW, OVERLAY
    if (valeur & TEXT) {
        if (!(valeur & RENDER2D)) cout << "MANQUE TEXT RENDER2D\n";
    }
    if (valeur & UI) {
        if (!(valeur & RENDER2D)) cout << "MANQUE UI RENDER2D\n";
        if (!(valeur & TEXT)) cout << "MANQUE UI TEXT\n";
    }
    if (valeur & SHADOW) {
        if (!(valeur & RENDER3D)) cout << "MANQUE SHADOW RENDER3D\n";
    }
    if (valeur & OVERLAY) {
        if (!(valeur & RENDER2D)) cout << "MANQUE OVERLAY RENDER2D\n";
        if (!(valeur & TEXT)) cout << "MANQUE OVERLAY TEXT\n";
    }

    int allumes = 0;
    for (int bit = 0; bit < 13; bit++) {
        if (valeur & (1ULL << bit)) allumes++;
    }

    cout << "ALLUMES " << allumes << "\n";
    cout << "ETEINTS " << 13 - allumes << "\n";
    return 0;
}
