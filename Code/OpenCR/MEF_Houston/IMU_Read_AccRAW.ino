/*************************************************** 
  Fonctions de détermination de l'angle du robot à partir des données de l'accéléromètre
 ****************************************************/
/*
  Range   : +/- 2 g
  Scale   : 16384 = 1 g
 */

// Fonction prenant en entrée les valeurs lues de l'accéléromètre et retournant l'angle du robot en x et en y
angleRobot calculAngle(int x, int y, int z){
    angleRobot structAngle;

    if( IMU.update() > 0 ){
      float x2,y2,z2;
    
      float xx = (float)(x - 2130)/16384; //La valeur 2130 a été déterminé suite à l'analyse des valeurs obtenues sur une surface à niveau afin d'ajuster les angles à la valeur qui devait être obtenue
      float yy = (float)(y - 819)/16384;  //La valeur 819 a été déterminé suite à l'analyse des valeurs obtenues sur une surface à niveau afin d'ajuster les angles à la valeur qui devait être obtenue
      float zz = (float)(z + 1147)/16384; //La valeur 1147 a été déterminé suite à l'analyse des valeurs obtenues sur une surface à niveau afin d'ajuster les angles à la valeur qui devait être obtenue

      x2 = xx*xx;
      y2 = yy*yy;
      z2 = zz*zz;

      structAngle.angleX = atan( xx/sqrt(y2+z2) )*180/3.14;
      structAngle.angleY = atan( yy/sqrt(x2+z2) )*180/3.14;
    }

    return structAngle;
}
