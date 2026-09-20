// Measures remaining SRAM to prevent silent execution crashes from dynamic allocation memory leaks
extern int __heap_start, *__brkval;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Free SRAM Memory Left: ");
  Serial.print(getFreeMemory());
  Serial.println(" Bytes");
  delay(2000);
}

// Function to calculate exact distance between stack pointer and top of the heap
int getFreeMemory() {
  int free_memory;
  if ((int)__brkval == 0) {
    free_memory = ((int)&free_memory) - ((int)&__heap_start);
  } else {
    free_memory = ((int)&free_memory) - ((int)__brkval);
  }
  return free_memory;
}
