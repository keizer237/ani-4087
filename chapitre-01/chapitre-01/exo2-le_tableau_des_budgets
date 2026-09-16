## Rapport de vérification : Budget de latence Motion-to-Photon

# Étape 1 : Mesure des capteurs
- Valeur du tableau : 1 à 2 ms
- Statut : Vrai
- Justification & Sources : Les centrales inertielles (IMU) comme le modèle TDK InvenSense ICM-42688-P fonctionnent à une fréquence d’échantillonnage 
de 1 kHz, générant un point de donnée toutes les 1 ms. Le filtrage numérique interne ajoute environ 0.5 à 1 ms.

# Étape 2 : Transmission système
- Valeur du tableau : 1 à 3 ms
- Statut : Vrai
- Justification & Sources : Temps requis pour le transfert de données via le bus SPI (High-Speed) jusqu’au processeur, complété par le traitement d’interruption 
du kernel et la file d’attente du SDK OpenXR.

# Étape 3 : Décision et dessin de l’application
- Valeur du tableau : 5 à 11 ms
- Statut : Vrai
- Justification & Sources : Lié à la fréquence de rafraîchissement matérielle (Frame Budget). À 90 Hz, l’application dispose d’un temps de calcul maximal 
de 11.1 ms par image (Source : Documentation Unity / Unreal Engine – Frame Timing).

# Étape 4 : Assemblage du compositeur
- Valeur du tableau : 1 à 2 ms
- Statut : Vrai
- Justification & Sources : Délai de la phase de composition finale et d’application de l’algorithme Asynchronous TimeWarp (ATW) 
par le runtime du système d’exploitation juste avant l’envoi à l’écran.

# Étape 5 : Affichage de l’écran
- **Valeur du tableau : 2 à 5 ms
- Statut : Vrai
- Justification & Sources : Correspond au temps d’illumination des dalles à faible persistance (Low Persistence) OLED/LCD pour limiter la rémanence 
rétinienne (Source : Rapport d’analyse de métrologie OptoFidelity – MTP Latency).
