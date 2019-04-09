/*
 * Le programme ci-dessous à été réalisé par l'équipe d'ARACHNUS
 * dans la cadre d'un cours de projet en génie robotique
 * de l'université de Sherbrooke (S4-GRO).
 */
 
/***************************************************
  Tests pour valider les fonctionnalitées du notre code pour la cinématique des pattes
 ****************************************************/

#include "ObjCinematique.h"

int indexF = 0;
unsigned long delais = 0;

//Variable d'entree
float qv = 0.0;
float qb = 80.0;
float dx = 0;
float dy = 0;

ObjCinematique * calculorCin;

void setup() {

  Serial.begin(9600);
  calculorCin = new ObjCinematique();

  //avec ObjCinematique
  float distanceSortie[2];
  calculorCin->runANGtoDIST(distanceSortie, qv, qb);
  dx = distanceSortie[0];
  dy = distanceSortie[1];

  Serial.print("x: ");
  Serial.println(dx);
  Serial.print("y:  ");
  Serial.println(dy);
  
}

void loop() {  
  indexF++;
  Serial.println("-----------------------------------------------------------------");
  Serial.println("_________________________________________________________________");
  Serial.println("-----------------------------------------------------------------");
  Serial.print("Loop de test no ");
  Serial.println(indexF);
  Serial.println("-----------------------------------------------------------------");
  Serial.println("_________________________________________________________________");

  float tableauDesAnglesRetournes[2];
  
  delais = millis();
  //calculorCin->runDISTtoANG(tableauDesAnglesRetournes, qv+40, qb+40, dx, dy);
  qv = int(tableauDesAnglesRetournes[0]);
  qb = int(tableauDesAnglesRetournes[1]);
  delais = millis() - delais;
  
  calculorCin->printTest();

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test OBJ: valeurOUT");
  Serial.println(tableauDesAnglesRetournes[0]);
  Serial.println(tableauDesAnglesRetournes[1]);
  Serial.println();

  Serial.println("-----------------------------------------------------------------");
  Serial.print("Temps de boucle: ");
  Serial.println(delais);
  Serial.println();
  
  delay(10000);
}
