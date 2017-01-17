/*
James' L298 Motor controller library

*/

#include "Arduino.h"
#include "L298Nbridge.h"


DCMotor::DCMotor(uint8_t num) {
  motorNum = num;
  
  inPin1 = inPin1s[motorNum - 1];
  inPin2 = inPin2s[motorNum - 1];
  enPin = enPins[motorNum - 1];

}

void DCMotor::begin() {
  pinMode(inPin1, OUTPUT);
  pinMode(inPin2, OUTPUT);
  pinMode(enPin, OUTPUT);
}

void DCMotor::run(uint8_t cmd) {
  uint8_t a, b;
  
  switch(cmd) {
    case FORWARD:
      digitalWrite(inPin1, HIGH);
      digitalWrite(inPin2, LOW);
      break;
    case BACKWARD:
      digitalWrite(inPin1, LOW);
      digitalWrite(inPin2, HIGH);
      break;
    case BRAKE:
      digitalWrite(inPin1, LOW);
      digitalWrite(inPin2, LOW);
      break;
    case RELEASE:
      digitalWrite(enPin, LOW);
      break;
  }
}

void DCMotor::setSpeed(uint8_t speed) {
  switch (motorNum) {
    case 1:
      analogWrite(enPin, speed);
      break;
    case 2:
      analogWrite(enPin, speed);
      break;
  }
}