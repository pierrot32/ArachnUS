typedef struct deltaAngleMoteurHauteur{
  float deltaAngleMoteur1 = 0;
  float deltaAngleMoteur2 = 0;
  float deltaAngleMoteur3 = 0; 
};
deltaAngleMoteurHauteur dMAngle;

typedef struct angleRobot{
  float angleX = 0.0;
  float angleY = 0.0;
};
angleRobot aRobot;


void setup() {
  Serial.begin(115200);
}

void loop() {

  // TEST #1
  aRobot.angleX = 0;
  aRobot.angleY = 0;
  dMAngle = stabilisationRobot(aRobot);
  if(dMAngle.deltaAngleMoteur1 == 0 && dMAngle.deltaAngleMoteur2 == 0 && dMAngle.deltaAngleMoteur3 == 0){
    Serial.println("Test #1 RÉUSSI");
  } else {
    Serial.println("Test #1 ÉCHOUÉ");    
  }

  // TEST #2
  aRobot.angleX = 0;
  aRobot.angleY = 1;
  dMAngle = stabilisationRobot(aRobot);
  if(dMAngle.deltaAngleMoteur1 > -2.78 - 0.01 && dMAngle.deltaAngleMoteur1 < -2.78 + 0.01 &&
       dMAngle.deltaAngleMoteur2 > 1.97 - 0.01 && dMAngle.deltaAngleMoteur2 < 1.97 + 0.01 &&
        dMAngle.deltaAngleMoteur3 > 1.97 - 0.01 && dMAngle.deltaAngleMoteur3 < 1.97 + 0.01){
    Serial.println("Test #2 RÉUSSI");
  } else {
    Serial.println("Test #2 ÉCHOUÉ");    
  }
  
  // TEST #3
  aRobot.angleX = 0;
  aRobot.angleY = -1;
  dMAngle = stabilisationRobot(aRobot);
  if(dMAngle.deltaAngleMoteur1 > 2.78 - 0.01 && dMAngle.deltaAngleMoteur1 < 2.78 + 0.01 &&
       dMAngle.deltaAngleMoteur2 > -1.97 - 0.01 && dMAngle.deltaAngleMoteur2 < -1.97 + 0.01 &&
        dMAngle.deltaAngleMoteur3 > -1.97 - 0.01 && dMAngle.deltaAngleMoteur3 < -1.97 + 0.01){
    Serial.println("Test #3 RÉUSSI");
  } else {
    Serial.println("Test #3 ÉCHOUÉ");   
  }

  // TEST #4
  aRobot.angleX = 1;
  aRobot.angleY = 0;
  dMAngle = stabilisationRobot(aRobot);
  if(dMAngle.deltaAngleMoteur1 > 0 - 0.01 && dMAngle.deltaAngleMoteur1 < 0 + 0.01 &&
       dMAngle.deltaAngleMoteur2 > -1.97 - 0.01 && dMAngle.deltaAngleMoteur2 < -1.97 + 0.01 &&
        dMAngle.deltaAngleMoteur3 > 1.97 - 0.01 && dMAngle.deltaAngleMoteur3 < 1.97 + 0.01){
    Serial.println("Test #4 RÉUSSI");
  } else {
    Serial.println("Test #4 ÉCHOUÉ");   
  }

  // TEST #5
  aRobot.angleX = -1;
  aRobot.angleY = 0;
  dMAngle = stabilisationRobot(aRobot);
  if(dMAngle.deltaAngleMoteur1 > 0 - 0.01 && dMAngle.deltaAngleMoteur1 < 0 + 0.01 &&
       dMAngle.deltaAngleMoteur2 > 1.97 - 0.01 && dMAngle.deltaAngleMoteur2 < 1.97 + 0.01 &&
        dMAngle.deltaAngleMoteur3 > -1.97 - 0.01 && dMAngle.deltaAngleMoteur3 < -1.97 + 0.01){
    Serial.println("Test #5 RÉUSSI");
  } else {
    Serial.println("Test #5 ÉCHOUÉ");   
  }

  // TEST #6
  aRobot.angleX = 1;
  aRobot.angleY = 1;
  dMAngle = stabilisationRobot(aRobot);
  if(dMAngle.deltaAngleMoteur1 > -2.78 - 0.01 && dMAngle.deltaAngleMoteur1 < -2.78 + 0.01 &&
       dMAngle.deltaAngleMoteur2 > 0 - 0.01 && dMAngle.deltaAngleMoteur2 < 0 + 0.01 &&
        dMAngle.deltaAngleMoteur3 > 3.93 - 0.01 && dMAngle.deltaAngleMoteur3 < 3.93 + 0.01){
    Serial.println("Test #6 RÉUSSI");
  } else {
    Serial.println("Test #6 ÉCHOUÉ");   
  }

  delay(2000);

}
