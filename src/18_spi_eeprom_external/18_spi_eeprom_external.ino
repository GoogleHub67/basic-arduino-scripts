// Communicates with external sensors and chips using the high-speed SPI bus protocol
#include <SPI.h>

const int CHIP_SELECT_PIN = 10; // Pin used to alert the target slave device

void setup() {
  Serial.begin(9600);
  pinMode(CHIP_SELECT_PIN, OUTPUT);
  digitalWrite(CHIP_SELECT_PIN, HIGH); // Keep communication line closed initially

  SPI.begin(); // Initialize the SPI bus lines (MOSI, MISO, SCK)
}

void loop() {
  // Begin transaction with the device
  digitalWrite(CHIP_SELECT_PIN, LOW);
  
  SPI.transfer(0x06); // Standard instruction command: Write Enable command byte
  
  digitalWrite(CHIP_SELECT_PIN, HIGH); // Close transaction line
  delay(1000);
}
