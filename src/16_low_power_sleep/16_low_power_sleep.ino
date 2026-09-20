// Shuts down internal microcontroller clocks to save massive amounts of battery power
#include <avr/sleep.h>

const int WAKE_PIN = 2;

void setup() {
  pinMode(WAKE_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Flash LED to signal active status
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.println("Going into deep sleep mode now...");
  delay(100); // Allow text buffer to clear before clock stop
  
  goToSleep();
  
  Serial.println("Just woke up!");
}

void goToSleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Deepest power saving option
  sleep_enable();                      // Arm the sleep bit
  
  // Attach wakeup event to Pin 2 low state change
  attachInterrupt(digitalPinToInterrupt(WAKE_PIN), wakeUpRoutine, LOW);
  
  sleep_cpu();                         // Complete system freeze happens here
  
  // --- THE CODE CONTINUES RUNNING HERE AFTER PIN 2 WAKES IT UP ---
  sleep_disable();                     // Safety clear bits
  detachInterrupt(digitalPinToInterrupt(WAKE_PIN));
}

void wakeUpRoutine() {
  // Abstract placeholder execution block
}
