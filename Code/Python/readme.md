## Installation de python
1.  Télécharger python 3.7
2.  Télécharger Pycharm (ou autre environnement de programmation en python)
3.  Ajouter les librairies suivantes: pip (19.0.1), numpy (1.16.1), pyserial (3.4) et matplotlib (3.0.3)

## Ajustement du code pour utilisation de la communication en l'ordinateur et la carte oprenCR
1.  Veuillez vérifier que le code utilise le bon port USB de votre ordinateur ('COM3')
    a)  Ouvrir arduinoIDE
    b)  Brancher la carte openCR
    c)  Outil(barre de menu) -> port -> Noter le port
2. Ajuster le code de communication
  a)  Ouvrir le fichier communication.py à l'aide de pycharm
  b)  Voir ligne 119
  c)  Changer COM3 par le port utilisé par votre ordinateur
    
##  Utilisation de l'interface
1.  Ouvrir le fichier Main.py
2.  S'assurer que la carte openCR est branché sur l'ordinateur
3.  Exécuter le code
4.  Le robot démarre en mode arrêt
5.  Changer le mode à manuel pour le contrôle individuel de chaque moteur
6.  ...
