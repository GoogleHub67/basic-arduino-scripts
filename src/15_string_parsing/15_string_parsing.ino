// Parses structured text input arrays (like "255,0,120") sent over the Serial monitor
void setup() {
  Serial.begin(9600);
  Serial.println("Type three numbers separated by commas (ex: 12,54,99):");
}

void loop() {
  if (Serial.available() > 0) {
    // Read numbers straight out of the incoming text buffer
    int val1 = Serial.parseInt(); 
    int val2 = Serial.parseInt();
    int val3 = Serial.parseInt();

    // Look for the terminating newline character
    if (Serial.read() == '\n') {
      Serial.print("Parsed Channel A: "); Serial.println(val1);
      Serial.print("Parsed Channel B: "); Serial.println(val2);
      Serial.print("Parsed Channel C: "); Serial.println(val3);
    }
  }
}
