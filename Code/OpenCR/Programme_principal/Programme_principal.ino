/*
 * Le programme ci-dessous à été réalisé par l'équipe d'ARACHNUS
 * dans la cadre d'un cours de projet en génie robotique
 * de l'université de Sherbrooke (S4-GRO).
 */


/*************************************************** 
  Programme principal pour le contrôle du robot
 ****************************************************/

#include <IMU.h>                                    // Librairie pour l'utilisation de l'accéléromètre

#define NBR_DE_SERVO 8                              // Nombre de servo moteur utilisé pour le robot

cIMU    IMU;                                        // Objet pour utilisation de l'acéléromètre

int initDone = 0;                                   // Variable pour savoir si l'initialisation est fait

//*****CONSTANTES ET VARIABLES POUR FILTRE DES MOTEURS*****//
#define coeffFiltre 7                               // Nombre de coefficient utilisé pour le filtre FIR à moyenne mobile
float filtreMot1[coeffFiltre];                      // Les entrée du filtre à moyenne mobile pour le moteur côté vert de la patte 1
float filtreMot2[coeffFiltre];                      // Les entrée du filtre à moyenne mobile pour le moteur côté vert de la patte 2
float filtreMot3[coeffFiltre];                      // Les entrée du filtre à moyenne mobile pour le moteur côté vert de la patte 3
int indexCirculaire = 0;                            // Index pour entrée les angles calculé dans la bonne case du tableau des filtres des différents moteurs

int moyenneFiltreMoteur1 = 0;                       // Moyenne mobile calculé pour le moteur côté vert de la patte 1
int moyenneFiltreMoteur2 = 0;                       // Moyenne mobile calculé pour le moteur côté vert de la patte 2
int moyenneFiltreMoteur3 = 0;                       // Moyenne mobile calculé pour le moteur côté vert de la patte 3


//*****STRUCTURE POUR COMMUNICATION ENTRE OPENCR ET ORDINATEUR PAR PORT SERIAL*****//
// La structure envoi est celle utilisé pour la communication par le port serial vers l'ordinateur
typedef struct envoi{
  long etat;
  long moteur0;                                     // Angle présente du moteur côté bleu de la patte 1
  long moteur1;                                     // Angle présente du moteur côté vert de la patte 1
  long moteur2;                                     // Angle présente du moteur côté bleu de la patte 2
  long moteur3;                                     // Angle présente du moteur côté vert de la patte 2
  long moteur4;                                     // Angle présente du moteur de sélection de l'angle de la patte 1
  long moteur5;                                     // Angle présente du moteur de sélection de l'angle de la patte 2
  long moteur6;                                     // Angle présente du moteur côté bleu de la patte 3
  long moteur7;                                     // Angle présente du moteur côté vert de la patte 3
  long hauteur;                                     // Hauteur entre le sol et le robot trouver à l'aide du capteur de hauteur
  long angx;                                        // Angle x du robot
  long angy;                                        // Angle y du robot
};
envoi msg_Envoi;                                    // Objet pour le message d'envoi vers le robt

//*****VARIABLES POUR LE CALCUL DE LA HAUTEURS DU ROBOT*****//
int delta_hauteur;                                  // Le changement de hauteur du robot pour atteindre celle désirée
int hauteur_actuelle;                               // Hauteur actuelle trouvé avec le capteur de hauteur




//*****VARIABLES POUR RECEVOIR LA STRUCUTRE DE COMMUNICATION*****//
byte buff[10*sizeof(long)];                         // Grandeur de la structure reçu lors de la communication avec l'ordinateur
int state[NBR_DE_SERVO];                            // État voulue (Sélectionné par l'interface lors de la communication) (Doit être dans un tableau pour le bon fonctionnement par communication par structure)
int height[NBR_DE_SERVO];                           // Hauteur voulue (Sélectionné par l'interface lors de la communication) (Doit être dans un tableau pour le bon fonctionnement par communication par structure)
int valeurs_Angles_moteurs[NBR_DE_SERVO];           // Valeur d'angle au moteur pour initialisation, état manuel et lors du calcul de stabilisation


//*****STRUCUTURE POUR LE CALCUL D'ANGLE DU ROBOT*****//
typedef struct angleRobot{
  float angleX = 0.0;                               // Angle en x du robot
  float angleY = 0.0;                               // Angle en y du robot
};
angleRobot aRobot;                                  // Objet utilisé pour le calcul de l'angle du robot

//*****PIN POUR LE CAPTEUR DE HAUTEUR*****//
uint8_t   trigPin = 12;
uint8_t   echoPin = 11;

//*****VARIABLES DE TEMPS*****//
static uint32_t tTime[3];                           // Tableau qui contient différents temps calculé
static uint32_t imu_time = 0;                       // Temps de la dernière fois que l'accéléromètre à été utilisé

