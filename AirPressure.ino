/*Pins connection:
VCC to 5V
GND	to GND
SCL	to A5
SDA	to A4 
*/

#include <Wire.h>

#define I2C_SENSOR_ADDR 0x76  // Simulated BMP sensor address

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(getTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(getPressure());
  Serial.println(" Pa");

  Serial.print("Altitude = ");
  Serial.print(getAltitude());
  Serial.println(" meters");

  Serial.println("------------------------");
  delay(2000);
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
