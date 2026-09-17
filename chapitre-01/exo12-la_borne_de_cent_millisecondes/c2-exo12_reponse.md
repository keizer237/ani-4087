### Exercice 12 : La borne de cent millisecondes

### 1. Comportement de la courbe d'erreur

* **Entre 10 ms et 100 ms :** L'erreur d'extrapolation est très faible, presque invisible. Les prédictions restent proches de la réalité.
* **Au-delà de 100 ms :** L'erreur commence à augmenter de manière exponentielle. À l'approche de la seconde, la trajectoire extrapolée dévie complètement
* de la trajectoire réelle (la vraie pose).

### 2. Pourquoi la borne de 100 ms se justifie ?

L'extrapolation linéaire de l'orientation (vitesse angulaire constante) suppose que la tête continue de tourner indéfiniment sur le même axe à la même vitesse, 
sans jamais s'arrêter ni freiner. 

Dans la réalité des mouvements humains : 

* **Sous la barre des 100 ms :** Le cerveau n'a pas encore le temps d'envoyer un nouveau signal moteur pour corriger, freiner ou changer la direction du mouvement
*  de la tête. L'extrapolation mathématique reste donc temporairement valide.
* **Au-delà de 100 ms :** L'inertie physique, les muscles du cou et les changements d'intention de l'utilisateur ralentissent ou dévient la trajectoire réelle.
L'extrapolation basée sur le passé devient alors complètement fausse et obsolète. C'est pourquoi la prédiction de mouvement en VR ne doit jamais dépasser cette limite de 100 ms sous peine de provoquer de fortes nausées.
