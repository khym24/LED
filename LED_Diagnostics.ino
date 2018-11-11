#include <MacRocketry_GPS_Shield.h> //header file

#define redPin 3
#define bluePin 6
#define greenPin 5
//#define button 2

int message = 0;

bool buttonState = false;

void displayLED(int msg){
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

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  //pinMode(button, INPUT);

  //Serial.begin(9600);
}
void loop() {
  
  err = 0;
   
  //alt = bmp.pressureToAltitude(seaLvlPressure, pressure);
  if (CHECK_BMP)
  //if (abs(P-seaLvlPressure) > seaLvlPressure*0.1){
    err += 100;
  }
  if (MacRocketry_GPS_Shield::readData() == false || MacRocketry_GPS_Shield::bufferSerial() == false){
    err += 10;
  }
  if(MacRocketry_SD_Logger::start() == false){
    err += 1;
  }
  displayLED(err); 
  if(case != PRE_LAUNCH)
    return; 
}
/*
void loop() { 
  if(GPS_CHECK() || BMP_CHECK() || SD_CHECK()){
    displayLED(1);
    }else{
    displayLED(0);
}
 */
}
