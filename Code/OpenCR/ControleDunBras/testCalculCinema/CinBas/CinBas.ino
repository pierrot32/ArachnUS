

matrix_obj * EulerXYZtoRot(float Euler[3]){
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

  /*return matrix_obj Q[3][3] = {{m11, m12, m13},
                                 {m21, m22, m23},
                                 {m31, m32, m33},
                                };
                   */
}

