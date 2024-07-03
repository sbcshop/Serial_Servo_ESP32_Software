// Interfacing code for onboard programmable Buttons

// Define programmable buttons
const int BT1 = 4;      // Define GPIO4 pin connection for Button 1
const int BT2 = 5;      // Define GPIO5 pin connection for Button 2
const int BT3 = 6;      // Define GPIO6 pin connection for Button 3

void setup(void) {
  Serial.begin(115200);
  // Define buttons as input
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);

}

void loop() {
  int statusBT1 = digitalRead(BT1);
  int statusBT2 = digitalRead(BT2);
  int statusBT3 = digitalRead(BT3);
  Serial.printf("BT1 = %d, BT2 = %d, BT3 = %d \n", statusBT1,statusBT2,statusBT3);
  
  if( statusBT1 == 0) {
    Serial.println("Button 1 Pressed!");
    delay(50);
  }
  
  if ( statusBT2 == 0) {
    Serial.println("Button 2 Pressed!");
    delay(50);
  }
  
  if ( statusBT3 == 0) {
    Serial.println("Button 3 Pressed!");
    delay(50);
  }
  
  delay(100);
}
