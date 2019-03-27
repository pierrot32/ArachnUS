#ifndef CINEMATIQUE_H
#define CINEMATIQUE_H

/* Déclaration des paramètres et des fonctions pour la cinématique des bras
   ArachnUS - Projet S4 - GRO
*/

#include "matrix.h"

// Constantes et paramètres
const float lv = 72.5; //mm
const float lbx = 116.1; //mm

extern matrix_obj *q;
extern matrix_obj *Tw0;  
extern matrix_obj *Tw1;
extern matrix_obj *Tw2;
extern matrix_obj *Tw3;
extern matrix_obj *TwF;

extern matrix_obj *J;
extern matrix_obj *fkc;
extern matrix_obj *fkr;
extern matrix_obj *Rw3;
extern matrix_obj *Pcurr;

extern matrix_obj *Rgoal;
extern matrix_obj *Pgoal;
extern matrix_obj *Ppartie;
extern matrix_obj *Err;
extern matrix_obj *Pcurr_old;
extern matrix_obj *Rcurr;
extern matrix_obj *delta_R;
extern matrix_obj *Omega;
extern matrix_obj *dX;
extern matrix_obj *Rpartie;
extern matrix_obj *A;
extern matrix_obj *Jtranspose;
extern matrix_obj *dTheta;

void cinematiqueBegin(float qv, float qb);

void transMat_w2f(matrix_obj * q, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3);

void bonAngle(matrix_obj * q, float qv, float qb);

void pointFinal(matrix_obj * T3x1, int op);

void findPoint(matrix_obj * A, matrix_obj * T);

void EulerXYZtoRot(matrix_obj * Q, matrix_obj * Euler);

void Jacobien(matrix_obj * J, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3);

void MatRotationToEuler(matrix_obj * Euler, matrix_obj * Mat);

void fk_4_ik(matrix_obj * fk, matrix_obj * fkc, matrix_obj * fkr, matrix_obj * Rw3, matrix_obj * q, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3);

void invCinPatte(matrix_obj * q, matrix_obj * Pgoal, matrix_obj * Err, matrix_obj * Pcurr_old, matrix_obj * Jtranspose, matrix_obj * Rcurr, matrix_obj * delta_R, matrix_obj * dTheta, matrix_obj * Omega, matrix_obj * dX, matrix_obj * Rgoal, matrix_obj * Ppartie, matrix_obj * A, matrix_obj * Rpartie, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3, matrix_obj * J, matrix_obj * Pcurr, matrix_obj * fkr, matrix_obj * fkc, matrix_obj * Rw3);



#endif
