/*
James' L298 Motor controller library

*/

#include "Arduino.h"
#include "L298Nbridge.h"
/*
MotorController::MotorController(void) {
}

void MotorController::enable(void) {
  pinMode(MOTORENABLE, OUTPUT);
}


static MotorController MC;

*/

DCMotor::DCMotor(uint8_t num) {
  motorNum = num;
  
  inPin1 = inPin1s[motorNum - 1];
  inPin2 = inPin2s[motorNum - 1];
  enPin = enPins[motorNum - 1];
/*  
  switch(num) {
    case 1:
      pinMode(inPin1[0], OUTPUT);
      pinMode(inPin2[0], OUTPUT);
      pinMode(enPin[0], OUTPUT);
      break;
    case 2:
      pinMode(inPin1[1], OUTPUT);
      pinMode(inPin2[1], OUTPUT);
      pinMode(enPin[1], OUTPUT);  
      break;
  }
*/
}

void DCMotor::begin() {
  pinMode(inPin1, OUTPUT);
  pinMode(inPin2, OUTPUT);
  pinMode(enPin, OUTPUT);
}

void DCMotor::run(uint8_t cmd) {
  uint8_t a, b;
  
  switch (motorNum) {
    case 1:
      a = MOTOR1_A; b = MOTOR1_B; break;
    case 2:
      a = MOTOR2_A; b = MOTOR2_B; break;
    default:
      return;
  }
  
  switch(cmd) {
    case FORWARD:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      break;
    case BACKWARD:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      break;
    case BRAKE:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      break;
    case RELEASE:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      break;
  }
}

void DCMotor::setSpeed(uint8_t speed) {
  switch (motorNum) {
    case 1:
      analogWrite(MOTOR1_EN, speed);
      break;
    case 2:
      analogWrite(MOTOR2_EN, speed);
      break;
  }
}