/*************************************************** 
  Simple code de test pour valider les mouvements d'un des bras.
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// L'adresse de la carte PCA9685 est 0x41.
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

//À valider:
#define SERVOMINg  250 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAXg  450 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMINd  180
#define SERVOMAXd  450

// Compteur de servo
uint8_t servonum = 3;
String commande = String(NULL);
int valeurAngle = 0;
int valeurAngleG = 400;
int valeurAngleD = 300;

void setup() {
  Serial.begin(9600);
  Serial.println("Test physique d'un des bras");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Frequence de raffraichissement des servo est ~60 Hz

  delay(10);
  pwm.setPWM(0, 0, valeurAngleG);
  pwm.setPWM(1, 0, valeurAngleD);
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {

  while(Serial.available() > 0){
    commande = Serial.readStringUntil(',');
    valeurAngle = Serial.parseInt();
  }
  
  if(commande == "g"){
    servonum = 0;
    if(valeurAngle < SERVOMINg){
      valeurAngle = SERVOMINg; 
    } else if(valeurAngle > SERVOMAXg){
      valeurAngle = SERVOMAXg;
    }

    valeurAngleG = valeurAngle;
    pwm.setPWM(servonum, 0, valeurAngleG);
    
  } else if(commande == "d"){
    servonum = 1;
    if(valeurAngle < SERVOMINd){
      valeurAngle = SERVOMINd; 
    } else if(valeurAngle > SERVOMAXd){
      valeurAngle = SERVOMAXd;
    }

    valeurAngleD = valeurAngle;
    pwm.setPWM(servonum, 0, valeurAngleD);
  }
  
  delay(500);
  Serial.print("Gauche: ");
  Serial.print(valeurAngleG);
  Serial.print("  ///  Droite: ");
  Serial.println(valeurAngleD);
    

}









