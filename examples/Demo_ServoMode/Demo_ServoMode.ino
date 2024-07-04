/*
 * Demo code for Servo Mode operation 
*/

#include <SBServo.h>

SBServo sb;

// GPIO 18 - S_RXD, GPIO 17 - S_TXD, as default.
#define S_RXD 18
#define S_TXD 17

const int ID = 0x02; // Change ID as per your Serial Servo Motor 

void setup()
{
  Serial1.begin(115200, SERIAL_8N1, S_RXD, S_TXD);
  sb.pSerial = &Serial1;
  delay(1000);
}


void loop()
{
  sb.WritePos(ID, 1000, 0, 1500);  // SERVO ID, Position, Time, Speed; => 1500 Steps/Seconds,
  delay(754);

  sb.WritePos(ID, 20, 0, 1500);  // SERVO ID, Position, Time, Speed; => 1500 Steps/Seconds,
  delay(754);

}
