/**
 * MQ2.cpp - Implementation for the MQ2 Gas Sensor library
 * Created by Anthropic, March 31, 2025
 */

 #include "MQ2.h"

 MQ2::MQ2(int pin, float rl) {
   _pin = pin;
   _rl = rl;
   _rsToRoCleanAir = 9.8; // RS/RO ratio in clean air (typical value for MQ2)
 }
 
 void MQ2::begin() {
   pinMode(_pin, INPUT);
   _ro = calibrate();
   Serial.println("MQ2 library initialized");
   Serial.print("Ro = ");
   Serial.print(_ro);
   Serial.println(" kohm");
 }
 
 float MQ2::calibrate() {
   // Take multiple readings and average them
   float rs = 0;
   for (int i = 0; i < 10; i++) {
     rs += readRs();
     delay(100);
   }
   rs = rs / 10.0;
   // Calculate Ro based on RS/RO ratio in clean air
   return rs / _rsToRoCleanAir;
 }
 
 float MQ2::readRs() {
   int val = analogRead(_pin);  // Read analog input
   // Convert analog value to voltage (assuming 5V reference and 10-bit ADC)
   float gasConcentration = map(val, 0, 1023, 0, 500);
   // Calculate sensor resistance from voltage divider formula
   return gasConcentration;
 }
 
 float MQ2::readGasConcentration() {
   // Read sensor 
   float rs = readRs();
   return rs;
 }
 
 float MQ2::readSpecificGas(float a, float b) {
   // Read sensor resistance
   float rs = readRs();
   // Calculate rs/ro ratio
   float rsRoRatio = rs / _ro;
   // Calculate gas concentration in ppm using power function with provided parameters
   return a * pow(rsRoRatio, b);
 }
 
 float MQ2::readLPG() {
   // Parameters for LPG
   return readSpecificGas(591.6, -2.0);
 }
 
 float MQ2::readCO() {
   // Parameters for CO
   return readSpecificGas(36974.0, -3.109);
 }
 
 float MQ2::readSmoke() {
   // Parameters for Smoke
   return readSpecificGas(3426.0, -2.86);
 }
