/*********************************** Fonction de tests automatisés pour le calcul de l'angle************************************/

typedef struct angleRobot{
  float angleX = 0.0;
  float angleY = 0.0;
};

angleRobot atest;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Test #1 angle voulu 0 en x et en y
  atest = calculAngle(0,0,1);
  if (atest.angleX > -1 && atest.angleX < 1 && atest.angleY > -1 && atest.angleY < 1){
    Serial.println("Test #1 : RÉUSSI");
  }
  else{
    Serial.println("Test #1 : ÉCHOUÉ");
  }

  //Test #2 angle voulu: 90 en x et 0 en y
  atest = calculAngle(1,0,0);
  if (atest.angleX > 89.0 && atest.angleX < 91.0 && atest.angleY > -1.0 && atest.angleY < 1.0){
    Serial.println("Test #2 : RÉUSSI");
  }
  else{
    Serial.println("Test #2 : ÉCHOUÉ");
  }
  //Test #3 angle voulu: 0 en x et 90 en y
  atest = calculAngle(0,1,0);
  if (atest.angleX > -1.0 && atest.angleX < 1.0 && atest.angleY > 89.0 && atest.angleY < 91.0){
    Serial.println("Test #3 : RÉUSSI");
  }
  else{
    Serial.println("Test #3 : ÉCHOUÉ");
  }
  //Test #4 angle voulu: 45 en x et 45 en y
  atest = calculAngle(1,1,0);
  if (atest.angleX > 44.0 && atest.angleX < 46.0 && atest.angleY > 44.0 && atest.angleY < 46.0){
    Serial.println("Test #4 : RÉUSSI");
  }
  else{
    Serial.println("Test #4 : ÉCHOUÉ");
  }
  //Test #5 angle voulu: 45 en x et 0 en y
  atest = calculAngle(1,0,1);
  if (atest.angleX > 44.0 && atest.angleX < 46.0 && atest.angleY > -1.0 && atest.angleY < 1.0){
    Serial.println("Test #5 : RÉUSSI");
  }
  else{
    Serial.println("Test #5 : ÉCHOUÉ");
  }
  //Test #6 angle voulu: 0 en x et 45 en y
  atest = calculAngle(0,1,1);
  if (atest.angleX > -1.0 && atest.angleX < 1.0 && atest.angleY > 44.0 && atest.angleY < 46.0){
    Serial.println("Test #6 : RÉUSSI");
  }
  else{
    Serial.println("Test #6 : ÉCHOUÉ");
  }
  delay(2000);
}
