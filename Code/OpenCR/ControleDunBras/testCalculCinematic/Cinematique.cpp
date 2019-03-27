
#include "Cinematique.h"
#include "gaussjordan.h"

matrix_obj *q;
matrix_obj *Tw0;
matrix_obj *Tw1;
matrix_obj *Tw2;
matrix_obj *Tw3;
matrix_obj *TwF;  //Pour des tests

void transMat_w2f(matrix_obj * q, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3) {
  Tw1->array[0] = cos(q->array[0]);
  Tw1->array[1] = -sin(q->array[0]);
  Tw1->array[4] = sin(q->array[0]);
  Tw1->array[5] = cos(q->array[0]);
  Tw1->array[10] = 1;
  Tw1->array[15] = 1;

  Tw2->array[0] = cos(q->array[1]);
  Tw2->array[1] = -sin(q->array[1]);
  Tw2->array[3] = lv * cos(q->array[0]);
  Tw2->array[4] = sin(q->array[1]);
  Tw2->array[5] = cos(q->array[1]);
  Tw2->array[7] = lv * sin(q->array[0]);
  Tw2->array[10] = 1;
  Tw2->array[15] = 1;

  Tw3->array[0] = cos(q->array[1]);
  Tw3->array[1] = -sin(q->array[1]);
  Tw3->array[3] = lv * cos(q->array[0]) + lbx * cos(q->array[1]);
  Tw3->array[4] = sin(q->array[1]);
  Tw3->array[5] = cos(q->array[1]);
  Tw3->array[7] = lv * sin(q->array[0]) + lbx * sin(q->array[1]);
  Tw3->array[10] = 1;
  Tw3->array[15] = 1;
}

void bonAngle(matrix_obj * q, float qv, float qb) {
  float qbx = -1.0914 * qb + 27.979;       // Angle de bleu1 à partir de vert1

  if (qb <= 137.25 && qb > 122.5) {
    qbx = qbx - ( (4*pow(10, -7)) * pow(qv, 4) + (3*pow(10, -5)) * pow(qv, 3) + 0.0003 * pow(qv, 2) + 0.0665 * qv - 0.7918);
  } else if (qb <= 122.5 && qb > 107.5) {
    qbx = qbx - ((-7*pow(10, -9)) * pow(qv, 5) - (3*pow(10, -7)) * pow(qv, 4) + (2*pow(10, -5)) * pow(qv, 3) + 0.0001 * pow(qv, 2) + 0.07 * qv - 0.5725);
  } else if (qb <= 107.5 && qb > 90) {
    qbx = qbx - ( (1*pow(10, -5)) * pow(qv, 3) - 0.0005 * pow(qv, 2) + 0.0783 * qv - 0.7722);
  } else if (qb <= 90 && qb > 70) {
    qbx = qbx - ( (2*pow(10, -5)) * pow(qv, 3) - 0.0015 * pow(qv, 2) + 0.1111 * qv - 0.8019 );
  } else if (qb <= 152.5 && qb > 137.5) {
    qbx = qbx - ( (6*pow(10, -8)) * pow(qv, 5) + (5*pow(10, -6)) * pow(qv, 4) + 0.0001 * pow(qv, 3) + 0.0005 * pow(qv, 2) + 0.0793 * qv - 0.7672);
  }
  q->array[0] = qv*(2*3.1416/360);
  q->array[1] = qbx*(2*3.1416/360);
}

void pointFinal(matrix_obj * T3x1, int op) {
  T3x1->array[1] = T3x1->array[1] + op*12; // op = 1 ou -1
}

void findPoint(matrix_obj * A, matrix_obj * T) {
  A->array[0] = T->array[3];
  A->array[1] = T->array[7];
  A->array[2] = T->array[11];
}

void cinematiqueBegin(float qv, float qb) {
  q = matrix_construct_zero(3, 1);
  bonAngle(q, qv, qb);

  // Matrice identité...
  Tw0 = matrix_construct_zero(4, 4);
  Tw0->array[0] = cos(20);
  Tw0->array[1] = sin(20);
  Tw0->array[4] = -sin(20);
  Tw0->array[5] = cos(20);
  Tw0->array[10] = 1;
  Tw0->array[15] = 1;

  // Création d'une  matrice de test
  TwF = matrix_construct_zero(4, 12);
  for (int i = 0; i < 48; i++) {
    if (i <= 3 || (i >= 12 && i <= 15) || (i >= 24 && i <= 27) || (i >= 36 && i <= 39)) {
      TwF->array[i] = 1.1;
    } else if ((i >= 4 && i <= 7) || (i >= 16 && i <= 19) || (i >= 28 && i <= 31) || (i >= 40 && i <= 43)) {
      TwF->array[i] = 2.2;
    } else if ((i >= 8 && i <= 11) || (i >= 20 && i <= 23) || (i >= 32 && i <= 35) || (i >= 44 && i <= 47)) {
      TwF->array[i] = 3.3;
    }
  }

  // Construction des matrices de transformation
  Tw1 = matrix_construct_zero(4, 4);
  Tw2 = matrix_construct_zero(4, 4);
  Tw3 = matrix_construct_zero(4, 4);
  transMat_w2f(q, Tw0, Tw1, Tw2, Tw3);
  /*matrix_copie_part(Tw1, TwF, 1, 1, 4, 4);
    matrix_copie_part(Tw2, TwF, 1, 5, 4, 8);
    matrix_copie_part(Tw3, TwF, 1, 9, 4, 12);*/
}



