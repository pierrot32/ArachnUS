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

ObjCinematique cc;

void setup() {

  Serial.begin(9600);
  delay(1000);
  Serial.println();
  // ========= Test automatisés pour la cinématique =========
  // Pour faire les différents tests, les fonctions de la classe ObjCinematique doivent toutes être publiques
  // ======================= bonAngle =======================
  Serial.println(" =============================== DÉBUT DES TESTS =============================== ");
  Serial.println();
  Serial.println(" -------------- Tests bonAngle -------------- ");
  // Test 1:
  // L'entrée est -25 et 100 degrées pour qv et qb et retourne -25 et -78 pour qv et qbx 
  cc.bonAngle(cc.q, -25.0, 100.0);
  float v_qv = -0.4363;
  float v_qbx =  -1.360;
  float t_qv = cc.q->array[0];
  float t_qbx = cc.q->array[1];
  int reussi = 1;
  if (abs(v_qv-t_qv) < 0.1 && abs(v_qbx - t_qbx) < 0.1){
    Serial.println(" ----------- bonAngle.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- bonAngle.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est 30 et 120 degrées pour qv et qb et retourne 30 et -104 degrées pour qv et qbx 
  cc.bonAngle(cc.q, 30, 120.0);
  v_qv = 0.5236;
  v_qbx =  -1.8279;
  t_qv = cc.q->array[0];
  t_qbx = cc.q->array[1];

  if (abs(v_qv-t_qv) < 0.1 && abs(v_qbx - t_qbx) < 0.1){
    Serial.println(" ----------- bonAngle.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- bonAngle.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= bonAngleInv =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests bonAngleInv -------------- ");
  // Test 1:
  // L'entrée est -25 et -78 degrées pour qv et qbx et retourne -25 et 100 pour qv et qb 
  cc.q->array[0] = -25*2*3.1416/360;
  cc.q->array[1] = -78*2*3.1416/360;
  cc.bonAngleInv(cc.qret, cc.q);
  v_qv = -25;
  float v_qb =  100;
  t_qv = cc.qret->array[0];
  float t_qb = cc.qret->array[1];

  if (abs(v_qv-t_qv) < 5 && abs(v_qb - t_qb) < 5){
    Serial.println(" ----------- bonAngleInv.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- bonAngleInv.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est 30 et -104 degrées pour qv et qbx et retourne 30 et 120 pour qv et qb 
  cc.q->array[0] = 30*2*3.1416/360;
  cc.q->array[1] = -104*2*3.1416/360;
  cc.bonAngleInv(cc.qret, cc.q);
  v_qv = 30;
  v_qb =  120;
  t_qv = cc.qret->array[0];
  t_qb = cc.qret->array[1];

  if (abs(v_qv-t_qv) < 5 && abs(v_qb - t_qb) < 5){
    Serial.println(" ----------- bonAngleInv.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- bonAngleInv.Test2 == Échoué ----------- ");
    reussi = 0;
  }
  
  // ======================= pointFinal =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests pointFinal -------------- ");
  // Test 1:
  // L'entrée est [0,0,0] pour la position et retourne [0,12,0] 
  cc.pointFinal(cc.Ppartie, 1);

  if (abs(0-cc.Ppartie->array[0]) < 0.1 && abs(12-cc.Ppartie->array[1]) < 0.1 && abs(0-cc.Ppartie->array[3]) < 0.1){
    Serial.println(" ----------- pointFinal.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- pointFinal.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est [155,23,0] degrées pour la position et retourne [155,11,0] 
  cc.Ppartie->array[0] = 155.0;
  cc.Ppartie->array[1] = 23.0;

  cc.pointFinal(cc.Ppartie, -1);

  if (abs(155-cc.Ppartie->array[0]) < 0.1 && abs(11-cc.Ppartie->array[1]) < 0.1 && abs(0-cc.Ppartie->array[3]) < 0.1){
    Serial.println(" ----------- pointFinal.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- pointFinal.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= transMat_w2f =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests transMat_w2f -------------- ");
  // Test 1:
  // L'entrée est des angles de -25 et -78 degrées pour qv et qbx retourne une matrice de rotation 
  cc.q->array[0] = -25*2*3.1416/360;
  cc.q->array[1] = -78*2*3.1416/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);

  if (abs(0.2079-cc.Tw3->array[0]) < 0.1 && abs(0.9781-cc.Tw3->array[1]) < 0.1 && abs(89.8459-cc.Tw3->array[3]) < 0.1 && abs(0.2079-cc.Tw3->array[5]) < 0.1 && abs(-0.9781-cc.Tw3->array[4]) < 0.1 && abs(-144.2028-cc.Tw3->array[7]) < 0.1){
    Serial.println(" ----------- transMat_w2f.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- transMat_w2f.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est des angles de 30 et -104 degrées pour qv et qbx retourne une matrice de rotation 
  cc.q->array[0] = 30*2*3.1416/360;
  cc.q->array[1] = -104*2*3.1416/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);

  if (abs(-0.2419-cc.Tw3->array[0]) < 0.1 && abs(0.9703-cc.Tw3->array[1]) < 0.1 && abs(34.699-cc.Tw3->array[3]) < 0.1 && abs(-0.9703-cc.Tw3->array[4]) < 0.1 && abs(-0.2419-cc.Tw3->array[5]) < 0.1 && abs(-76.4013-cc.Tw3->array[7]) < 0.1){
    Serial.println(" ----------- transMat_w2f.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- transMat_w2f.Test2 == Échoué ----------- ");
    reussi = 0;
  }

 // ======================= findPoint =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests findPoint -------------- ");
  // Test 1:
  // L'entrée est des angles de -25 et -78 degrées pour qv et qbx retourne un vecteur position [89.84,-144.2,0]
  cc.q->array[0] = -25*2*3.1416/360;
  cc.q->array[1] = -78*2*3.1416/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  cc.findPoint(cc.A, cc.Tw3);
  if (abs(89.8459-cc.A->array[0]) < 0.1 && abs(-144.2028-cc.A->array[1]) < 0.1 && abs(0-cc.A->array[3]) < 0.1){
    Serial.println(" ----------- findPoint.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- findPoint.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est des angles de 30 et -104 degrées pour qv et qbx retourne un vecteur position [34.69,-76.4,0]
  cc.q->array[0] = 30*2*3.1416/360;
  cc.q->array[1] = -104*2*3.1416/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  cc.findPoint(cc.A, cc.Tw3);
  if (abs(34.6997-cc.A->array[0]) < 0.1 && abs(-76.4013-cc.A->array[1]) < 0.1 && abs(0-cc.A->array[3]) < 0.1){
    Serial.println(" ----------- findPoint.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- findPoint.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= positionCartesiennePatte =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests positionCartesiennePatte -------------- ");
  // Test 1:
  // L'entrée est des angles de -25 et -100 degrées pour qv et qb retourne un vecteur position [89.84,-144.2,0] dans Pgoal
  cc.positionCartesiennePatte(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3, cc.Pgoal, -25, 100);
  if (abs(89.92-cc.Pgoal->array[0]) < 0.1 && abs(-156.18-cc.Pgoal->array[1]) < 0.1 && abs(0-cc.Pgoal->array[3]) < 0.1){
    Serial.println(" ----------- positionCartesiennePatte.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- positionCartesiennePatte.Test1 == Échoué ----------- ");
    reussi = 0;
  }
 
  // Test 2:
  // L'entrée est des angles de 30 et 120 degrées pour qv et qb retourne un vecteur position [33.26,-88.03,0] dans Pgoal
  cc.positionCartesiennePatte(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3, cc.Pgoal, 30, 120);
  if (abs(33.26-cc.Pgoal->array[0]) < 0.1 && abs(-88.03-cc.Pgoal->array[1]) < 0.1 && abs(0-cc.Pgoal->array[3]) < 0.1){
    Serial.println(" ----------- positionCartesiennePatte.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- positionCartesiennePatte.Test2 == Échoué ----------- ");
    reussi = 0;
  }
  
  // ======================= runANGtoDIST =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests runANGtoDIST -------------- ");
  // Test 1:
  // L'entrée est des angles de -25 et -100 degrées pour qv et qb retourne un vecteur position [89.84,-144.2] dans distSort
  float distSort[2] = {0,0};
  cc.runANGtoDIST(distSort, -25, 100);
  if (abs(89.92-distSort[0]) < 0.1 && abs(-156.18-distSort[1]) < 0.1){
    Serial.println(" ----------- runANGtoDIST.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- runANGtoDIST.Test1 == Échoué ----------- ");
    reussi = 0;
  }
  
  // Test 2:
  // L'entrée est des angles de 30 et 120 degrées pour qv et qb retourne un vecteur position [33.26,-88.03] dans distSort
  cc.runANGtoDIST(distSort, 30, 120);
  if (abs(33.26-distSort[0]) < 0.1 && abs(-88.03-distSort[1]) < 0.1){
    Serial.println(" ----------- runANGtoDIST.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- runANGtoDIST.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= MatRotationToEuler et EulerXYztoRot =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests MatRotationToEuler et EulerXYztoRot -------------- ");
  // Test 1:
  // L'entrée est des angles de -25 et -78 degrées pour qv et qbx retourne des angles d'Euler [0;0;-1.36] dans Euler
  cc.q->array[0] = -25*3.1416*2/360;
  cc.q->array[1] = -78*3.1416*2/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  matrix_copie_part(cc.Rw3, cc.Tw3, 1, 1, 3, 3);
  cc.MatRotationToEuler(cc.Euler, cc.Rw3);
  if (abs(0-cc.Euler->array[0]) < 0.1 && abs(0-cc.Euler->array[1]) < 0.1 && abs(-1.36-cc.Euler->array[2]) < 0.1){
    Serial.println(" ----------- MatRotationToEuler.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- MatRotationToEuler.Test1 == Échoué ----------- ");
    reussi = 0;
  }
  
  // Test 1:
  // Retour de la matrice de rotation Rw3 initiale à partir des angles d'Euler
  cc.EulerXYZtoRot(cc.Rw3, cc.Euler);
   if (abs(0.2079-cc.Rw3->array[0]) < 0.1 && abs(0.9781-cc.Rw3->array[1]) < 0.1 && abs(-0.9781-cc.Rw3->array[3]) < 0.1 && abs(0.2079-cc.Rw3->array[4]) < 0.1){
    Serial.println(" ----------- EulerXYZtoRot.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- EulerXYZtoRot.Test1 == Échoué ----------- ");
    reussi = 0;
  }
  
   // Test 2:
  // L'entrée est des angles de 30 et -104 degrées pour qv et qbx retourne des angles d'Euler [0;0;-1.81] dans Euler
  cc.q->array[0] = 30*3.1416*2/360;
  cc.q->array[1] = -104*3.1416*2/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  matrix_copie_part(cc.Rw3, cc.Tw3, 1, 1, 3, 3);
  cc.MatRotationToEuler(cc.Euler, cc.Rw3);
  if (abs(0-cc.Euler->array[0]) < 0.1 && abs(0-cc.Euler->array[1]) < 0.1 && abs(-1.8151-cc.Euler->array[2]) < 0.1){
    Serial.println(" ----------- MatRotationToEuler.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- MatRotationToEuler.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // Retour de la matrice de rotation Rw3 initiale à partir des angles d'Euler
  cc.EulerXYZtoRot(cc.Rw3, cc.Euler);
   if (abs(-0.2419-cc.Rw3->array[0]) < 0.1 && abs(0.9703-cc.Rw3->array[1]) < 0.1 && abs(-0.9703-cc.Rw3->array[3]) < 0.1 && abs(-0.2419-cc.Rw3->array[4]) < 0.1){
    Serial.println(" ----------- EulerXYZtoRot.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- EulerXYZtoRot.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= fk_4_ik =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests fk_4_ik -------------- ");
  // Test 1:
  // L'entrée est des angles de -25 et -78 degrées pour qv et qbx retourne un vecteur position [89.84;-144.2;0] dans fk
  cc.q->array[0] = -25*3.1416*2/360;
  cc.q->array[1] = -78*3.1416*2/360;
  cc.fk_4_ik(cc.fk, cc.fkc, cc.fkr, cc.Rw3, cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  if (abs(89.84-cc.fk->array[0]) < 0.1 && abs(-144.2-cc.fk->array[1]) < 0.1 && abs(0-cc.fk->array[2]) < 0.1){
    Serial.println(" ----------- fk_4_ik.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- fk_4_ik.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est des angles de 30 et -104 degrées pour qv et qbx retourne un vecteur position [34.6997;-76.4;0] dans fk
  cc.q->array[0] = 30*3.1416*2/360;
  cc.q->array[1] = -104*3.1416*2/360;
  cc.fk_4_ik(cc.fk, cc.fkc, cc.fkr, cc.Rw3, cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  if (abs(34.6997-cc.fk->array[0]) < 0.1 && abs(-76.40-cc.fk->array[1]) < 0.1 && abs(0-cc.fk->array[2]) < 0.1){
    Serial.println(" ----------- fk_4_ik.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- fk_4_ik.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= Jacobien =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests Jacobien -------------- ");
  // Test 1:
  // L'entrée est des angles de -25 et -78 degrées pour qv et une position de qbx retourne le bon Jacobien
  cc.q->array[0] = -25*3.1416*2/360;
  cc.q->array[1] = -78*3.1416*2/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  cc.Jacobien(cc.J, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  if (abs(144.2028-cc.J->array[0]) < 0.1 && abs(113.56-cc.J->array[1]) < 0.1 && abs(89.84-cc.J->array[3]) < 0.1 && abs(24.1385-cc.J->array[4]) < 0.1){
    Serial.println(" ----------- Jacobien.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- Jacobien.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est des angles de 30 et -104 degrées pour qv et qbx retourne le bon Jacobien
  cc.q->array[0] = 30*3.1416*2/360;
  cc.q->array[1] = -104*3.1416*2/360;
  cc.transMat_w2f(cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  cc.Jacobien(cc.J, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  if (abs(76.4013-cc.J->array[0]) < 0.1 && abs(112.6513-cc.J->array[1]) < 0.1 && abs(34.6997-cc.J->array[3]) < 0.1 && abs(-28.0871-cc.J->array[4]) < 0.1){
    Serial.println(" ----------- Jacobien.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- Jacobien.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= invCinPatte =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests invCinPatte -------------- ");
  // Test 1:
  // L'entrée est des angles de -35 et -68 degrées pour qv et qbx et une distance de [89.84;-144.2;0] pour retourner des angles de -25 et -78 degrées pour qv et qb
  cc.q->array[0] = -35*3.1416*2/360;
  cc.q->array[1] = -68*3.1416*2/360;
  cc.fk_4_ik(cc.Pcurr, cc.fkc, cc.fkr, cc.Rw3, cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  cc.Pgoal->array[0] = 89.94;
  cc.Pgoal->array[1] = -144.2;
  cc.Pgoal->array[2] = 0;
  cc.Pgoal->array[3] = cc.Pcurr->array[3];
  cc.Pgoal->array[4] = cc.Pcurr->array[4];
  cc.Pgoal->array[5] = cc.Pcurr->array[5];
  
  cc.invCinPatte(cc.q, cc.Pgoal, cc.Err, cc.Pcurr_old, cc.Jtranspose, cc.Rcurr, cc.delta_R, cc.dTheta, cc.Omega, cc.dX, cc.Rgoal, cc.Ppartie, cc.A, cc.Rpartie, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3, cc.J, cc.Pcurr, cc.fkr, cc.fkc, cc.Rw3);
  if (abs(-0.4363-cc.q->array[0]) < 0.1 && abs(-1.361 - cc.q->array[1]) < 0.1){
    Serial.println(" ----------- invCinPatte.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- invCinPatte.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est des angles de 10 et -120 degrées pour qv et qbx et une distance de [34.6997;-76.40;0] pour retourner des angles de 30 et 120 degrées pour qv et qb
  cc.q->array[0] = 10*3.1416*2/360;
  cc.q->array[1] = -120*3.1416*2/360;
  cc.fk_4_ik(cc.Pcurr, cc.fkc, cc.fkr, cc.Rw3, cc.q, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3);
  cc.Pgoal->array[0] = 34.6997;
  cc.Pgoal->array[1] = -76.40;
  cc.Pgoal->array[2] = 0;
  cc.Pgoal->array[3] = cc.Pcurr->array[3];
  cc.Pgoal->array[4] = cc.Pcurr->array[4];
  cc.Pgoal->array[5] = cc.Pcurr->array[5];
  
  cc.invCinPatte(cc.q, cc.Pgoal, cc.Err, cc.Pcurr_old, cc.Jtranspose, cc.Rcurr, cc.delta_R, cc.dTheta, cc.Omega, cc.dX, cc.Rgoal, cc.Ppartie, cc.A, cc.Rpartie, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3, cc.J, cc.Pcurr, cc.fkr, cc.fkc, cc.Rw3);
  if (abs(0.5236-cc.q->array[0]) < 0.1 && abs(-1.815 - cc.q->array[1]) < 0.1){
    Serial.println(" ----------- invCinPatte.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- invCinPatte.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= positionAngulairePatte =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests positionAngulairePatte -------------- ");
  // Test 1:
  // L'entrée est des angles de -35 et 120 degrées pour qv et qbx et une distance de [89.84;-156.2;0] pour retourner des angles de -25 et -78 degrées pour qv et qb
  cc.positionAngulairePatte(cc.q, cc.qret, cc.Pgoal, cc.Err, cc.Pcurr_old, cc.Jtranspose, cc.Rcurr, cc.delta_R, cc.dTheta, cc.Omega, cc.dX, cc.Rgoal, cc.Ppartie, cc.A, cc.Rpartie, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3, cc.J, cc.Pcurr, cc.fkr, cc.fkc, cc.Rw3, -35, 120, 89.8, -156.2);

  if (abs(-25-cc.qret->array[0]) < 5 && abs(100 - cc.qret->array[1]) < 5){
    Serial.println(" ----------- positionAngulairePatte.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- positionAngulairePatte.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est des angles de 10 et 130 degrées pour qv et qbx et une distance de [34.6997;-88.40;0] pour retourner des angles de 30 et 120 degrées pour qv et qb
  cc.positionAngulairePatte(cc.q, cc.qret, cc.Pgoal, cc.Err, cc.Pcurr_old, cc.Jtranspose, cc.Rcurr, cc.delta_R, cc.dTheta, cc.Omega, cc.dX, cc.Rgoal, cc.Ppartie, cc.A, cc.Rpartie, cc.Tw0, cc.Tw1, cc.Tw2, cc.Tw3, cc.J, cc.Pcurr, cc.fkr, cc.fkc, cc.Rw3, 10, 130, 34.7, -88.4);

  if (abs(30-cc.qret->array[0]) < 5 && abs(120 - cc.qret->array[1]) < 5){
    Serial.println(" ----------- positionAngulairePatte.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- positionAngulairePatte.Test2 == Échoué ----------- ");
    reussi = 0;
  }

  // ======================= runDISTtoANG =======================
  Serial.println();
  Serial.println();
  Serial.println(" -------------- Tests runDISTtoANG -------------- ");
  // Test 1:
  // L'entrée est des angles de -35 et 120 degrées pour qv et qbx et une distance de [89.84;-156.2;0] pour retourner des angles de -25 et -78 degrées pour qv et qb
  float angSort[2] = {0,0};
  cc.runDISTtoANG(angSort, -35, 120, 89.8, -156.2);

  if (abs(-25-cc.qret->array[0]) < 5 && abs(100 - cc.qret->array[1]) < 5){
    Serial.println(" ----------- positionAngulairePatte.Test1 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- positionAngulairePatte.Test1 == Échoué ----------- ");
    reussi = 0;
  }

  // Test 2:
  // L'entrée est des angles de 10 et 130 degrées pour qv et qbx et une distance de [34.6997;-88.40;0] pour retourner des angles de 30 et 120 degrées pour qv et qb
  cc.runDISTtoANG(angSort, 10, 130, 34.7, -88.4);
  if (abs(30-cc.qret->array[0]) < 5 && abs(120 - cc.qret->array[1]) < 5){
    Serial.println(" ----------- positionAngulairePatte.Test2 == Réussi ----------- ");
  }
  else{
    Serial.println(" ----------- positionAngulairePatte.Test2 == Échoué ----------- ");
    reussi = 0;
  }



  Serial.println();
  Serial.print(" ================================= Réussi = ");
  Serial.print(reussi);
  Serial.println(" =================================" );
  Serial.println(" =============================== FIN DES TESTS =============================== ");

  
  //avec ObjCinematique
  float distanceSortie[2];
//  calculorCin.runANGtoDIST(distanceSortie, qv, qb);
  dx = distanceSortie[0];
  dy = distanceSortie[1];

 
}

void loop() {

}
