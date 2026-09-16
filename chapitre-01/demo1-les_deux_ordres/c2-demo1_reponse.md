

### Cas 1 : "Je tourne puis j'avance"
- **Étape 1 (Tourner à gauche) :** L'orientation change vers la **Gauche**. Position : `(0, 0)`.
- **Étape 2 (Avancer de 5 pas) :** L'objet se déplace sur l'axe X négatif.
- **Résultat Final :** Position **(-5, 0)**, Direction : **Gauche**.

### Cas 2 : "J'avance puis je tourne"
- **Étape 1 (Avancer de 5 pas) :** L'objet progresse sur l'axe Y positif. Position : `(0, 5)`.
- **Étape 2 (Tourner à gauche) :** L'orientation finale change vers la **Gauche**.
- **Résultat Final :** Position **(0, 5)**, Direction : **Gauche**.

## 2. Conclusion Mathématique

L'orientation finale est identique (`Gauche`), mais les coordonnées bien distinct :
- Cas 1 : `(-5, 0)` 
- Cas 2 : `(0, 5)` 
L'ordre des instructions change complètement le résultats final
Cela prouve de façon définitive que les transformations géométriques (les matrices de rotation et de translation) ne sont **pas commutatives**.
