/*
  Library for using a L298 dual H bridge Motor driver.
  Created by James A Hope January 2017.
  Released into the public domain.
  
*/
 
#ifndef L298Nbridge_h
#define L298Nbridge_h
 
#include "Arduino.h"


//constants for motor run calls
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4


class DCMotor
{
  public:
    DCMotor(uint8_t num, uint8_t Pin1, uint8_t Pin2, uint8_t enPin);
    void begin();
    void run(uint8_t);
    void setSpeed(uint8_t);
  
  private:
    uint8_t _motorNum;
    uint8_t _Pin1;
    uint8_t _Pin2;
    uint8_t _enPin;
};
 
#endif