#ifndef GAS_SENSOR_H
#define GAS_SENSOR_H

#include <Arduino.h>

#define MQ2_PIN A0  // Pin connected to MQ2 sensor (analog pin)

class GasSensor {
public:
    GasSensor() {}

    // Initialize the MQ2 sensor
    void begin() {
        pinMode(MQ2_PIN, INPUT);
        // Add any additional initialization code here if needed
    }

    // Read the gas sensor value
    int readGasLevel() {
        return analogRead(MQ2_PIN);  // Read the sensor value (0 to 1023)
    }

    // Simulate gas concentration level (For demonstration purposes)
    float getGasConcentration() {
        int sensorValue = analogRead(MQ2_PIN);
        float concentration = map(sensorValue, 0, 1023, 0, 100);  // Map the sensor value to a percentage
        return concentration;  // Simulated gas concentration in percentage
    }
};

#endif
