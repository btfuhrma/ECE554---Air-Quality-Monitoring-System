// ino file that is updated from the wokwi online simulator
// https://wokwi.com/

#include "DHTSensor.h"
#include "Display.h"

// Pin definitions and sensor type
#define DHT_PIN 2 // Can change this later if necessary
#define DHT_TYPE DHT22

DHTSensor dhtSensor(DHT_PIN, DHT_TYPE);
Display display;

void setup() {
  Serial.begin(9600);

  // Initialize sensor and display
  dhtSensor.begin();
}

void loop() {
  // Get temperature and humidity
  float temperature = dhtSensor.getTemperature();
  float humidity = dhtSensor.getHumidity();

  // Timer for delays, we can always change it
  delay(2000);
}
