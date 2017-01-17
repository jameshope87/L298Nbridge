/*
 * This is an example sketch to test a DC motor using the custom L298 Motor Library with the Uno
 * 
 * This does not work with he more complicated motor shields, this is for an Uno connectd directly to an L298 chip or module.
 * 
 */
#include <L298Nbridge.h>


//initialise a motor object (1 or 2)
DCMotor rMotor(1, 2, 3, 9);
DCMotor lMotor(2, 4, 5, 10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Motor test!");
  rMotor.begin();
  //turn on motor using pwm speed 0 - 255
  rMotor.setSpeed(200);
  lMotor.setSpeed(200);
  lMotor.begin();
  rMotor.run(RELEASE);
  lMotor.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t i;

  Serial.println("forward");

  rMotor.run(FORWARD);
  lMotor.run(FORWARD);
  for (i=0; i<255; i++) {
    rMotor.setSpeed(i);
    lMotor.setSpeed(i);
    delay(10);
  }

  for (i=255; i!=0; i--) {
    rMotor.setSpeed(i);
    lMotor.setSpeed(i);
    delay(10);
  }

  Serial.println("backwards");
  rMotor.run(BACKWARD);
  lMotor.run(BACKWARD);
  for (i=0; i<255; i++) {
    rMotor.setSpeed(i);
    lMotor.setSpeed(i);
    delay(10);
  }

  for (i=255; i!=0; i--) {
    rMotor.setSpeed(i);
    lMotor.setSpeed(i);
    delay(10);
  }
  Serial.println("aaaaaaannnd stop.");
  rMotor.run(RELEASE);
  lMotor.run(RELEASE);
  delay(1000);
}
