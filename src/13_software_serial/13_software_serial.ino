// Creates a secondary virtual Serial port on digital pins to talk to Bluetooth/GPS modules
#include <SoftwareSerial.h>

const int RX_PIN = 10;
const int TX_PIN = 11;

// Define a new serial port instance
SoftwareSerial externalSerial(RX_PIN, TX_PIN); 

void setup() {
  Serial.begin(9600);         // Communication port with the computer
  externalSerial.begin(9600); // Communication port with the external sensor module
  
  Serial.println("Dual serial lines established.");
}

void loop() {
  // If data comes in from the sensor, forward it to the computer screen
  if (externalSerial.available()) {
    char data = externalSerial.read();
    Serial.print(data);
  }
}
