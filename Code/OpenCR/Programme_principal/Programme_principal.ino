
#define NBR_DE_SERVO 8
#define trigPin 12 // define TrigPin 
#define echoPin 11 // define EchoPin.
#include <IMU.h>

// variables globales

cIMU    IMU;

int initDone = 0;

typedef struct envoi{
//  long debut_struct;
  long etat;
  long moteur0;
  long moteur1;
  long moteur2;
  long moteur3;
  long moteur4;
  long moteur5;
  long moteur6;
  long moteur7;
  long hauteur;
  long angx;
  long angy;
};
envoi msg_Envoi;

int height[NBR_DE_SERVO];
int state[NBR_DE_SERVO];
byte buff[10*sizeof(long)];
int valeurs_Angles_moteurs[NBR_DE_SERVO];

// variables accél
typedef struct angleRobot{
  float angleX = 0.0;
  float angleY = 0.0;
};

angleRobot aRobot;

uint8_t   led_tog = 0;
uint8_t   led_pin = 13;

static uint32_t tTime[3];
static uint32_t imu_time = 0;

typedef struct deltaAngleMoteurHauteur{
  float deltaAngleMoteur1 = 0;
  float deltaAngleMoteur2 = 0;
  float deltaAngleMoteur3 = 0; 
};
deltaAngleMoteurHauteur dMAngle;

void setup() {
  Serial.begin(115200);
  IMU.begin();
  pinMode( led_pin, OUTPUT );
  pinMode(trigPin,OUTPUT);// set trigPin to output mode   
  pinMode(echoPin,INPUT); // set echoPin to input mode
  initFctServo(valeurs_Angles_moteurs);
}

void loop() {
  while(Serial.available() > 0){
    bool x;
    x = lecture(buff);
    copie_array_struc(buff,valeurs_Angles_moteurs, state, height);
  }

  switch(state[0]){
    case 0:
      initDone = 0;
      //etat arret fait rien
      break;
    case 1:
      //état d'initialisation
      msg_Envoi.etat = 1;
      initDone = 1;
      break;
    case 2:
      //etat manuel verifie si le robot a ete initialise, mais n'est pas encore necessaire puisque nous n'avons pas d'initialisation a faire pour l'instant
//      if (initDone == 0){
//        msg_Envoi.etat = 0;
//        break;
//        //init n'a pas été fait donc on ne peut entrer en mode manuel
//      }
//      else{
        msg_Envoi.etat = 2;
        updateServos(valeurs_Angles_moteurs);
        break;        
//        }

    case 3:
      //etat stabilisation appel des fonctions de calcul d'angle du robot
      msg_Envoi.etat = 3;
      if( (millis()-tTime[1]) >= 10 ){
        tTime[1] = millis();

        aRobot = calculAngle(IMU.accRaw[0],IMU.accRaw[1], IMU.accRaw[2]);
        dMAngle = stabilisationRobot(aRobot);
        if( valeurs_Angles_moteurs[7] + dMAngle.deltaAngleMoteur1>=0 && valeurs_Angles_moteurs[7] + dMAngle.deltaAngleMoteur1<= 90){
          valeurs_Angles_moteurs[7] = valeurs_Angles_moteurs[7] + dMAngle.deltaAngleMoteur1;
        }
        if( valeurs_Angles_moteurs[3]+ dMAngle.deltaAngleMoteur2>=0 && valeurs_Angles_moteurs[3]+ dMAngle.deltaAngleMoteur2<= 90){
          valeurs_Angles_moteurs[3] = valeurs_Angles_moteurs[3] + dMAngle.deltaAngleMoteur2;
        }
        if( valeurs_Angles_moteurs[1]+ dMAngle.deltaAngleMoteur3>=0 && valeurs_Angles_moteurs[1]+ dMAngle.deltaAngleMoteur3<= 90){
          valeurs_Angles_moteurs[1] = valeurs_Angles_moteurs[1] + dMAngle.deltaAngleMoteur3;
        }

        updateServos(valeurs_Angles_moteurs);
        
  }

      break;
    case 4:
      //etat modulation de la hauteur
      height[0] = int(getSonar());
      break;
  }
  envoi_serie(msg_Envoi,valeurs_Angles_moteurs);

  delay(100);
}