/*
  Range   : +/- 2 g
  Scale   : 16384 = 1 g
 */

#include <IMU.h>

cIMU    IMU;

//--------------------------------------------
// Definition des variables et des constant (GLOBAL)

typedef struct angleRobot{
  float angleX = 0.0;
  float angleY = 0.0;
};

angleRobot aRobot;


uint8_t   led_tog = 0;
uint8_t   led_pin = 13;

static uint32_t tTime[3];
static uint32_t imu_time = 0;

//--------------------------------------------
// Setup

void setup()
{
  Serial.begin(115200);
  IMU.begin();
  pinMode( led_pin, OUTPUT );
}


//--------------------------------------------
// loop


void loop()
{
  if( (millis()-tTime[1]) >= 50 )
  {
    tTime[1] = millis();

    aRobot = calculAngle(IMU.accRaw[0],IMU.accRaw[1], IMU.accRaw[2]);

    
    Serial.print("Angle en X :"); 
    Serial.print(aRobot.angleX);
    Serial.print(" \t");
    Serial.print("Angle en Y :"); 
    Serial.print(aRobot.angleY);
    Serial.println(" ");
  }
}

//--------------------------------------------
// Definition des fonction

angleRobot calculAngle(int x, int y, int z){
    angleRobot structAngle;

    if( IMU.update() > 0 ){
      float x2,y2,z2;
    
      float xx = (float)(x)/16384;
      float yy = (float)(y)/16384;    
      float zz = (float)(z)/16384;
    

      x2 = xx*xx;
      y2 = yy*yy;
      z2 = zz*zz;

      structAngle.angleX = atan( xx/sqrt(y2+z2) )*180/3.14;
      structAngle.angleY = atan( yy/sqrt(x2+z2) )*180/3.14;
    }

    return structAngle;
}


