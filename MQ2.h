/**
 * MQ2.h - Library for using MQ2 Gas Sensor
 * MQ2 sensor can detect LPG, smoke, alcohol, propane, hydrogen, methane and carbon monoxide
 */

 #include <Arduino.h>
 
 #ifndef MQ2_H
 #define MQ2_H
 
 class MQ2 {
   private:
     int _pin;
     float _ro;      // Ro is initialized resistance of the sensor in clean air
     float _rl;      // The load resistance on the board, in kilo ohms
     float _rsToRoCleanAir; // RS/RO ratio in clean air (typically 9.8)
     
     // Parameters for calculating ppm from sensor resistance
     float _a = 574.25;
     float _b = -2.222;
     
     // Calibration function
     float calibrate();
     
   public:
     /**
      * Constructor
      * @param pin - The analog pin the sensor is connected to
      * @param rl - The load resistance on the board in kilo ohms (default 10)
      */
     MQ2(int pin, float rl = 10.0);
     
     /**
      * Initialize the sensor
      */
     void begin();
     
     /**
      * Read the sensor resistance
      * @return The sensor resistance in clean air
      */
     float readRs();
     
     /**
      * Read gas concentration in ppm
      * @return Gas concentration in parts per million (ppm)
      */
     float readGasConcentration();
     
     /**
      * Read specific gas concentration
      * @param a - Parameter a for gas type
      * @param b - Parameter b for gas type
      * @return Specific gas concentration in ppm
      */
     float readSpecificGas(float a, float b);
     
     /**
      * Read LPG concentration
      * @return LPG concentration in ppm
      */
     float readLPG();
     
     /**
      * Read CO concentration
      * @return CO concentration in ppm
      */
     float readCO();
     
     /**
      * Read Smoke concentration
      * @return Smoke concentration in ppm
      */
     float readSmoke();
 };
 
 #endif