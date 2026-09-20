// Creates manual PWM signal pulses using microsecond math to control servos without libraries
const int OUTPUT_PIN = 9;

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
  // Manually generate a 1.5ms pulse over a standard 20ms frame loop (centers a servo arm)
  digitalWrite(OUTPUT_PIN, HIGH);
  delayMicroseconds(1500); 
  digitalWrite(OUTPUT_PIN, LOW);
  delayMicroseconds(18500); 
}