//*****VARIABLE POUR LE CALCUL DU CHANGENT D'ANGLE POUR LA STABILISATION DU ROBOT*****//
typedef struct deltaAngleMoteurHauteur{
  float deltaAngleMoteur1 = 0;                      // Changment d'angle du moteur côté vert de la patte 1
  float deltaAngleMoteur2 = 0;                      // Changment d'angle du moteur côté vert de la patte 2
  float deltaAngleMoteur3 = 0;                      // Changment d'angle du moteur côté vert de la patte 3 
};
deltaAngleMoteurHauteur dMAngle;                    // Objet pou rle calcul lors de la stabilisation

void envoi_serie(envoi MSG, int valeurs_moteurs[NBR_DE_SERVO]);

//*****SETUP DU RU PROGRAMME*****//
void setup() {
  Serial.begin(115200);
  IMU.begin();
  pinMode(trigPin,OUTPUT);// set trigPin to output mode   
  pinMode(echoPin,INPUT); // set echoPin to input mode
  initFctServo(valeurs_Angles_moteurs);
  for (int i=0;i<coeffFiltre;i++){
    filtreMot1[i] = 0;
    filtreMot2[i] = 0;
    filtreMot3[i] = 0;
  }
  
}





//*****LOOP DU PROGRAMME*****/
void loop() {
  //Boucle de communication//
  // La carte fait la lecture du port sérial tant que des structures son disponible
  while(Serial.available() > 0){
    if(lecture(buff)){
      copie_array_struc(buff,valeurs_Angles_moteurs, state, height);
    }
  }

  //Machine à état fini pour sélection de l'état du robot
  switch(state[0]){
    
    //État d'arrêt//
    case 0:
      // Rien ne se produit dans cet état
      initDone = 0;
      break;

    //État d'initialisation//
    case 1:
      // Rien ne se produit pour l'instant dans cet état.
      msg_Envoi.etat = 1;
      initDone = 1;
      break;

    //État manuel//
    case 2:
      // Contrôle des moteurs à l'aide de l'interface
      msg_Envoi.etat = 2;
      updateServos(valeurs_Angles_moteurs);
        break;        

    //État de stabilisation//
    case 3:
      // Stabilisation automatique du robot (n'inclus pas la cinématique inverse dans cette version)
      msg_Envoi.etat = 3;

        // Calcul de l'angle du robot
        aRobot = calculAngle(IMU.accRaw[0],IMU.accRaw[1], IMU.accRaw[2]);

        // Calcul des variations d'angle des trois moteur de position en y du robot
        dMAngle = stabilisationRobot(aRobot);

        // Mise à jour de la hauteur actuelle du robot
        hauteur_actuelle = int(getSonar());

        // Ajout des nouvelle valeurs calculé au filtre (avec varition de hauteurs)
        filtreMot1[indexCirculaire] = dMAngle.deltaAngleMoteur1 + (height[0]-hauteur_actuelle);
        filtreMot2[indexCirculaire] = dMAngle.deltaAngleMoteur2 + (height[0]-hauteur_actuelle);
        filtreMot3[indexCirculaire] = dMAngle.deltaAngleMoteur3 + (height[0]-hauteur_actuelle);

        // Mise à jour de l'index pour l'ajout des données aux filtres des moteurs
        if (indexCirculaire>=coeffFiltre){
          indexCirculaire++;
        } else {
          indexCirculaire = 0;
        }

        // Calcul de la moyenne mobile des moteurs
        moyenneFiltreMoteur1 = filtreMoyenneMobile(filtreMot1, coeffFiltre);
        moyenneFiltreMoteur2 = filtreMoyenneMobile(filtreMot2, coeffFiltre);
        moyenneFiltreMoteur3 = filtreMoyenneMobile(filtreMot3, coeffFiltre);
        
        // Limites de chaque moteurs
        if( valeurs_Angles_moteurs[7] + moyenneFiltreMoteur1>=0 && valeurs_Angles_moteurs[7] + moyenneFiltreMoteur1<= 90){
          valeurs_Angles_moteurs[7] = valeurs_Angles_moteurs[7] + moyenneFiltreMoteur1;
        }
        if( valeurs_Angles_moteurs[3]+ moyenneFiltreMoteur2>=0 && valeurs_Angles_moteurs[3]+ moyenneFiltreMoteur2<= 90){
          valeurs_Angles_moteurs[3] = valeurs_Angles_moteurs[3] + moyenneFiltreMoteur2;
        }
        if( valeurs_Angles_moteurs[1]+ moyenneFiltreMoteur3>=0 && valeurs_Angles_moteurs[1]+ moyenneFiltreMoteur3<= 90){
          valeurs_Angles_moteurs[1] = valeurs_Angles_moteurs[1] + moyenneFiltreMoteur3;
        } 
               
        // Update des servos moteurs
        updateServos(valeurs_Angles_moteurs);

      break;

  }

  // Envois des données vers l'interface à chaque 100 ms
  if( (millis()-tTime[1]) >= 100 ){
    tTime[1] = millis();
    envoi_serie(msg_Envoi,valeurs_Angles_moteurs);
  }

  // Délais de 20 ms entre chaque loop
  delay(20);
}


