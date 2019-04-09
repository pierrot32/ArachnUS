/***************************************************
  Tests pour valider les fonctionnalitées du notre code pour la cinématique des pattes
 ****************************************************/

#include "ObjCinematique.h"

float index = 0.0;

//Variable d'entree
float qv = -25.0;
float qb = 100.0;
float dx = 0;
float dy = 0;

ObjCinematique calculorCin;

void setup() {

  Serial.begin(9600);

  //avec ObjCinematique
  float distanceSortie[2];
  calculorCin.runANGtoDIST(distanceSortie, qv, qb);
  dx = distanceSortie[0];
  dy = distanceSortie[1];

  Serial.print("x: ");
  Serial.println(dx);
  Serial.print("y:  ");
  Serial.println(dy);
  
}

void loop() {
  index++;
  Serial.println("-----------------------------------------------------------------");
  Serial.println("_________________________________________________________________");
  Serial.println("-----------------------------------------------------------------");
  Serial.print("Loop de test no ");
  Serial.println(index);
  Serial.println("-----------------------------------------------------------------");
  Serial.println("_________________________________________________________________");

  float tableauDesAnglesRetournes[2];
  calculorCin.runDISTtoANG(tableauDesAnglesRetournes, qv, qb, dx, dy);
  
  calculorCin.printTest();

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test OBJ: valeurOUT");
  Serial.println(tableauDesAnglesRetournes[0]);
  Serial.println(tableauDesAnglesRetournes[1]);
  Serial.println();


  delay(10000);
}
