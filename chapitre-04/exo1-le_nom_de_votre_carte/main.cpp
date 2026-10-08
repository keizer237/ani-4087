#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<string> ordrePourPlateforme(const string& plateforme) {
    if (plateforme == "WINDOWS") return {"VULKAN", "DX12", "DX11", "OPENGL", "SOFTWARE"};
    if (plateforme == "MACOS")   return {"METAL", "OPENGL", "SOFTWARE"};
    if (plateforme == "IOS")     return {"METAL", "SOFTWARE"};
    if (plateforme == "ANDROID") return {"VULKAN", "OPENGL", "SOFTWARE"};
    return {"VULKAN", "OPENGL", "SOFTWARE"};
}

int main() {
    map<string, string> noms = {
        {"VULKAN", "Vulkan"},
        {"DX12", "DirectX 12"},
        {"DX11", "DirectX 11"},
        {"OPENGL", "OpenGL"},
        {"METAL", "Metal"},
        {"SOFTWARE", "Software"}
    };

    int n;
    cin >> n;

    int ignorees = 0;
    int logiciel = 0;
    set<string> differentes;

    for (int i = 0; i < n; i++) {
        string nom, plateforme;
        int k;
        cin >> nom >> plateforme >> k;

        set<string> liste;
        for (int j = 0; j < k; j++) {
            string api;
            cin >> api;
            liste.insert(api);
        }

        vector<string> ordre = ordrePourPlateforme(plateforme);
        set<string> dansOrdre(ordre.begin(), ordre.end());

        // interfaces qui marchent mais que la détection n'essaie jamais
        for (const string& api : liste) {
            if (dansOrdre.count(api) == 0) ignorees++;
        }

        string choisie = "SOFTWARE";
        for (const string& api : ordre) {
            if (api == "SOFTWARE" || liste.count(api)) {
                choisie = api;
                break;
            }
        }

        if (choisie == "SOFTWARE") logiciel++;

        string lisible = noms[choisie];
        differentes.insert(lisible);
        cout << nom << " " << lisible << "\n";
    }

    cout << "IGNOREES " << ignorees << "\n";
    cout << "LOGICIEL " << logiciel << "\n";
    cout << "DIFFERENTES " << differentes.size() << "\n";
    return 0;
}
