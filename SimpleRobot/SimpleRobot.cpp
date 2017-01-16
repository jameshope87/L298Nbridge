/*******************************************************
  SimpleRobot.h
  low level motor driver interface

  For use with the custom L298Nbridge library
********************************************************/

#include <Arduino.h>  
#include <L298Nbridge.h>  // adafruit motor shield library
#include "SimpleRobot.h"

const int differential = 0;

const int MIN_SPEED = 40; // first table entry is 40% speed

const int MIN_SPEED = 40; // first table entry is 40% speed
const int SPEED_TABLE_INTERVAL = 10; // each table entry is 10% faster speed
const int NBR_SPEEDS =  1 + (100 - MIN_SPEED)/ SPEED_TABLE_INTERVAL;
 
int speedTable[NBR_SPEEDS]  =  {40,     50,   60,   70,   80,   90,  100}; // speeds  
int rotationTime[NBR_SPEEDS] = {5500, 3300, 2400, 2000, 1750, 1550, 1150}; // time 

DCMotor motors[] = {
  DCMotor(1), // left is Motor #1 
  DCMotor(2)  // right is Motor #2
};

int  motorSpeed[2]  = {0,0};

void robotBegin()
{
  robotStop();  // stop the front motor   
}

// speed range is 0 to 100 percent
void robotSetSpeed(int speed)
{
  motorSpeed[MOTOR_RIGHT] = speed;
  motorSpeed[MOTOR_LEFT] = speed;
  if( motor == MOTOR_LEFT && speed > differential)
    motorSpeed[MOTOR_LEFT] = speed - differential;
  
  int rpwm = map(motorSpeed[MOTOR_RIGHT], 0,100, 0,255);  // scale to PWM range
  int lpwm = map(motorSpeed[MOTOR_LEFT], 0,100, 0,255);  // scale to PWM range
  
  motors[MOTOR_LEFT].setSpeed(lpwm);
  motors[MOTOR_RIGHT].setSpeed(rpwm);
}

void robotForward(int speed)
{
  robotSetSpeed(0);
  motors[MOTOR_LEFT].run(FORWARD);
  motors[MOTOR_RIGHT].run(FORWARD);
  for (uint8_t i=0; i<speed; i++) {
    robotSetSpeed(i);
    delay(10);
  }
}

void robotReverse(int speed)
{
  robotSetSpeed(0);
  motors[MOTOR_LEFT].run(BACKWARD);
  motors[MOTOR_RIGHT].run(BACKWARD); 
  for (uint8_t i=0; i<speed; i++) {
    robotSetSpeed(i);
    delay(10);
  }
}

void robotStop()
{
  robotSetSpeed(0);      // stopped
}

void robotBrake()
{
  motors[MOTOR_LEFT].run(BRAKE);
  motors[MOTOR_RIGHT].run(BRAKE);
}

void robotTurnRight(int speed)
{
  robotSetSpeed(0);
  motors[MOTOR_LEFT].run(FORWARD);
  motors[MOTOR_RIGHT].run(BACKWARD);
  for (uint8_t i=0; i<speed; i++) {
    robotSetSpeed(i);
    delay(10);
  }
}

void robotTurnLeft(int speed)
{
  robotSetSpeed(0);
  motors[MOTOR_LEFT].run(BACKWARD);
  motors[MOTOR_RIGHT].run(FORWARD);
  for (uint8_t i=0; i<speed; i++) {
    robotSetSpeed(i);
    delay(10);
  }
}