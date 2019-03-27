/*************************************************** 
  Actualisation de l'ensemble des servos
 ****************************************************/
 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// L'adresse de la carte PCA9685 est 0x41.
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

//À valider:
#define SERVOMIN  300 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  450 // this is the 'maximum' pulse length count (out of 4096)
#define ANGLEMIN  0
#define ANGlEMAX  90
#define NBR_DE_SERVO 8

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

void initFctServo(int valeursAngle[]) {

  pwm.begin();
  pwm.setPWMFreq(60);  // Frequence de raffraichissement des servo est ~60 Hz

  int valeurMoy = ((SERVOMAX-SERVOMIN)/2)+SERVOMIN;


  for (int i=0; i<NBR_DE_SERVO; i++){
    valeursAngle[i] = pulseAAngle(valeurMoy); 
  }
  valeursAngle[0] = 80;
  valeursAngle[2] = 80;
  valeursAngle[6] = 80;
  updateServos(valeursAngle);
}
