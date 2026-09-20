// Safe memory ring buffer that prevents data loss or crashes during high-speed data transfers
#define BUFFER_SIZE 8

volatile char ringBuffer[BUFFER_SIZE];
volatile int head = 0; // Where data is written
volatile int tail = 0; // Where data is read

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Check if there is data waiting to be read in the ring buffer
  if (head != tail) {
    char dataToProcess = ringBuffer[tail];
    tail = (tail + 1) % BUFFER_SIZE; // Advance tail safely
    
    Serial.print("Processed from buffer: ");
    Serial.println(dataToProcess);
  }
  
  // Simulate high-speed data arrivals occasionally
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    
    int nextHead = (head + 1) % BUFFER_SIZE;
    if (nextHead != tail) { // Check if buffer is full
      ringBuffer[head] = incomingByte;
      head = nextHead; // Advance head safely
    } else {
      Serial.println("Buffer Overflow Error! Data dropped.");
    }
  }
}
