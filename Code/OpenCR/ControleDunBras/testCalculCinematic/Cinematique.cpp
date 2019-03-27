
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

<<<<<<< HEAD
<<<<<<< HEAD
void EulerXYZtoRot(matrix_obj * Q, matrix_obj * Euler) {
  float c1 = cos(Euler->array[0]);
  float s1 = sin(Euler->array[0]);
  float c2 = cos(Euler->array[1]);
  float s2 = sin(Euler->array[1]);
  float c3 = cos(Euler->array[2]);
  float s3 = sin(Euler->array[2]);

  Q->array[0] = c2 * c3;
  Q->array[1] = c1 * s3 + c3 * s1 * s2;
  Q->array[2] = s1 * s3 - c1 * c3 * s2;
  Q->array[3] = -c2 * s3;
  Q->array[4] = c1 * c3 - s1 * s2 * s3;
  Q->array[5] = c3 * s1 + c1 * s2 * s3;
  Q->array[6] = s2;
  Q->array[7] = -c2 * s1;
  Q->array[8] = c1 * c2;
}

void Jacobien(matrix_obj * J, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3) {
  //Jacobcol1
  J->array[0] = Tw0->array[6] * Tw3->array[11] - Tw0->array[10] * Tw3->array[7]; //obj->array[0] = src1->array[1]*src2->array[2] - src1->array[2]*src2->array[1];
  J->array[3] = Tw0->array[10] * Tw3->array[3] - Tw0->array[2] * Tw3->array[11]; //obj->array[1] = src1->array[2]*src2->array[0] - src1->array[0]*src2->array[2];
  J->array[6] = Tw0->array[2] * Tw3->array[7] - Tw0->array[6] * Tw3->array[3]; //obj->array[2] = src1->array[0]*src2->array[1] - src1->array[1]*src2->array[0];
  J->array[9] = Tw0->array[2];
  J->array[12] = Tw0->array[6];
  J->array[15] = Tw0->array[10];

  //Jacobcol2
  J->array[1] = Tw2->array[6] * (Tw3->array[11] - Tw2->array[11]) - Tw2->array[10] * (Tw3->array[7] - Tw2->array[7]);
  J->array[4] = Tw2->array[10] * (Tw3->array[3] - Tw2->array[3]) - Tw2->array[2] * (Tw3->array[11] - Tw2->array[11]);
  J->array[7] = Tw2->array[2] * (Tw3->array[7] - Tw2->array[7]) - Tw2->array[6] * (Tw3->array[3] - Tw2->array[3]);
  J->array[10] = Tw2->array[2];
  J->array[13] = Tw2->array[6];
  J->array[16] = Tw2->array[10];

  //Jacobcol3
  J->array[2] = Tw3->array[6] * (Tw3->array[11] - Tw3->array[11]) - Tw3->array[10] * (Tw3->array[7] - Tw3->array[7]);
  J->array[5] = Tw3->array[10] * (Tw3->array[3] - Tw3->array[3]) - Tw3->array[2] * (Tw3->array[11] - Tw3->array[11]);
  J->array[8] = Tw3->array[2] * (Tw3->array[7] - Tw3->array[7]) - Tw3->array[6] * (Tw3->array[3] - Tw3->array[3]);
  J->array[11] = Tw3->array[2];
  J->array[14] = Tw3->array[6];
  J->array[17] = Tw3->array[10];
}

void MatRotationToEuler(matrix_obj * Euler, matrix_obj * Mat) {
  float nx = Mat->array[0];
  float ny = Mat->array[3];
  float nz = Mat->array[6];
  float ox = Mat->array[1];
  float oy = Mat->array[4];
  float oz = Mat->array[7];
  float ax = Mat->array[2];
  float ay = Mat->array[5];
  float az = Mat->array[8];

  float A1 = atan2(-ay, az);
  float A1tt = atan2(az, -ay);
  float B1l = atan2(ax, (-1 * sin(A1) * ay + cos(A1) * az));
  float C1 = atan2(cos(A1) * ny + sin(A1) * nz, cos(A1) * oy + sin(A1) * oz);
  float A1f = 0;
  float B1f = 0;
  float C1f = 0;

  if (abs(ax - 1) < 0.000006) {
    A1f = atan2(ny, oy) / 2;
    B1f = 3.1416 / 2;
    C1f = atan2(ny, oy) / 2;
  } else if (abs(ax + 1) < 0.000006) {
    A1f = atan2(-ny, oy) / 2;
    B1f = -3.1416 / 2;
    C1f = -atan2(-ny, oy) / 2;
  } else {
    A1f = A1;
    C1f = C1;
    B1f = B1l;
  }
  
  Euler->array[0]  = A1f;
  Euler->array[1]  = B1f;
  Euler->array[2]  = C1f;

}

void fk_4_ik(matrix_obj * fk, matrix_obj * fkc, matrix_obj * fkr, matrix_obj * Rw3, matrix_obj * q, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3) {
  transMat_w2f(q, Tw0, Tw1, Tw2, Tw3);
  findPoint(fkc, Tw3);

  matrix_copie_part(Rw3, Tw3, 1, 1, 3, 3);
  MatRotationToEuler(fkr, Rw3);

  fk->array[0] = fkc->array[0];
  fk->array[1] = fkc->array[1];
  fk->array[2] = fkc->array[2];
  fk->array[3] = fkr->array[0];
  fk->array[4] = fkr->array[1];
  fk->array[5] = fkr->array[2];
}

