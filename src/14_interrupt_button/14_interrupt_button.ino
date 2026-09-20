// Uses hardware interrupts to freeze the current execution thread and react instantly to a click
const int INTERRUPT_PIN = 2; // Pin 2 is an interrupt pin on Uno/Nano
const int LED_PIN = 13;
volatile bool motionDetected = false; // "volatile" ensures memory updates mid-loop

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  
  // Trigger the function 'flagEvent' the exact microsecond Pin 2 transitions from HIGH to LOW
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), flagEvent, FALLING);
}

void loop() {
  if (motionDetected) {
    digitalWrite(LED_PIN, HIGH);
    delay(5000); // Visual indicator hold
    digitalWrite(LED_PIN, LOW);
    motionDetected = false; // Reset the flag
  }
}

// Keep interrupt service routines (ISR) incredibly brief! No delays allowed here.
void flagEvent() {
  motionDetected = true; 
}
