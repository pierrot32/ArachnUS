#define angleEntrePattesAvantEtArriere 135 //À changer
#define angleEntrePattesArrieres 90 //À changer

#define distanceMilieuRobotAxeRotPatte 82.77
#define distanceSupportPatte 76.78

float anglePatteArriereGauche = 0;
float anglePatteArriereDroite = 0;

float angleAxeXPatte1 = 0;
float angleAxeXPatte2 = 45;
float angleAxeXPatte3 = -45;

typedef struct angleRobot{
  float angleX = 0.0;
  float angleY = 0.0;
};
angleRobot aRobot;

typedef struct deltaAngleMoteurHauteur{
  float deltaAngleMoteur1 = 0;
  float deltaAngleMoteur2 = 0;
  float deltaAngleMoteur3 = 0; 
};
deltaAngleMoteurHauteur dMAngle;



void setup() {
  Serial.begin(115200);
}

void loop() {

    dMAngle = stabilisationRobot(aRobot);



    Serial.print("distance patte 1 :"); 
    Serial.print(dMAngle.deltaAngleMoteur1);
    Serial.print(" \t");
    Serial.print("distance patte 2 :"); 
    Serial.print(dMAngle.deltaAngleMoteur2);
    Serial.print(" \t");
    Serial.print("distance patte 3 :"); 
    Serial.print(dMAngle.deltaAngleMoteur3);
    Serial.println(" ");  

  delay(1000);
}

deltaAngleMoteurHauteur stabilisationRobot(angleRobot aRobot2){

    deltaAngleMoteurHauteur dMAngle2;
  
//Calculs des delta hauteur pour la stabilisation en X du robot
    float distanceEnXPatte2 = sin(angleAxeXPatte2*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);
    float distanceEnXPatte3 = sin(angleAxeXPatte3*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);

    float deltaHauteurXPatte1 = 0;
    float deltaHauteurXPatte2 = sin(aRobot2.angleX*3.14/180)*(distanceEnXPatte2);
    float deltaHauteurXPatte3 = sin(aRobot2.angleX*3.14/180)*(distanceEnXPatte3);

//Calculs des delta hauteur pour la stabilisation en Y du robot
    float distanceEnYPatte1 = (distanceMilieuRobotAxeRotPatte+distanceSupportPatte);
    float distanceEnYPatte2 = -cos(angleAxeXPatte2*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);
    float distanceEnYPatte3 = -cos(angleAxeXPatte3*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);
    
    float deltaHauteurYPatte1 = sin(aRobot2.angleY*3.14/180)*(distanceEnYPatte1);
    float deltaHauteurYPatte2 = sin(aRobot2.angleY*3.14/180)*(distanceEnYPatte2);
    float deltaHauteurYPatte3 = sin(aRobot2.angleY*3.14/180)*(distanceEnYPatte3);

//Calculs des delta hauteur pour la stabilisation totale du robot

    float deltaHauteurPatte1 = deltaHauteurXPatte1 + deltaHauteurYPatte1;
    float deltaHauteurPatte2 = deltaHauteurXPatte2 + deltaHauteurYPatte2;
    float deltaHauteurPatte3 = deltaHauteurXPatte3 + deltaHauteurYPatte3;

    dMAngle2.deltaAngleMoteur1 = (int)(deltaHauteurPatte1/2);
    dMAngle2.deltaAngleMoteur2 = (int)(deltaHauteurPatte2/2);
    dMAngle2.deltaAngleMoteur3 = (int)(deltaHauteurPatte3/2);

    return dMAngle2; 
}