void invCinPatte(matrix_obj * q, matrix_obj * Pgoal, matrix_obj * Err, matrix_obj * Pcurr_old, matrix_obj * Jtranspose, matrix_obj * Rcurr, matrix_obj * delta_R, matrix_obj * dTheta, matrix_obj * Omega, matrix_obj * dX, matrix_obj * Rgoal, matrix_obj * Ppartie, matrix_obj * A, matrix_obj * Rpartie, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3, matrix_obj * J, matrix_obj * Pcurr, matrix_obj * fkr, matrix_obj * fkc, matrix_obj * Rw3) {
  fk_4_ik(Pcurr, fkc, fkr, Rw3, q, Tw0, Tw1, Tw2, Tw3);

  matrix_copie_part(Ppartie, Pgoal, 4, 1, 6, 1);
  EulerXYZtoRot(Rgoal, Ppartie);        //Goal rotation matrix
  matrix_sub(Err, Pgoal, Pcurr);        //Error between Pgoal and Pcurr
    
    while (max_matrix_abs(Err) > 0.001){  //Beginning of the iterative method
      
      matrix_copy_matrix(Pcurr_old, Pcurr);
      matrix_copie_part(Ppartie, Pcurr, 4, 1, 6, 1);   
      EulerXYZtoRot(Rcurr, Ppartie);      //Current rotational matrix from Euler angles
      matrix_sub(delta_R, Rgoal, Rcurr);  //Difference between matrices
      matrix_inv(Rpartie, Rcurr);
      matrix_mul(Omega, delta_R, Rpartie);  //matrix differential rule: delta_R=Omega*Rcurr. So Omega = delta_R*inv(Rcurr)
                    
      dX->array[3] = (Omega->array[7]-Omega->array[5])/2; //Finding wx from W
      dX->array[4] = (Omega->array[2]-Omega->array[6])/2; //Finding wy from W
      dX->array[5] = (Omega->array[3]-Omega->array[1])/2; //Finding wz from W

      //positional displacement as seen in the class notes
      dX->array[0] =  Pgoal->array[0] - Pcurr->array[0];
      dX->array[1] =  Pgoal->array[1] - Pcurr->array[1];
      dX->array[2] =  Pgoal->array[2] - Pcurr->array[2];
     
      transMat_w2f(q, Tw0, Tw1, Tw2, Tw3);
      Jacobien(J, Tw0, Tw1, Tw2, Tw3);   //Determination of the Jacobian at angle q

      matrix_transpose(Jtranspose, J);
      matrix_mul(Rpartie, Jtranspose, J);
      matrix_inv(A, Rpartie);
      matrix_mul(Rpartie, A, Jtranspose);
      matrix_mul(dTheta, Rpartie, dX);  //Inverse Kinematics formula

      matrix_add(q, q, dTheta);       //Finding new angles
                   
      fk_4_ik(Pcurr, fkc, fkr, Rw3, q, Tw0, Tw1, Tw2, Tw3); //Determining new Pcurr from new q
      matrix_sub(Err, Pcurr_old, Pcurr);  //Determining Err from new Pcurr         
    }     
}

void positionCartesiennePatte(matrix_obj * q, matrix_obj * Tw0, matrix_obj * Tw1, matrix_obj * Tw2, matrix_obj * Tw3, float qv, float qb) {
  bonAngle(q, qv, qb);
  
  transMat_w2f(q, Tw0, Tw1, Tw2, Tw3);

  findPoint(Ppartie, Tw3);

  pointFinal(Pgoal, -1);
   
}

=======
>>>>>>> parent of 6e9be56... Cinématique sur arduino 80%
=======
>>>>>>> parent of 6e9be56... Cinématique sur arduino 80%
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
<<<<<<< HEAD
<<<<<<< HEAD

  /*J = matrix_construct_zero(6, 3);
  Jacobien(J, Tw0, Tw1, Tw2, Tw3);

  fk = matrix_construct_zero(6, 1);
  fkc = matrix_construct_zero(3, 1);
  fkr = matrix_construct_zero(3, 1);
  Rw3 = matrix_construct_zero(3, 3);
  fk_4_ik(Pcurr, fkc, fkr, Rw3, q, Tw0, Tw1, Tw2, Tw3);*/

  Rgoal = matrix_construct_zero(3, 3);
  Pgoal = matrix_construct_zero(6, 1);
  Ppartie = matrix_construct_zero(3, 1);
  Err = matrix_construct_zero(6, 1);
  Pcurr_old = matrix_construct_zero(6, 1);
  Rcurr = matrix_construct_zero(3, 3);
  delta_R = matrix_construct_zero(3, 3);
  Omega = matrix_construct_zero(3, 3);
  dX = matrix_construct_zero(6, 1);
  Rpartie = matrix_construct_zero(3, 3);
  A = matrix_construct_zero(3, 3);
  Jtranspose = matrix_construct_zero(3, 6);
  dTheta = matrix_construct_zero(3, 1);

  invCinPatte(q, Pgoal, Err, Pcurr_old, Jtranspose, Rcurr, delta_R, dTheta, Omega, dX, Rgoal, Ppartie, A, Rpartie, Tw0, Tw1, Tw2, Tw3, J, Pcurr, fkr, fkc, Rw3);
  positionCartesiennePatte(q, Tw0, Tw1, Tw2, Tw3, qv, qb);


=======
>>>>>>> parent of 6e9be56... Cinématique sur arduino 80%
=======
>>>>>>> parent of 6e9be56... Cinématique sur arduino 80%
}



