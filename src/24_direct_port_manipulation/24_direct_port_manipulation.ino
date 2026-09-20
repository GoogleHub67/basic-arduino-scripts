// Bypasses the slow digitalWrite() function entirely to flip pins at raw clock speeds
void setup() {
  // Set Pin 13 (Bit 5 of Port B on Uno/Nano) as an output
  // DDRB is the Data Direction Register for Port B
  DDRB |= B00100000; 
}

void loop() {
  // PORTB drives the pins HIGH or LOW directly in 1 clock cycle (~62.5 nanoseconds)
  PORTB |= B00100000;  // Turn Pin 13 HIGH
  delay(500);
  
  PORTB &= ~B00100000; // Turn Pin 13 LOW
  delay(500);
}
