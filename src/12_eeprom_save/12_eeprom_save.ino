// Saves configuration memory settings permanently through hardware resets
#include <EEPROM.h>

const int MEMORY_ADDRESS = 0;
int deviceRunCount = 0;

void setup() {
  Serial.begin(9600);
  
  // Read value stored in EEPROM address
  deviceRunCount = EEPROM.read(MEMORY_ADDRESS);
  deviceRunCount++;

  Serial.print("This board has turned on ");
  Serial.print(deviceRunCount);
  Serial.println(" times.");

  // Save updated value back into permanent onboard storage
  EEPROM.write(MEMORY_ADDRESS, deviceRunCount);
}

void loop() {
  // Nothing to loop
}
