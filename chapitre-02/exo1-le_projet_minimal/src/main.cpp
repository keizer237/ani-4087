#define MON_PROPRE_DEFINE
#include "MaClasse.hpp"

int main() {
    MaClasse instance;
    instance.afficher(); // Cette ligne va poser problème si la classe est vide !
    return 0;
}