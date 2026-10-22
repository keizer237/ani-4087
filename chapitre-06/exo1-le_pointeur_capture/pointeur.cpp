#include "NKWindow/NKWindow.h"

namespace nkentseu::PointeurCapture {
namespace {
    NkWindow* gFenetre = nullptr;
    unsigned int gNombreMasquages = 0;
    bool gCaptureActive = false;
    bool gConfinementActif = false;
}

void Prendre(NkWindow& fenetre) {
    gFenetre = &fenetre;

    // ShowMouse repose sur un compteur sous Windows : chaque false compte.
    gFenetre->ShowMouse(false);
    ++gNombreMasquages;

    gFenetre->CaptureMouse(true);
    gCaptureActive = true;

    // Confine le curseur au rectangle client de la fenêtre.
    gFenetre->ClipMouseToClient(true);
    gConfinementActif = true;
}

void Rendre() {
    if (gFenetre == nullptr) return;

    // Équilibrer tous les appels à ShowMouse(false), même après plusieurs
    // pressions de la touche qui reprend le curseur.
    while (gNombreMasquages > 0) {
        gFenetre->ShowMouse(true);
        --gNombreMasquages;
    }
    if (gCaptureActive) {
        gFenetre->CaptureMouse(false);
        gCaptureActive = false;
    }
    if (gConfinementActif) {
        gFenetre->ClipMouseToClient(false);
        gConfinementActif = false;
    }
}

void AvantFermeture() {
    Rendre();
    gFenetre = nullptr;
}

} 
