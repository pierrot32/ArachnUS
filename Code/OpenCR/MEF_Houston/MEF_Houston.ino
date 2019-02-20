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
int long_msg_envoi = sizeof(MSG_Envoi);
int long_msg_recu = sizeof(MSG_Recu);
byte buff[sizeof(MSG_Recu)];

void setup() {
Serial.begin(115200);
}

void loop() {
  while(Serial.available() > 0){
  }
  switch(MSG_Recu.etat){
    case 0:
      MSG_Envoi.etat = 0;
      initDone = 0;
      //etat arret fait rien
      break;
    case 1:
      MSG_Envoi.etat = 1;
      //etat à venir
      initDone = 1;
      break;
    case 2:
      //etat à venir
      if (initDone == 0){
        MSG_Envoi.etat = 0;
        break;
        //init n'a pas été fait donc on ne peut entrer en mode manuel
      }
      else{
        MSG_Envoi.etat = 2;
        //opération demandée
        break;        
      }

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
//  bool x;
//  x = lecture(buff);
//  copie_array_struc(&MSG_Recu, buff);
  
  
  delay(2000);
}
//fonction de lecture
bool lecture(byte *buf){
  return(Serial.readBytes((char*)buf, sizeof(message))==sizeof(message)); 
}

//fonction de copie array dans struc
void copie_array_struc(message *MSG, byte *buf){
  memcpy(&MSG, buf, sizeof(MSG));
}

//fontion d'envoi
void envoi_serie(message MSG){
  Serial.write((uint8_t*)&MSG_Recu, long_msg_recu);
}
