/*
James' L298 Motor controller library

*/

#include "Arduino.h"
#include "L298Nbridge.h"


DCMotor::DCMotor(uint8_t num, uint8_t Pin1, uint8_t Pin2, uint8_t enPin) {
    _motorNum = num;
    _Pin1 = Pin1;
    _Pin2 = Pin2;
    _enPin = enPin;
}

void DCMotor::begin() {
  pinMode(_Pin1, OUTPUT);
  pinMode(_Pin2, OUTPUT);
  pinMode(_enPin, OUTPUT);
}

void DCMotor::run(uint8_t cmd) {
  uint8_t a, b;
  
  switch(cmd) {
    case FORWARD:
      digitalWrite(_Pin1, HIGH);
      digitalWrite(_Pin2, LOW);
      break;
    case BACKWARD:
      digitalWrite(_Pin1, LOW);
      digitalWrite(_Pin2, HIGH);
      break;
    case BRAKE:
      digitalWrite(_Pin1, LOW);
      digitalWrite(_Pin2, LOW);
      break;
    case RELEASE:
      digitalWrite(_enPin, LOW);
      break;
  }
}

void DCMotor::setSpeed(uint8_t speed) {
  analogWrite(_enPin, speed);
}