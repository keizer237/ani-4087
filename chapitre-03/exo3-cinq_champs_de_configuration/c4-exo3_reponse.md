# Exercice 3 : Cinq champs de configuration

## Solution
Pour cet exercice, j'ai choisi cinq champs différents de `NkWindowConfig` qui se trouve dans `KitNkentseu\include\NKWindow\Core` afin d'observer leur influence sur la fenêtre. J'ai testé chaque champ séparément.

### 1. Redimensionnement : `resizable`

```cpp
bool resizable = true;
```

* Je m'attends à ce que la taille de la fenêtre ne puisse plus être modifiée manuellement. *

**Observé :** Je ne pouvais plus redimensionner la fenêtre avec la souris. Sa taille restait fixe même en essayant de déplacer ses bordures.


### 2. Position horizontale : `x`

```cpp
int32 x = 600;
```
* Je m'attends à ce que la fenêtre soit positionnée plus à droite sur l'écran. *

***Observation :** Au début, j'ai essayé plusieurs valeurs pour `x`, même des valeurs beaucoup plus grandes, mais la fenêtre ne changeait pas de position. J'ai d'abord pensé qu'il y avait un problème avec le champ `x`. Ensuite, en relançant le programme, j'ai oublié de remettre `bool centered = true` et j'ai remarqué que la fenêtre avait changé de position. J'ai donc compris que lorsque `centered` est à `true`, la fenêtre est centrée automatiquement et la valeur de `x` n'est pas prise en compte pour son positionnement initial. En mettant `bool centered = false`, la valeur de `x` est bien prise en compte et la fenêtre se déplace.


### 3. Position : `centered`

```cpp
config.resizable = false;
```

**Observation :** La fenêtre ne s'est plus affichée exactement au centre de l'écran. Elle a été positionnée différemment par rapport à sa position habituelle.

### 4. Couleur de fond : `bgColor`

```cpp
uint32 bgColor = 0xFF0000FF;
```
* je m'attendait a ce que la couleur de fond change *

**Observation :** La couleur de fond de la fenêtre a changé par rapport à la couleur utilisée au départ. Le champ `bgColor` permet donc bien de modifier la couleur de la fenêtre.

### 5. Opacité : `opacity`

```cpp
float32 opacity = 0.5f;
```
* je m'attend a ce que la fenetre soit plus transparente. *
**Observation :** La fenêtre est devenue plus transparente qu'avant. On pouvait voir en partie ce qui se trouvait derrière la fenêtre c'est à dire mon editeur de code.

## Conclusion

Ces cinq tests m'ont permis de voir que les différents champs de `NkWindowConfig` permettent de modifier plusieurs caractéristiques de la fenêtre, comme sa position, sa taille et son apparence.
