#ifndef CINEMATIQUE_H
#define CINEMATIQUE_H

/* Déclaration des paramètres et des fonctions pour la cinématique des bras
   ArachnUS - Projet S4 - GRO
*/

#include "matrix.h"

// Constantes et paramètres
const float qb = 0.0;
const float qbx = 3.1416/2.0;
const float qv = 3.1416/10.0;

extern matrix_obj *q;
extern matrix_obj *Tw0;  
extern matrix_obj *Tw1;
extern matrix_obj *Tw2;
extern matrix_obj *Tw3;
extern matrix_obj *TwF;

void cinematiqueBegin();

/*
A = findpoint(Tw3);
P = pointfinal(A, 1);

// Calcul du Jacobien
J = Jacobien(q, Tw0, Tw1, Tw2, Tw3);

// Recherche de la cinématique inverse
Pgoal = [A;MatRotationToEuler(Tw3(1:3,1:3))];
Ik = invCinPatte(Pgoal,q+0.6,Tw0)

// Affichage graphique de la patte
coord = [   Tw1(1,4), Tw2(1,4), Tw3(1,4); 
            Tw1(2,4), Tw2(2,4), Tw3(2,4);
            Tw1(3,4), Tw2(3,4), Tw3(3,4)];
*/




#endif
