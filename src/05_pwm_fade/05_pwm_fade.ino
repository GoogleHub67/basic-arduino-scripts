// Gradually alters LED brightness using Pulse Width Modulation (PWM)
const int PWM_PIN = 9; // Must be a PWM pin (~ symbols on board)

void setup() {
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  // Fade In
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(PWM_PIN, brightness);
    delay(10);
  }
  // Fade Out
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(PWM_PIN, brightness);
    delay(10);
  }
}
