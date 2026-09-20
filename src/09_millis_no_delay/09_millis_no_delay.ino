// Blinks an LED without blocking code operations using time deltas
const int LED_PIN = 13;
unsigned long previousMillis = 0;
const long interval = 1000; // 1 second threshold
int ledState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis(); // Milliseconds passed since startup

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Reset timestamp

    ledState = (ledState == LOW) ? HIGH : LOW;
    digitalWrite(LED_PIN, ledState);
  }
  // Other fast-running tasks can execute here without getting stuck!
}
