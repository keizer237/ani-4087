//#include "NKWindow/NKMain.h"
//#include "NKWindow/NKWindow.h"

//NKENTSEU_DEFINE_APP_DATA(([](){
    //nkentseu::NkAppData d{};
    //d.appName = "La Fenetre Nue";
    //d.appVersion = "0.1.0";
    //return d;
//})())

//int nkmain(const nkentseu::NkEntryState &state)
//{
    //nkentseu::NkWindowConfig config;
    //config.title = "Ma Salle";
    //config.width = 1000;
    //config.height = 720;

    //nkentseu::NkWindow fenetre(config);
    //if (!fenetre.IsValid()) {
       // return 1;
    //}

    //while(fenetre.IsOpen()) {
        //nkentseu::NkEvents().PollEvents();
    //}

    //return 0;
//}

//#include <NKWindow/NKWindow.h>
//#include <NKEvent/NkEvent.h>

//int main(){
    //nkentseu::NkWindowConfig config;

    ////config.title = "Ma salle";
    //config.width = 1280;
    //config.height = 720;
    //config.resizable = false;


    //nkentseu::NkWindow fenetre(config);

    //if (!fenetre.IsValid()){
        //return 1;
    //}

    //while (fenetre.IsOpen()){
        //nkentseu::NkEvents().PollEvents();
    //}

    //return 0;
//}
#include <NKWindow/NKWindow.h>
#include <NKEvent/NkEvent.h>
#include <NKEvent/NkWindowEvent.h>
#include <NKEvent/NkKeyboardEvent.h>

int main(){
    // Configuration de la fenêtre
    nkentseu::NkWindowConfig config;

    config.title = "Ma salle";
    config.width = 1280;
    config.height = 720;

    // Création de la fenêtre avec la configuration définie
    nkentseu::NkWindow fenetre(config);

    // Vérification que la fenêtre a bien été créer
    if (!fenetre.IsValid()){
        return 1;
    }

    bool running = true;

    // Rappel appelé lorsque l'utilisateur ferme la fenêtre
    // bouton X
    nkentseu::NkEvents().AddEventCallback<nkentseu::NkWindowCloseEvent>(
        [&](nkentseu::NkWindowCloseEvent* event){
            running = false;
        });

    // Rappel appelé lorsqu'une touche du clavier est pressée, on verifie si c'est la touche Echap
    // touche Échap
    nkentseu::NkEvents().AddEventCallback<nkentseu::NkKeyPressEvent>(
        [&](nkentseu::NkKeyPressEvent* event){
            if (event->GetKey() == nkentseu::NkKey::NK_ESCAPE){
                running = false;
            }
        });
        

    while (running){
        nkentseu::NkEvents().PollEvents();
    }

    return 0;
}