#include <DHT.h>

#define DHTPIN 2        // Pin connected to DHT22 data (change this if you use another pin)
#define DHTTYPE DHT22   // DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);

// Simulate altitude data
float getAltitude() {
    // Simulating altitude around 150m, with small fluctuations.
    return 150.0 + (rand() % 10 - 5) * 0.1;  // Altitude will range from 148m to 152m
}

void setup() {
    Serial.begin(9600);
    dht.begin();  // Initialize the DHT sensor (though we're not using it for altitude)
    Serial.println("Simulated Altitude Sensor Test");
}

void loop() {
    // Get simulated altitude
    float altitude = getAltitude();

    // Print the simulated altitude to the Serial Monitor
    Serial.print("Simulated Altitude: ");
    Serial.print(altitude);
    Serial.println(" m");

    delay(2000);  // Wait for 2 seconds between readings
}
