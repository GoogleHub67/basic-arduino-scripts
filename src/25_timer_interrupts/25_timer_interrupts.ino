// Configures internal hardware Timer1 to trigger code strictly based on clock ticks
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  noInterrupts(); // Disable all interrupts while configuring registers
  
  TCCR1A = 0;     // Clear Timer1 Control Registers
  TCCR1B = 0;
  TCNT1  = 0;     // Initialize counter value to 0
  
  // Set Compare Match Register for exactly 1Hz (1 second) intervals
  // Formula: (16MHz / (prescaler * targeted frequency)) - 1
  OCR1A = 15624;  // = (16,000,000 / (1024 * 1)) - 1
  
  TCCR1B |= (1 << WGM12);  // Turn on CTC (Clear Timer on Compare) mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // Set 1024 prescaler
  TIMSK1 |= (1 << OCIE1A); // Enable timer compare interrupt
  
  interrupts();   // Re-enable all global interrupts
}

// Hardware-triggered Interrupt Service Routine (ISR) when Timer1 matches OCR1A
ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle the state of the pin
}

void loop() {
  // Main program thread is completely empty, yet the LED blinks perfectly via hardware!
}
