### Exercice 5 : La composition - Vérification théorique

### 1. Cas de test choisi pour la vérification

Pour valider manuellement l'algorithme, nous avons utilisé les données simples suivantes : 

* **Pose A :** Déplacement de +2 sur l'axe X (Position: 2 0 0) et aucune rotation (Quaternion: 0 0 0 1).
* **Pose B :** Déplacement de +3 sur l'axe Y (Position: 0 3 0) et aucune rotation (Quaternion: 0 0 0 1).
* **Point initial :** Situé à l'origine (0 0 0).

### 2. Résultats des deux méthodes et calcul de l'écart

* **Méthode 1 (Appliquer l'une après l'autre) :** Le point se déplace d'abord en (0, 3, 0) avec la pose B, puis en (2, 3, 0) avec la pose A.
* **Méthode 2 (Composer d'abord puis appliquer) :** La pose globale combinée donne une translation totale de (2, 3, 0). Appliquée directement sur le point (0,0,0),
on obtient le même point final (2, 3, 0).

**Écart obtenu :** 0 (soit 0.000000). 

### 3. Conclusion

Les deux méthodes mènent exactement au même point dans l'espace. Cela confirme mathématiquement que la composition de deux transformations géométriques 
(Pose A ∘ Pose B) respecte parfaitement l'ordre d'application successif sur un objet en coordonnées 3D.
