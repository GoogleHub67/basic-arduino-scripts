// Proportional-Integral-Derivative control loop: Used for precise heating systems or cruise control
float setpoint = 100.0; // The target value we want to achieve
float kp = 2.0, ki = 0.5, kd = 1.0; // Tuning constants

float integral = 0, lastError = 0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
  lastTime = millis();
}

void loop() {
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0; // Calculate time delta in seconds
  
  if (dt > 0.1) { // Run the loop every 100ms
    float currentReading = analogRead(A0) * (150.0 / 1023.0); // Simulated sensor scaling
    float error = setpoint - currentReading;
    
    integral += error * dt;
    float derivative = (error - lastError) / dt;
    
    // Core PID Math formula
    float outputPWM = (kp * error) + (ki * integral) + (kd * derivative);
    outputPWM = constrain(outputPWM, 0, 255); // Keep output within hardware limits (analogWrite)
    
    analogWrite(9, outputPWM); // Drive the actuator/heater
    
    lastError = error;
    lastTime = now;
    
    Serial.print("Target: "); Serial.print(setpoint);
    Serial.print(" | Current: "); Serial.print(currentReading);
    Serial.print(" | Correction Output: "); Serial.println(outputPWM);
  }
}
