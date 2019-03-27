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

void cinematiqueBegin(float qv, float qb);

void transMat_w2f(matrix_obj * q, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3);

void bonAngle(matrix_obj * q, float qv, float qb);

void pointFinal(matrix_obj * T3x1, int op);

void findPoint(matrix_obj * A, matrix_obj * T);



#endif
