Ici sont réunies les premier codes de tests et les informations sur le hardware que nous avons utilisé.

Ci-dessous une liste de références pour l'électronique du robot:

Guide d'utilisation du contrôleur PCA9685:
https://learn.adafruit.com/16-channel-pwm-servo-driver/overview

Guide d'utilisateur de la carte OpenCR:
http://emanual.robotis.com/docs/en/parts/controller/opencr10/
http://support.robotis.com/en/product/controller/opencr.htm?fbclid=IwAR3mdokLMNBJ61K55APRvNFKxcBc7fuHtkBBCOIlaJhQWwKeLr4MbHUsWKk

Fiches techniques :
Moteur MG996R : http://magicduino.com/Images/ItemsMedia/File/7203.pdf
Capteur de hauteur HC-SR04 :
La section utile au capteur est le chapitre 24 du tutoriel, c'est dans cette section que le code utilisé a été pris.
Cette section contient aussi les informations sur l'alimentation électrique du capteur.
https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_Arduino/blob/master/Tutorial.pdf

Pour l'installation de la carte OpenCR sur arduinoIDE (sur Windows): 
1) Fichier -> préférence -> URL de gestionnaire des cartes suppl. -> https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCR/master/arduino/opencr_release/package_opencr_index.json
2) Tools -> board -> board manager -> "opencr" dans la barre de recherche -> install
3) Tools -> board -> "OpenCR Board"
4) Tools -> port -> COMX (*une fois connecte)

Pour MAC ou autre, voir le guide d'utilisateur de la carte OpenCR^^

