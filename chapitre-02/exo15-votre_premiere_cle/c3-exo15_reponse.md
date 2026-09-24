# Réponse Exercice 15 - Votre première clé de signature

### 1. Commande employée pour la génération
Pour fabriquer la clé de signature de manière sécurisée avec l'algorithme RSA, la commande standard suivante a été exécutée (le mot de passe a été omis de la ligne de commande pour des raisons évidentes de sécurité) :

```bash
jenga keygen --allias Salle-key --output monapp.keystore
```

### 2. Emplacement de stockage du mot de passe
Afin de ne jamais exposer les identifiants de production dans le dépôt public GitHub (ce qui représenterait une faille de sécurité majeure), le mot de passe fort associé à cette clé de signature ainsi que son alias ont été consignés et sauvegardés de manière totalement externe au projet :
* **Stockage sécurisé :** Les informations ont été enregistrées localement dans un gestionnaire de mots de passe sécurisé et chiffré (type *KeePass* / *Bitwarden*).
* **Fichier de secours local :** Une copie physique locale hors-ligne a été placée dans un répertoire utilisateur privé sur la machine hôte (`C:\Users\Bouetou\.security\`), un dossier qui est strictement exclu de tout suivi Git via le fichier `.gitignore`.