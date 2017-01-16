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
  motornum = num;
  
  switch(num) {
    case 1:
      pinMode(MOTOR1_EN, OUTPUT);
      pinMode(MOTOR1_A, OUTPUT);
      pinMode(MOTOR1_B, OUTPUT);
      break;
    case 2:
      pinMode(MOTOR2_EN, OUTPUT);
      pinMode(MOTOR2_A, OUTPUT);
      pinMode(MOTOR2_B, OUTPUT);  
      break;
  }
}

void DCMotor::run(uint8_t cmd) {
  uint8_t a, b;
  
  switch (motornum) {
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
  switch (motornum) {
    case 1:
      analogWrite(MOTOR1_EN, speed);
      break;
    case 2:
      analogWrite(MOTOR2_EN, speed);
      break;
  }
}