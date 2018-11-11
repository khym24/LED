#include <LED_Diagnostics.h>
#include <MacRocketry_GPS_Shield.h>

LED_Diagnostics::LED_Diagnostics(){
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void LED_Diagnostics::statusCheck(int fix){
  err = 0;
  if (CHECK_BMP()){
    err += 100;
  }
  if (fix>0){
    err += 10;
  }
  if(SD_CHECK()){
    err += 1;
  }
  displayLED(err); 
  //if(case != PRE_LAUNCH)
  //  return; 
}

boolean LED_Diagnostics::CHECK_BMP(){

}

boolean LED_Diagnostics::SD_CHECK(){

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
