// Standard array filter that smooths out jumpy, noisy sensor data signals using a rolling average
const int WINDOW_SIZE = 5;
int readings[WINDOW_SIZE]; // Array holding the last few raw read instances
int readIndex = 0;
long totalSum = 0;
int smoothAverage = 0;

void setup() {
  Serial.begin(9600);
  // Zero out the entire array data register space on boot
  for (int i = 0; i < WINDOW_SIZE; i++) readings[i] = 0;
}

void loop() {
  totalSum -= readings[readIndex];       // Subtract the oldest history entry
  readings[readIndex] = analogRead(A0);  // Read newest sensor data into index slot
  totalSum += readings[readIndex];       // Add the new sample to the total sum
  
  readIndex = (readIndex + 1) % WINDOW_SIZE; // Roll the index counter smoothly

  smoothAverage = totalSum / WINDOW_SIZE; // Compute final output
  
  Serial.print("Smoothed Signal: ");
  Serial.println(smoothAverage);
  delay(50);
}
