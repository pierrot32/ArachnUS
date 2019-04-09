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

## Utilisation de le la carte openCr avec le programme de contrôle du robot
Voir le dossier Code/OpenCr pour la procédure d'installation et d'utilisation de code du robot

## Utilisation de la carte PCA9685 (branchements sur la carte openCr)
Voir le dossier Documentation électronique

## Uilisation du capteur de distance
Voir le dossier Documentation électronique

## Utilisation de l'interface:
Voir le dossier Code/python pour la procédure d'installation et d'utilisation de l'interface pour le contrôle du robot.




