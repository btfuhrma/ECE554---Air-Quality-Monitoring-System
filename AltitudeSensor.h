#ifndef ALTITUDE_SENSOR_H
#define ALTITUDE_SENSOR_H

#include <DHT.h>

#define DHTPIN 2        // Pin connected to DHT22 data
#define DHTTYPE DHT22   // DHT 22 (AM2302)

class AltitudeSensor {
public:
    AltitudeSensor() : dht(DHTPIN, DHTTYPE) {}

    void begin() {
        dht.begin();
    }

    float getAltitude() {
        return 150.0 + (rand() % 10 - 5) * 0.1;
    }

private:
    DHT dht;
};

#endif
