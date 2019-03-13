/*
  Range   : +/- 2000 deg/sec
  Scale   : 16.4 = 1 deg/sec
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

float nouveauTemps = 0;
float ancienTemps = 0;

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
  ancienTemps = nouveauTemps;
  nouveauTemps = millis();

  
  if( (millis()-tTime[1]) >= 50 )
  {
    tTime[1] = millis();
    if( IMU.update() > 0 ){
      aRobot = calculAngle(aRobot, IMU.gyroRaw[0],IMU.gyroRaw[1], IMU.gyroRaw[2], ancienTemps, nouveauTemps);
    }
    
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

angleRobot calculAngle(angleRobot structAngle, int x, int y, int z, float ancienTemps2, float nouveauTemps2){

    
     float xx = (float)(x)/16.4;
     float yy = (float)(y)/16.4;    
     float zz = (float)(z)/16.4;
    
      
    structAngle.angleX = structAngle.angleX + xx*((nouveauTemps2-ancienTemps2)/1000.0);
    structAngle.angleY = structAngle.angleY + yy*((nouveauTemps2-ancienTemps2)/1000.0);
    
    return structAngle;
}




 
/*
  if( (millis()-tTime[1]) >= 50 )
  {
    tTime[1] = millis();

    Serial.print(imu_time);
    Serial.print(" \t");
    Serial.print(IMU.gyroRaw[0]);    // GYRO X
    Serial.print(" \t");
    Serial.print(IMU.gyroRaw[1]);    // GYRO Y
    Serial.print(" \t");
    Serial.print(IMU.gyroRaw[2]);    // GYRO Z
    Serial.println(" ");
*/
