
#define NBR_DE_SERVO 8
#define coeffFiltre 4
#include <IMU.h>

// variables globales

cIMU    IMU;

int initDone = 0;

float filtriMot0[coeffFiltre];
float filtreMot1[coeffFiltre];
float filtreMot2[coeffFiltre];
float filtreMot3[coeffFiltre];
float filtreMot6[coeffFiltre];
float filtreMot7[coeffFiltre];

int moteur0 = 0;
int moteur1 = 0;
int moteur2 = 0;
int moteur3 = 0;
int moteur6 = 0;
int moteur7 = 0;

int indexCirculaire = 0;

int hauteurInitial = 50; //hauteurs initials du robot en mm

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

int delta_hauteur;
int height[NBR_DE_SERVO];
int hauteurActuelle;
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
uint8_t   trigPin = 12;
uint8_t   echoPin = 11;


static uint32_t timePidMoteur = 100; //ms
static uint32_t timeMoteur[3];


static uint32_t tTime[3];
static uint32_t imu_time = 0;

typedef struct deltaPosPattes{
  float deltaPosPatte1 = 0;
  float deltaPosPatte2 = 0;
  float deltaPosPatte3 = 0; 
};

deltaPosPattes dMPos;

void setup() {
  Serial.begin(115200);
  IMU.begin();
  pinMode( led_pin, OUTPUT );
  pinMode(trigPin,OUTPUT);// set trigPin to output mode   
  pinMode(echoPin,INPUT); // set echoPin to input mode
  initFctServo(valeurs_Angles_moteurs);
  for (int i=0;i<coeffFiltre;i++){
    filtreMot1[i] = 0;
    filtreMot2[i] = 0;
    filtreMot3[i] = 0;
  }
  
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
      // aRobot est les angles en x et en y du robot
      aRobot = calculAngle(IMU.accRaw[0],IMU.accRaw[1], IMU.accRaw[2]);
      
      // dmPos est le delta position de chaque moteur pour stabiliser le robot
      dMPos = stabilisationRobot(aRobot);
      
      
      // Calcul de la hauteur actuelle
      hauteurActuelle = int(getSonar());
      
      // deltaHauteur est la différence entre la hauteur présente et la haute voulue
      // Calcul du deltaHauteur
      deltaHauteur = height[0] - hauteurActuelle;
      
      // On ajoute la variation de hauteur
      dMPos.deltaPosPatte1 += deltaHauteur;
      dMPos.deltaPosPatte2 += deltaHauteur;
      dMPos.deltaPosPatte3 += deltaHauteur;
      
      // On calcule la nouvelle position 
      [moteur0, moteur1] = CALCUL CINÉMATIQUE(posMoteur0Voulue, posMoteur1Voulue];
      [moteur2, moteur3] = CALCUL CINÉMATIQUE(posMoteur2Voulue, posMoteur3Voulue];
      [moteur6, moteur7] = CALCUL CINÉMATIQUE(posMoteur6Voulue, posMoteur7Voulue];
      
      // On s'assure que les limites d'angle envoyé aux moteurs sont respecté
      if( moteur0<0 ){
        moteur0 = 0;
      }else if( moteur0>90){
        moteur0 = 90
      }
      if( moteur1<0 ){
        moteur1 = 0;
      }else if( moteur1>90){
        moteur1 = 90
      }
      if( moteur2<0 ){
        moteur2 = 0;
      }else if( moteur2>90){
        moteur2 = 90
      }
      if( moteur3<0 ){
        moteur3 = 0;
      }else if( moteur3>90){
        moteur3 = 90
      }
      if( moteur6<0 ){
        moteur6 = 0;
      }else if( moteur6>90){
        moteur6 = 90
      }
      if( moteur7<0 ){
        moteur7 = 0;
      }else if( moteur7>90){
        moteur7 = 90
      }
      
      if (indexCirculaire>=coeffFiltre){
        indexCirculaire++;
      } else {
        indexCirculaire = 0;
      }
      
      // On entre les nouvelles valeurs de moteur dans le tableau du filtre
      filtreMot0[indexCirculaire] = moteur0;
      filtreMot1[indexCirculaire] = moteur1;
      filtreMot2[indexCirculaire] = moteur2;
      filtreMot3[indexCirculaire] = moteur3;
      filtreMot6[indexCirculaire] = moteur6;
      filtreMot7[indexCirculaire] = moteur7;
      
      // Calcul des filtres pour avoir la bonne sortie pour envoyer la commande au moteur
      valeurs_Angles_moteurs[0] = filtreMoyenneMobile(filtreMot0, coeffFiltre);
      valeurs_Angles_moteurs[1] = filtreMoyenneMobile(filtreMot1, coeffFiltre);
      valeurs_Angles_moteurs[2] = filtreMoyenneMobile(filtreMot2, coeffFiltre);
      valeurs_Angles_moteurs[3] = filtreMoyenneMobile(filtreMot3, coeffFiltre);
      valeurs_Angles_moteurs[6] = filtreMoyenneMobile(filtreMot6, coeffFiltre);
      valeurs_Angles_moteurs[7] = filtreMoyenneMobile(filtreMot7, coeffFiltre);
      
      // Envois de la commande aux moteurs
      updateServos(valeurs_Angles_moteurs);

        
  //}

      break;
    case 4:
    // LE CASE 4 NE SERT À RIEN
//      //etat modulation de la hauteur
//      hauteur_actuelle = int(getSonar());
//      Serial.print("Hauteur :\t"); //écriture dans le port série pour la vérification du fonctionnement du capteur
//      Serial.println(hauteur_actuelle);
//      delta_hauteur = height[0] - hauteur_actuelle; //Permet de déterminer la différence de hauteur (positive ou négative) entre la hauteur demandée et la hauteur actuelle
//      //valeurs_Angles_moteurs = cinematique(deltax = 0, delta_hauteur, valeurs_Angles_moteurs);// Passer le delta_hauteur en paramètres à la fonction de traduction en commandes moteur 
//      updateServos(valeurs_Angles_moteurs);// Envoi des commandes à la fonction d'ajustement de la position des servos
      break;
  }
  //hauteur_actuelle = int(getSonar());
  if( (millis()-tTime[1]) >= 100 ){
    tTime[1] = millis();
    envoi_serie(msg_Envoi,valeurs_Angles_moteurs);
  }

  delay(20);
}


