
/*************************************************** 
  Fonctions de communication entre OpenCR et Python(PC)
 ****************************************************/

//fonction de lecture des données envoyées du PC à la carte (stocke toutes les données dans un buffer)
bool lecture(byte *buf){
  return(Serial.readBytes((char*)buf, 10*sizeof(long))== 10*sizeof(long)); 
}

//fonction de copie d'un byte array dans une struc et création du tableau de valeurs des angles des moteurs à partir du byte array
void copie_array_struc(byte *buf, int valeurs_angles[], int state[], int hauteur[]){
  long tableau[NBR_DE_SERVO+2];
  memcpy(tableau, buf, sizeof(tableau));
  state[0] = (int)tableau[0];
  for (int i=0; i<NBR_DE_SERVO;i++){
    valeurs_angles[i] = (int)tableau[i+1];
  }
  hauteur[0] = (int)tableau[NBR_DE_SERVO+1];
}

//fontion d'envoi des données de la carte openCR au PC
void envoi_serie(envoi MSG, int valeurs_moteurs[NBR_DE_SERVO]){
  MSG.etat = state[0];
  MSG.hauteur = hauteurActuelle;
  MSG.moteur0 = valeurs_moteurs[0];
  MSG.moteur1 = valeurs_moteurs[1];
  MSG.moteur2 = valeurs_moteurs[2];
  MSG.moteur3 = valeurs_moteurs[3];
  MSG.moteur4 = valeurs_moteurs[4];
  MSG.moteur5 = valeurs_moteurs[5];
  MSG.moteur6 = valeurs_moteurs[6];
  MSG.moteur7 = valeurs_moteurs[7];
  MSG.angx = long(moteursPatte1[1]);//aRobot.angleX);
  MSG.angy = long(aRobot.angleY);
  Serial.write((uint8_t*)&MSG, sizeof(MSG));
}
