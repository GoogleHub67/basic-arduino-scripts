// Handles state tracking engine configurations cleanly
enum SystemState { SAFE, WARNING, CRITICAL };
SystemState currentState = SAFE;

void setup() {
  Serial.begin(9600);
}

void loop() {
  switch (currentState) {
    case SAFE:
      Serial.println("Status Clear.");
      delay(2000);
      currentState = WARNING; // Change state statefully
      break;
    case WARNING:
      Serial.println("System Alert Active!");
      delay(2000);
      currentState = CRITICAL;
      break;
    case CRITICAL:
      Serial.println("Emergency Shutdown Event Triggered!");
      delay(5000);
      currentState = SAFE;
      break;
  }
}
