/*
* Motor Mode Example
*/

#include <SBServo.h>

SBServo sb; //create instance

// GPIO 18 - S_RXD, GPIO 17 - S_TXD, as default.
#define S_RXD 18
#define S_TXD 17

const int ID = 0x02; // Change Motor ID as per your Serial Servo Motor 

void setup()
{
  Serial1.begin(115200, SERIAL_8N1, S_RXD, S_TXD);
  sb.pSerial = &Serial1; 
  delay(1000);
  sb.PWMMode(ID);  // define ID of motor to control 
}

void loop()
{
  sb.WritePWM(ID, 1000);  // ID, speed 
  delay(2000);
  sb.WritePWM(ID, 0);   // stop motor
  delay(2000);
  sb.WritePWM(ID, -1000);  // reverse direction
  delay(2000);
  sb.WritePWM(ID,0);
  delay(2000);
}
