// Implements an internal safety hardware clock that auto-resets the board if the code freezes
#include <avr/wdt.h>

void setup() {
  Serial.begin(9600);
  Serial.println("System starting up safely...");
  delay(500);

  wdt_enable(WDTO_2S); // Enable Watchdog timer. System crashes if not pinged within 2 seconds.
}

void loop() {
  Serial.println("System execution normal.");
  
  wdt_reset(); // "Kick the dog" — Resets the countdown timer to prevent system reboot
  delay(1000); 

  // Simulate a hardware lockup loop condition or extreme crash block
  // If this line ran for more than 2 seconds, the board would force a full chip reset instantly
  // while(true) {} 
}
