
#include "Cinematique.h"
#include "gaussjordan.h"

matrix_obj *q;
matrix_obj *Tw0;  
matrix_obj *Tw1;
matrix_obj *Tw2;
matrix_obj *Tw3;
matrix_obj *TwF;

void cinematiqueBegin(){
  q = matrix_construct_zero(3, 1);
  q->array[0] = qv;
  q->array[1] = qbx;
  
  Tw0 = matrix_construct_zero(4, 4);
  Tw0->array[0] = cos(20);
  Tw0->array[1] = sin(20);
  Tw0->array[4] = -sin(20);
  Tw0->array[5] = cos(20);
  Tw0->array[10] = 1;
  Tw0->array[15] = 1;     
  
  // Recherce de la cinématique directe
  TwF = matrix_construct_zero(4, 12); 
  for (int i=0; i<48; i++){
    if (i<=3 || (i>=12 && i<=15) || (i>=24 && i<=27) || (i>=36 && i<=39)){
       TwF->array[i] = 1.1;
    } else if ((i>=4 && i<=7) || (i>=16 && i<=19) || (i>=28 && i<=31) || (i>=40 && i<=43)){
      TwF->array[i] = 2.2;
    } else if ((i>=8 && i<=11) || (i>=20 && i<=23) || (i>=32 && i<=35) || (i>=44 && i<=47)){
      TwF->array[i] = 3.3;
    }
  }
  //TwF = transMat_w2f(q, Tw0);
  
  Tw1 = matrix_construct_zero(4, 4);
  Tw2 = matrix_construct_zero(4, 4);
  Tw3 = matrix_construct_zero(4, 4);
  matrix_copie_part(Tw1, TwF, 1, 1, 4, 4);
  matrix_copie_part(Tw2, TwF, 1, 5, 4, 8);
  matrix_copie_part(Tw3, TwF, 1, 9, 4, 12);

}

/*matrix_obj * EulerXYZtoRot(float Euler[3]){
  float c1 = cos(Euler[0]);
  float s1 = sin(Euler[0]);
  float c2 = cos(Euler[1]);
  float s2 = sin(Euler[1]);
  float c3 = cos(Euler[2]);
  float s3 = sin(Euler[2]);

  float m11 = c2*c3;
  float m12 = c1*s3 + c3*s1*s2;
  float m13 = s1*s3 - c1*c3*s2;
  float m21 = -c2*s3;
  float m22 = c1*c3 - s1*s2*s3;
  float m23 = c3*s1 + c1*s2*s3;
  float m31 = s2;
  float m32 = -c2*s1;
  float m33 = c1*c2;

  return matrix_obj Q[3][3] = {{m11, m12, m13},
                                 {m21, m22, m23},
                                 {m31, m32, m33},
                                };
                   
}*/

