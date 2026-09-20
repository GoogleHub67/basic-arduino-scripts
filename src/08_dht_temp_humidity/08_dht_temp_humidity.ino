// Reads environment telemetry using DHT11 or DHT22 sensors
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11 // Swap to DHT22 if needed

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error reading sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("% | Temp: ");
  Serial.print(temperature);
  Serial.println("C");
  delay(2000);
}
