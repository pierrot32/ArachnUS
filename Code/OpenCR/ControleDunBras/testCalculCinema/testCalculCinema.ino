/*************************************************** 
  Tests pour valider les fonctionnalitées du notre code pour la cinématique des pattes
 ****************************************************/


#include "matrix.h"


matrix_obj *matriceTest1;
float index = 0.0;

void setup() {
  matriceTest1 = matrix_construct_zero(3, 3);
  Serial.begin(9600);

}

void loop() {
  matrix_printf(matriceTest1);
  Serial.println();
  index += 0.1;
  matriceTest1->array[1] = index;
  
  delay(500);
}
