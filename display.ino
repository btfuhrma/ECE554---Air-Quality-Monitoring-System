//---Wire Connections---
// LED1 to GND
// LED2 to D13
// SSD GND to GND
// SSD VCC to 5V
// SSD SCL to A5
// SSD SDA to A4
//----------------------

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>
#include <stdio.h>

//********REPLACE WITH ACTUAL FUNCTION RETURNS FOR SENSOR READINGS AND UNITS********
#define AIR_QUALITY_THRESHOLD 50.0
#define TEMP_THRESHOLD 50.0
#define HUM_THRESHOLD 50.0
#define PRESSURE_THRESHOLD 50.0
#define GAS_THRESHOLD 40.0
#define ALTITUDE_THRESHOLD 50.0

#define AIR_QUALITY_THRESHOLD_UNITS "UN"
#define TEMP_THRESHOLD_UNITS "UN"
#define HUM_THRESHOLD_UNITS "UN"
#define PRESSURE_THRESHOLD_UNITS "UN"
#define GAS_THRESHOLD_UNITS "UN"
#define ALTITUDE_THRESHOLD_UNITS "UN"
//************************************************************************

const int SCREEN_WIDTH = 128; 
const int SCREEN_HEIGHT = 64; 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int ledPin = 13;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while(true);
  }

  //Led Setup--------------
  pinMode(ledPin, OUTPUT);
  //-----------------------

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 20);
  display.println("AirQuality");
  display.println("Monitoring System");
  display.println("Start-Up...");
  display.display();

  //Delay to add if any sensors have a start-up lag before taking measurements
  delay(5000);
}

void loop() {
  //********REPLACE WITH ACTUAL FUNCTION RETURNS FOR SENSOR READINGS********
  float airQuality = 10.0;
  float temp = 20.0;
  float humidity = 30.0;
  float pressure = 40.0;
  float gas = 50.0;
  float altitude = 60.0;
  //************************************************************************
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);

  int danger1 = set_display_value("Air Quality", AIR_QUALITY_THRESHOLD_UNITS, airQuality, AIR_QUALITY_THRESHOLD);
  int danger2 = set_display_value("Temperature", TEMP_THRESHOLD_UNITS, temp, TEMP_THRESHOLD);
  int danger3 = set_display_value("Humidity", HUM_THRESHOLD_UNITS, humidity, HUM_THRESHOLD);
  int danger4 = set_display_value("Pressure", PRESSURE_THRESHOLD_UNITS, pressure, PRESSURE_THRESHOLD);
  int danger5 = set_display_value("Gas", GAS_THRESHOLD_UNITS, gas, GAS_THRESHOLD);
  int danger6 = set_display_value("Altitude", ALTITUDE_THRESHOLD_UNITS, altitude, ALTITUDE_THRESHOLD);

  int danger_sum = danger1 + danger2 + danger3 + danger4 + danger5 + danger6;
  
  display.setCursor(0, 56);
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.print("WARNINGS :");
  display.print(danger_sum);

  if (danger_sum != 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  display.display();

  //Make delay for HIGHEST lag needed for sensors
  delay(3000); //updates every 3 seconds (can increase or decrease this) 
}

int set_display_value(char *sensor, char *units, float sensor_val, float sensor_threshold)
{
  if(sensor_val <= sensor_threshold) { //safe
    display.setTextColor(WHITE);
    display.print(sensor);
    display.print(":");
    display.print(sensor_val);
    display.print(" ");
    display.println(units);
    return 0;
  } else { //not safe
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    display.print(sensor);
    display.print(":");
    display.println("DANGER");
    return 1;
  }

}
