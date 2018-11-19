#include <LED_Diagnostics.h>
#include <MacRocketry_GPS_Shield.h>
#include <MacRocketry_SD_Logger.h>
#include <cmath>

LED_Diagnostics::LED_Diagnostics(){
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void LED_Diagnostics::statusCheck(int fix, float gps_alt, float bmp_alt){
  err = 0;
  if (CHECK_BMP(float gps_alt, float bmp_alt)){   //checks if the bmp and gps altitude values match up
    err += 100;
  }
  if (fix = 0){     //checks that the gps is spitting out values
    err += 10;      //
  }
  if(SD_CHECK()){
    err += 1;
  }
  displayLED(err); 
  //if(case != PRE_LAUNCH)
  //  return; 
}

boolean LED_Diagnostics::CHECK_BMP(float gps_alt, float bmp_alt){
  if (abs(gps_alt-bmp_alt) > 1.0)) {    // 1.0 is a place holder number, run tests to get a better range
    return true;
  }
  return false;
}

boolean LED_Diagnostics::SD_CHECK(String path){
  bool connectFile = openFile(path);
  String checkVal = 
}

void LED_Diagnostics::displayLED(int msg){
  switch (msg){
    case 110//red -> BMP and GPS errors
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 0);
      break;
    case 1: //blue -> SD card error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;
    case 0: //green -> no errors
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
    case 100//purple -> GPS error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;
    case 10: //yellow -> BMP error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
    case 011: //cyan -> sensor + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    case 101: //cyan -> sensor + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    case -1: //white -> not used
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
  }
  
}
