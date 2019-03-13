/*************************************************** 
  Fonctions de mesure de la hauteur du robot à l'aide du capteur à ultrason HC-SR04
  Cette fonction a été prise sur le github de freenove: Freenove_Ultimate_Starter_kit_for_Arduino
  dans le pdf tutorial à la section concernant le capteur.
 ****************************************************/
#define MAX_DISTANCE 200 // Maximum sensor distance is rated at 400-500cm. 

float getSonar() {   
  // define the timeOut according to the maximum range. timeOut= 2*MAX_DISTANCE /100 /340 *1000000 = MAX_DISTANCE*58.8
  float timeOut = MAX_DISTANCE * 60;  
  int soundVelocity = 340; // define sound speed=340m/s 
  unsigned long pingTime;   
  float distance;   
  digitalWrite(trigPin, HIGH); // make trigPin output high level lasting for 10μs to triger HC_SR04,   
  delayMicroseconds(10);   
  digitalWrite(trigPin, LOW);   
  pingTime = pulseIn(echoPin, HIGH, timeOut); // Wait HC-SR04 returning to the high level and measure out this waitting time   
  distance = (float)pingTime * soundVelocity / 2 / 10000; // calculate the distance according to the time   return distance; // return the distance value 
} 
