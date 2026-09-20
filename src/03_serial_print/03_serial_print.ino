// Streams data back to the computer's Serial Monitor
int counter = 0;

void setup() {
  Serial.begin(9600); // Open connection at 9600 baud rate
  Serial.println("System Initialized...");
}

void loop() {
  Serial.print("Runtime Counter: ");
  Serial.println(counter);
  counter++;
  delay(1000);
}
