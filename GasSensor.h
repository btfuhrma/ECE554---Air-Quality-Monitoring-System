#ifndef GASSENSOR_H
#define GASSENSOR_H

#include <Arduino.h>

class GasSensor {
  private:
    int pin;

  public:
    GasSensor(int analogPin = A0) {
      pin = analogPin;
    }

    // Setup pin mode
    void begin() {
      pinMode(pin, INPUT);
    }

    // Simulated gas concentration value in ppm
    float getGasConcentration() {
      return 50 + random(-20, 20);  // Simulated values between 30–80 ppm
    }
};

#endif
