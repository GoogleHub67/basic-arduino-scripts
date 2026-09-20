// Reads variable voltage (0-5V) from a potentiometer
const int POT_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(POT_PIN); // Returns 0 to 1023
  float voltage = rawValue * (5.0 / 1023.0);
  
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage);
  delay(500);
}
