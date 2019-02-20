/*************************************************** 
  Actualisation de l'ensemble des servos
 ****************************************************/
 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// L'adresse de la carte PCA9685 est 0x41.
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

//À valider:
#define SERVOMIN  200 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  450 // this is the 'maximum' pulse length count (out of 4096)
#define ANGLEMIN  0
#define ANGlEMAX  145
#define NBR_DE_SERVO 8

// Compteur de servo
int numServo = NBR_DE_SERVO;
int angleVoulu = 0;
String commande = String(NULL);
int valeurMoy = ((SERVOMAX-SERVOMIN)/2)+SERVOMIN;
int valeursAngle[NBR_DE_SERVO];


// Convertie une consigne d'angle au moteur en une longueur de pulse pour le pwm
int angleAPulse(int angle) {
  if(angle<ANGLEMIN){
    angle = ANGLEMIN;
  } else if (angle>ANGlEMAX) {
    angle = ANGlEMAX;
  }
  return map(angle, ANGLEMIN, ANGlEMAX, SERVOMIN, SERVOMAX);
}

// Convertie une consigne de pulse au moteur en une valeur d'angle
int pulseAAngle(int pulse) {
  if(pulse<SERVOMIN){
    pulse = SERVOMIN;
  } else if (pulse>SERVOMAX){
    pulse = SERVOMAX;
  }
  return map(pulse, SERVOMIN, SERVOMAX, ANGLEMIN, ANGlEMAX);
}

// Actualise l'ensemble des servos un après l'autre
void updateServos(int angleVoulu[NBR_DE_SERVO]) {
  for (int i=0; i<NBR_DE_SERVO; i++){
    pwm.setPWM(i, 0, angleAPulse(angleVoulu[i])); 
  }
}


void setup() {
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(60);  // Frequence de raffraichissement des servo est ~60 Hz

  for (int i=0; i<NBR_DE_SERVO; i++){
    valeursAngle[i] = pulseAAngle(valeurMoy); 
  }
  updateServos(valeursAngle);
}

void loop() {

  while(Serial.available() > 0){
    numServo = Serial.parseInt();
    angleVoulu = Serial.parseInt();
  }
  valeursAngle[numServo] = angleVoulu;

  Serial.println("------------------------------------------------");
  for(int i=0; i<NBR_DE_SERVO; i++){
    Serial.print("Le moteur #");
    Serial.print(i);
    Serial.print(" est a ");
    Serial.print(valeursAngle[i]);
    Serial.println(" degrees");
  }

  delay(100);   

}
