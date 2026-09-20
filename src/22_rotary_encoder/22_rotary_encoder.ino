// Tracks the exact rotation and position of industrial volume dials or robot wheels
const int CLK_PIN = 2; // Needs interrupt capability
const int DT_PIN = 3;

volatile int encoderPosition = 0;
int lastClkState;

void setup() {
  Serial.begin(9600);
  pinMode(CLK_PIN, INPUT);
  pinMode(DT_PIN, INPUT);
  
  lastClkState = digitalRead(CLK_PIN);
  
  // Instantly trigger when the dial rotates
  attachInterrupt(digitalPinToInterrupt(CLK_PIN), readEncoder, CHANGE);
}

void loop() {
  static int lastPrintedPosition = 0;
  if (encoderPosition != lastPrintedPosition) {
    Serial.print("Position: ");
    Serial.println(encoderPosition);
    lastPrintedPosition = encoderPosition;
  }
}

void readEncoder() {
  int clkState = digitalRead(CLK_PIN);
  if (clkState != lastClkState && clkState == HIGH) {
    // If DT state is different from CLK, it is rotating clockwise
    if (digitalRead(DT_PIN) != clkState) {
      encoderPosition++;
    } else {
      encoderPosition--;
    }
  }
  lastClkState = clkState;
}
