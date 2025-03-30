#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include <DHT.h>

class DHTSensor {
  private:
    DHT dht;

  public:
    // Constructor to initialize the DHT sensor
    DHTSensor(int pin, int type) : dht(pin, type) {}

    // Begin the sensor
    void begin() {
      dht.begin();
    }

    // Get temperature (In celcius)
    float getTemperature() {
      return dht.readTemperature();
    }

    // Get humidity (In percentage)
    float getHumidity() {
      return dht.readHumidity();
    }
};

#endif
