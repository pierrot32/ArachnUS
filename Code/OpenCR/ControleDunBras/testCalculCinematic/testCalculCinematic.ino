/*************************************************** 
  Tests pour valider les fonctionnalitées du notre code pour la cinématique des pattes
 ****************************************************/

#include "Cinematique.h"

matrix_obj *matriceTest1;
float index = 0.0;

matrix_obj *matriceTestMult;
matrix_obj *matriceTestInv;

matrix_obj *vecTest1;
matrix_obj *vecTest2;
matrix_obj *vecTest12;

//Variable d'entree
float qb = 100.0;
float qv = -25.0;


void setup() {
  matriceTest1 = matrix_construct_zero(3, 3);
  matriceTestMult = matrix_construct_zero(4, 4);
  matriceTestInv = matrix_construct_zero(3, 3);

  vecTest1 = matrix_construct_zero(1, 3);
    vecTest1->array[0] = 1;
    vecTest1->array[1] = 2;
    vecTest1->array[2] = 1;
  vecTest2 = matrix_construct_zero(1, 3);
    vecTest2->array[0] = 1;
    vecTest2->array[1] = 1;
    vecTest2->array[2] = 1;
  vecTest12 = matrix_construct_zero(1, 3);
  Serial.begin(9600);

  cinematiqueBegin(qv, qb);
}

void loop() {
  Serial.println("-----------------------------------------------------------------");
  Serial.println("_________________________________________________________________");
  Serial.println("-----------------------------------------------------------------");
  Serial.print("Loop de test no ");
  Serial.println(index*10);
  Serial.println("-----------------------------------------------------------------");
  Serial.println("_________________________________________________________________");
  
  
  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test 1: Creation et affichage");
  matriceTest1->array[0] = 0;
  matriceTest1->array[1] = 2;
  matriceTest1->array[2] = 2;
  matriceTest1->array[3] = 1;
  matriceTest1->array[4] = 1;
  matriceTest1->array[5] = 1;
  matriceTest1->array[6] = 0;
  matriceTest1->array[7] = 1;
  matriceTest1->array[8] = 2;
  matrix_printf(matriceTest1);
  Serial.println();  

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test 2: Copie d'une partie de matrice dans une plus petite");
  matrix_printf(TwF);
  Serial.println();
  matrix_printf(Tw1);
  Serial.println();
  matrix_printf(Tw2);
  Serial.println();
  matrix_printf(Tw3);
  Serial.println();

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test 3: Multiplication 4x4");
  //Serial.println(Tw3->nRows);
  //Serial.println(Tw3->nCols);
  matrix_mul(matriceTestMult, Tw0, Tw3);
  matrix_printf(matriceTestMult);
  Serial.println();

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test 4: Inversion 3x3");
  matrix_inv(matriceTestInv, matriceTest1);
  matrix_printf(matriceTestInv);
  Serial.println();

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test 5: cross 1x3 avec 1x3");
  matrix_cross(vecTest12, vecTest1, vecTest2);
  matrix_printf(vecTest1);
  Serial.println();
  matrix_printf(vecTest2);
  Serial.println();
  matrix_printf(vecTest12);
  Serial.println();

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test 6: Inversion 6x6 avec GaussJordan");
  matrix_inv(matriceTestInv, matriceTest1);
  matrix_printf(matriceTestInv);
  Serial.println();
<<<<<<< HEAD

  Serial.println("-----------------------------------------------------------------");
  Serial.println("Test 9: positionCartesiennePatte");
  matrix_printf(Pgoal);
  Serial.println();


=======
>>>>>>> parent of 6e9be56... Cinématique sur arduino 80%
  
  delay(10000);
}
