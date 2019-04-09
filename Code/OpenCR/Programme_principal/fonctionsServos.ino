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

int tabServoMin[NBR_DE_SERVO] = {300,300,320,300,300,300,300,350};
int tabServoMax[NBR_DE_SERVO] = {450,450,450,450,450,450,450,500};
int tabAngleMin[NBR_DE_SERVO] = {30,-40,30,-40,0,0,30,-40};
int tabAngleMax[NBR_DE_SERVO] = {80,10,80,10,0,0,80,10};

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

    for(int i = 0; i<NBR_DE_SERVO; i++){
      if(angleVoulu[i]<tabAngleMin[i]){
        angleVoulu[i]=tabAngleMin[i];
      } else if(angleVoulu[i]>tabAngleMax[i]){
        angleVoulu[i]=tabAngleMax[i];
      }
    }
    
    pwm.setPWM(0, 0, map(angleVoulu[0], tabAngleMin[0], tabAngleMax[0], tabServoMin[0], tabServoMax[0]));
    pwm.setPWM(1, 0, map(angleVoulu[1], tabAngleMax[1], tabAngleMin[1], tabServoMin[1], tabServoMax[1]));
    pwm.setPWM(2, 0, map(angleVoulu[2], tabAngleMin[2], tabAngleMax[2], tabServoMin[2], tabServoMax[2]));
    pwm.setPWM(3, 0, map(angleVoulu[3], tabAngleMax[3], tabAngleMin[3], tabServoMin[3], tabServoMax[3]));
    pwm.setPWM(4, 0, map(angleVoulu[4], tabAngleMin[4], tabAngleMax[4], tabServoMin[4], tabServoMax[4]));
    pwm.setPWM(5, 0, map(angleVoulu[5], tabAngleMin[5], tabAngleMax[5], tabServoMin[5], tabServoMax[5]));
    pwm.setPWM(6, 0, map(angleVoulu[6], tabAngleMin[6], tabAngleMax[6], tabServoMin[6], tabServoMax[6]));
    pwm.setPWM(7, 0, map(angleVoulu[7], tabAngleMax[7], tabAngleMin[7], tabServoMin[7], tabServoMax[7])); 
}

void initFctServo(int valeursAngle[]) {

  pwm.begin();
  pwm.setPWMFreq(60);  // Frequence de raffraichissement des servo est ~60 Hz

  updateServos(valeursAngle);
}
