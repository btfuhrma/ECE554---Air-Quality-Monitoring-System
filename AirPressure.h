/*Pins connection:
VCC to 5V
GND	to GND
SCL	to A5
SDA	to A4 
*/

#ifndef AIR_PRESSURE_SENSOR_H
#define AIR_PRESSURE_SENSOR_H

#include <Wire.h>

#define I2C_SENSOR_ADDR 0x76  // Simulated BMP sensor address

class AirPressureSensor {
public:
    AirPressureSensor() {}

    // Initialize the sensor
    void begin() {
        Wire.begin();
        // Add any sensor initialization code here if needed
    }

    // Simulated Temperature
    float getTemperature() {
        return 25.0 + (random(-10, 10) / 10.0);  // Generates a random temp near 25°C
    }

    // Simulated Pressure
    long getPressure() {
        return 101325 + random(-500, 500);  // Generates random pressure near 101325 Pa
    }

    // Simulated Altitude
    float getAltitude() {
        return 50.0 + (random(-5, 5));  // Generates a random altitude near 50m
    }

private:
    // If you have any sensor-specific private methods or members, they can go here.
};

#endif