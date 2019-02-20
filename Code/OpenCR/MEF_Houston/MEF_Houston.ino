
#define NBR_DE_SERVO 8
// variables globales
int initDone = 0;

typedef struct message{
  long etat;
  long moteur0;
  long moteur1;
  long moteur2;
  long moteur3;
  long moteur4;
  long moteur5;
  long moteur6;
  long moteur7;
  long angx;
  long angy;
  long angz;
  long hauteur;
};
message MSG_Envoi;
message MSG_Recu;
byte buff[sizeof(MSG_Recu)];
int valeurs_Angles_moteurs[NBR_DE_SERVO];

void setup() {
Serial.begin(115200);
initFctServo(valeurs_Angles_moteurs);
}

void loop() {
  while(Serial.available() > 0){
  }

  //lis les données envoyées par python
  bool x;
  x = lecture(buff);
  copie_array_struc(&MSG_Recu, buff,valeurs_Angles_moteurs);
  
  switch(MSG_Recu.etat){
    case 0:
      MSG_Envoi.etat = 0;
      initDone = 0;
      //etat arret fait rien
      break;
    case 1:
      MSG_Envoi.etat = 1;
      //etat init
      initDone = 1;
      break;
    case 2:
      //etat manuel verifie si le robot a ete initialise, mais n'est pas encore necessaire puisque nous n'avons pas d'initialisation a faire pour l'instant
//      if (initDone == 0){
//        MSG_Envoi.etat = 0;
//        break;
//        //init n'a pas été fait donc on ne peut entrer en mode manuel
//      }
//      else{
        MSG_Envoi.etat = 2;
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
  envoi_serie(MSG_Envoi, valeurs_Angles_moteurs);
  delay(100);
}

//fonction de lecture des données envoyées du PC à la carte (stocke toutes les données dans un buffer)
bool lecture(byte *buf){
  return(Serial.readBytes((char*)buf, sizeof(message))==sizeof(message)); 
}

//fonction de copie d'un byte array dans une struc et création du tableau de valeurs des angles des moteurs à partir du byte array
void copie_array_struc(message *MSG, byte *buf, int valeurs_angles[]){
  long tableau[NBR_DE_SERVO];
  memcpy(&MSG, buf, sizeof(MSG));
  memcpy(tableau, buf+=sizeof(long), sizeof(tableau));
  for (int i=0; i<NBR_DE_SERVO;i++){
    valeurs_angles[i] = (int)tableau[i];
  }
}

//fontion d'envoi des données de la carte openCR au PC
void envoi_serie(message MSG, int valeurs_angles[]){
  MSG.moteur0 = valeurs_angles[0];
  MSG.moteur1 = valeurs_angles[1];
  MSG.moteur2 = valeurs_angles[2];
  MSG.moteur3 = valeurs_angles[3];
  MSG.moteur4 = valeurs_angles[4];
  MSG.moteur5 = valeurs_angles[5];
  MSG.moteur6 = valeurs_angles[6];
  MSG.moteur7 = valeurs_angles[7];
  Serial.write((uint8_t*)&MSG, sizeof(MSG));
}
