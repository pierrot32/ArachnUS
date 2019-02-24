
#define NBR_DE_SERVO 8
// variables globales
int initDone = 0;

typedef struct recoit{
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
};
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
  long angz;
};

envoi msg_Envoi;
recoit msg_Recu;
int height[NBR_DE_SERVO];
int state[NBR_DE_SERVO];
byte buff[sizeof(msg_Recu)];
int valeurs_Angles_moteurs[NBR_DE_SERVO];

void setup() {
Serial.begin(115200);
initFctServo(valeurs_Angles_moteurs);
}

void loop() {
  while(Serial.available() > 0){
    bool x;
    x = lecture(buff);
    copie_array_struc(&msg_Recu, buff,valeurs_Angles_moteurs, state, height);
  }
//  Serial.println("\nmoteur0");
//  Serial.println(valeurs_Angles_moteurs[0]);
  switch(state[0]){
    case 0:
      initDone = 0;
      //etat arret fait rien
      break;
    case 1:
//      msg_Envoi.etat = 1;
      //etat init
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
//        msg_Envoi.etat = 2;
        updateServos(valeurs_Angles_moteurs);
        break;        
//        }

/*    case 3:
      //etat à venir

      break;
    case 4:
      //etat à venir

      break;
    case 5:
      //etat à venir

      break;*/
  }
  envoi_serie(msg_Envoi,valeurs_Angles_moteurs);
//  Serial.println("envoi");
//  Serial.println(MSG_Envoi.moteur0);
//  Serial.println("envoi");
//  Serial.println(MSG_Envoi.etat);
//  Serial.println(MSG_Envoi.moteur0);
//  Serial.println(MSG_Envoi.moteur1);
//  Serial.println(MSG_Envoi.moteur2);
//  Serial.println(MSG_Envoi.moteur3);
//  Serial.println(MSG_Envoi.moteur4);
//  Serial.println(MSG_Envoi.moteur5);
//  Serial.println(MSG_Envoi.moteur6);
//  Serial.println(MSG_Envoi.moteur7);
  delay(100);
}

//fonction de lecture des données envoyées du PC à la carte (stocke toutes les données dans un buffer)
bool lecture(byte *buf){
  return(Serial.readBytes((char*)buf, sizeof(recoit))==sizeof(recoit)); 
}

//fonction de copie d'un byte array dans une struc et création du tableau de valeurs des angles des moteurs à partir du byte array
void copie_array_struc(recoit *MSG, byte *buf, int valeurs_angles[], int state[], int hauteur[]){
  long tableau[NBR_DE_SERVO+2];
  memcpy(&MSG, buf, sizeof(MSG));
//  memcpy(&state, buf+=sizeof(long), sizeof(long));
  memcpy(tableau, buf, sizeof(tableau));
  state[0] = (int)tableau[0];
  for (int i=0; i<NBR_DE_SERVO;i++){
    valeurs_angles[i] = (int)tableau[i+1];
  }
  hauteur[0] = (int)tableau[NBR_DE_SERVO+1];
}

//fontion d'envoi des données de la carte openCR au PC
void envoi_serie(envoi MSG, int valeurs_moteurs[NBR_DE_SERVO]){
  msg_Envoi.etat = state[0];
  msg_Envoi.hauteur = height[0];
  MSG.moteur0 = valeurs_moteurs[0];
  MSG.moteur1 = valeurs_moteurs[1];
  MSG.moteur2 = valeurs_moteurs[2];
  MSG.moteur3 = valeurs_moteurs[3];
  MSG.moteur4 = valeurs_moteurs[4];
  MSG.moteur5 = valeurs_moteurs[5];
  MSG.moteur6 = valeurs_moteurs[6];
  MSG.moteur7 = valeurs_moteurs[7];
  Serial.write((uint8_t*)&MSG, sizeof(MSG));
}
