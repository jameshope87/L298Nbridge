/*
James' L298 Motor controller library

*/

#include "Arduino.h"
#include "L298Nbridge.h"


DCMotor::DCMotor(uint8_t num, uint8_t inPin1, uint8_t inPin2, uint8_t enPin) {
  motorNum = num;
  
  _inPin1s[motorNum - 1] = inPin1;
  _inPin2s[motorNum - 1] = inPin2;
  _enPins[motorNum - 1] = enPin;

}

void DCMotor::begin() {
  pinMode(_inPin1s[motorNum - 1], OUTPUT);
  pinMode(_inPin2s[motorNum - 1], OUTPUT);
  pinMode(enPin, OUTPUT);
}

void DCMotor::run(uint8_t cmd) {
  uint8_t a, b;
  
  switch(cmd) {
    case FORWARD:
      digitalWrite(_inPin1s[motorNum - 1], HIGH);
      digitalWrite(_inPin2s[motorNum - 1], LOW);
      break;
    case BACKWARD:
      digitalWrite(_inPin1s[motorNum - 1], LOW);
      digitalWrite(_inPin2s[motorNum - 1], HIGH);
      break;
    case BRAKE:
      digitalWrite(_inPin1s[motorNum - 1], LOW);
      digitalWrite(_inPin2s[motorNum - 1], LOW);
      break;
    case RELEASE:
      digitalWrite(_enPins[motorNum - 1], LOW);
      break;
  }
}

void DCMotor::setSpeed(uint8_t speed) {
  analogWrite(_enPins[motorNum - 1], speed);
}