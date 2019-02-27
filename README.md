# ArachnUS
Projet de conception d'un robot araignée à 3 pattes.


## CAD:
Fichier RobotCAD contient toutes les informations pour imprimer ou modifier les pièces du robot avec le logiciel Solidworks.

Plus d'informations sont données dans le fichier.

## OpenCR et PCA9685:
Pour utiliser la carte OpenCR dans notre appliquation, il faut:
1. Télécharger arduinoIDE
2. Télécharger la carte "OpenCR" dans arduinoIDE (voir documentationElectronique)
3. Télécharger la librairie "adafruit servo" dans arduinoIDE
4. Assembler la carte PCA9685 (https://learn.adafruit.com/16-channel-pwm-servo-driver/assembly)
5. Faire les connections électriques entre le PCA9685, le OpenCR et les servos moteur (https://learn.adafruit.com/16-channel-pwm-servo-driver/hooking-it-up)
6. Connecter l'alimentation externe
7. Connecter la prise USB et téléverser les codes

*NOTE*: Toujours brancher l'alimentation externe avant de brancher le cable USB

## Python:
Pour utiliser la communication entre l'interface et l'openCR, il faut
1.  Télécharger python 3.7
2.  Télécharger Pycharm
3.  Ajouter les package suivant: pip, numpy et pyserial
4.  Veuillez vérifier que le code utilise le bon port USB de votre ordinateur ('COM3')

Pour utiliser l'interface utilisateur, il faut
1. Ouvrir le fichier Main.py
2. Exécuter le code




