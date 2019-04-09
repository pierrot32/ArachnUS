##  Guide d'utilisateur de la carte OpenCR:
http://emanual.robotis.com/docs/en/parts/controller/opencr10/
http://support.robotis.com/en/product/controller/opencr.htm?fbclid=IwAR3mdokLMNBJ61K55APRvNFKxcBc7fuHtkBBCOIlaJhQWwKeLr4MbHUsWKk

## OpenCR et PCA9685:
Pour utiliser la carte OpenCR dans notre appliquation, il faut:
1. Télécharger arduinoIDE
2. Télécharger la carte "OpenCR" dans arduinoIDE 
  a) Fichier -> préférence -> URL de gestionnaire des cartes suppl. -> https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCR/master/arduino/opencr_release/package_opencr_index.json
  b) Tools -> board -> board manager -> "opencr" dans la barre de recherche -> install
  c) Tools -> board -> "OpenCR Board"
  d) Tools -> port -> COMX (*une fois connecte)
3. Télécharger la librairie "adafruit servo" dans arduinoIDE
4. Assembler la carte PCA9685 (https://learn.adafruit.com/16-channel-pwm-servo-driver/assembly)
5. Faire les connections électriques entre le PCA9685, le OpenCR et les servos moteur (https://learn.adafruit.com/16-channel-pwm-servo-driver/hooking-it-up)
6. Connecter l'alimentation externe
7. Connecter la prise USB et téléverser le programme "Programme principal"

*NOTE*: Toujours brancher l'alimentation externe avant de brancher le cable USB



