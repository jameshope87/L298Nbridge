/*
  Library for using a L298 dual H bridge Motor driver.
  Created by James A Hope January 2017.
  Released into the public domain.
 
  Connect:
  ENA to D9
  IN1 to D3
  IN2 to D2
 
  ENB to D10
  IN3 to D4
  IN4 to D5
  
  This wiring obviously depends on how you have your motors wired and you should test first with tiral and error!
  
*/
 
#ifndef L298Nbridge_h
#define L298Nbridge_h
 
#include "Arduino.h"
 
//Arduino pin names for motors
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 4
#define MOTOR2_B 5

#define MOTOR1_EN 9
#define MOTOR2_EN 10

//constants for motor run calls
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

/*
class MotorController
{
  public:
    MotorController(void);
    void enable(void);
    friend class DCMotor;
 };
*/

class DCMotor
{
  public:
    DCMotor(uint8_t motornum);
    void run(uint8_t);
    void setSpeed(uint8_t);
  
  private:
    uint8_t motornum;
};
 
#endif