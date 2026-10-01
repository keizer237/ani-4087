# Exercice 4 : Fermer proprement


## Solution

Pour cet exercice, j'ai modifié la boucle principale afin qu'elle ne dépende plus directement de `fenetre.IsOpen()`.

J'ai créé un booléen `running` qui indique si le programme doit continuer à fonctionner. Au départ, sa valeur est `true`.

Un rappel sur `NkWindowCloseEvent` met `running` à `false` lorsque l'utilisateur ferme la fenêtre.

J'ai aussi ajouté un rappel sur `NkKeyPressEvent` qui met le même booléen à `false` lorsque la touche **Échap** est pressée.

### Programme [`main.cpp`](main.cpp)

```cpp
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

    // Vérification que la fenêtre a bien été créée
    if (!fenetre.IsValid()){
        return 1;
    }

    bool running = true;

    // Rappel appelé lorsque l'utilisateur ferme la fenêtre (bouton X)
    nkentseu::NkEvents().AddEventCallback<nkentseu::NkWindowCloseEvent>(
        [&](nkentseu::NkWindowCloseEvent* event){
            running = false;
        });

    // Rappel appelé lorsqu'une touche est pressée : on vérifie si c'est Échap
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
```

## Ce que font les boucles et les rappels

Quand je lance `jenga build` puis `jenga run projet`, une fenêtre s'ouvre à l'écran. Le programme entre alors dans la boucle `while (running)`.

- À chaque tour, `PollEvents()` regarde ce qui s'est passé sur la fenêtre : un clic, une touche, la croix de fermeture, etc.
- Si rien ne s'est passé, la boucle recommence. La fenêtre reste ouverte et le programme tourne.
- Si j'appuie sur une touche autre qu'Échap, le rappel du clavier est appelé, mais il ne fait rien, car ce n'est pas la bonne touche. La fenêtre reste ouverte.
- Si je clique sur la croix de la fenêtre, le rappel `NkWindowCloseEvent` est appelé et met `running` à `false`.
- Si j'appuie sur **Échap**, le rappel `NkKeyPressEvent` est appelé et met aussi `running` à `false`.

Quand `running` est `false`, la boucle s'arrête au tour suivant. Le programme passe au `return 0`, la fenêtre disparaît de l'écran et le terminal revient à la ligne de commande.

Le `PollEvents()` est important : sans lui, les rappels ne sont jamais appelés, et la fenêtre ne réagit plus (elle ne se ferme pas, elle peut même afficher « ne répond pas »).

## Pourquoi les deux chemins doivent aboutir au même endroit ?

Les deux actions ont le même objectif : **arrêter proprement le programme**.

Que l'utilisateur ferme la fenêtre avec la croix ou qu'il appuie sur **Échap**, le résultat doit être le même : `running` passe à `false`, la boucle s'arrête et le programme arrive au même `return 0`.

Cela évite d'avoir deux façons différentes de quitter. Il n'y a qu'une seule condition de sortie et un seul endroit à surveiller. Si chaque chemin quittait à sa manière, par exemple avec un `return` direct dans un rappel, on pourrait oublier de faire le nettoyage d'un côté, et le programme se comporterait différemment selon la façon de fermer.
