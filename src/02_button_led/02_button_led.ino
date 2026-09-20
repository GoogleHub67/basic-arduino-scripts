// Turns on an LED when a push button is pressed
const int BUTTON_PIN = 2;
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // Uses internal pull-up resistor (button connects pin 2 to GND)
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
}

void loop() {
  // LOW means button is pressed when using INPUT_PULLUP
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
