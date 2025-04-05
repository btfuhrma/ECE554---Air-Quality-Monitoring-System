#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD at address 0x27, 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Air Pressure Mon");
  delay(2000);
  lcd.clear();
}

void loop() {
  long pressure = getPressure();

  // Serial Output
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" Pa");
  Serial.println("------------------------");

  // LCD Display: Show Pressure
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pressure:");
  lcd.setCursor(0, 1);
  lcd.print(pressure / 100);  // Convert Pa to hPa
  lcd.print(" hPa");
  delay(2000);

  // LCD Alert
  lcd.clear();
  if (pressure > 102000) {
    lcd.print("ALERT: High Pres");
    Serial.println("ALERT: High Pressure!");
  } else if (pressure < 99000) {
    lcd.print("ALERT: Low Pres");
    Serial.println("ALERT: Low Pressure!");
  } else {
    lcd.print("Pressure Normal");
    Serial.println("Pressure Normal");
  }

  Serial.println();
  delay(2000);
}

// Simulated Pressure
long getPressure() {
  return 101325 + random(-3000, 3000);  // Wider range for faster fluctuation
}
