## Je tourne puis j'avance:
L'objet effectue une rotation sur lui même, puis se déplace vers l'avant dans la nouvelles direction vers laquelle il pointe.

# Resultats:
l'objet est déplacer sur un axe incliner par rapport au point de depart.

## J'avance puis je tourne:
L'objet avance en ligne droite de sa direction initiale, puis une fois a sa nouvelle position effectue une rotation sur lui meme.

# Resultats:
L'objet se retrouve sur le même axe direct que le point de départ mais avec une orientation differente.


### Cas 1 : "Je tourne puis j'avance"
- **Étape 1 (Tourner à gauche) :** L'orientation change vers la **Gauche**. Position : `(0, 0)`.
- **Étape 2 (Avancer de 5 pas) :** L'objet se déplace sur l'axe X négatif.
- **Résultat Final :** Position **(-5, 0)**, Direction : **Gauche**.

### Cas 2 : "J'avance puis je tourne"
- **Étape 1 (Avancer de 5 pas) :** L'objet progresse sur l'axe Y positif. Position : `(0, 5)`.
- **Étape 2 (Tourner à gauche) :** L'orientation finale change vers la **Gauche**.
- **Résultat Final :** Position **(0, 5)**, Direction : **Gauche**.

## 2. Conclusion Mathématique

L'orientation finale est identique (`Gauche`), mais les coordonnées finales sont complètement distinctes :
- Cas 1 : `(-5, 0)` 
- Cas 2 : `(0, 5)` 

Cela prouve de façon définitive que les transformations géométriques (les matrices de rotation et de translation) ne sont **pas commutatives**.
