/*
 * This is an example sketch to test a 2WD custom L298 Motor Library with the Uno
 * 
 * This does not work with he more complicated motor shields, this is for an Uno connectd directly to an L298 chip or module.
 * 
 * Connect as follows:
 * 
 * Motor 1 enable - pin 9
 * Motor 1 IN0 - pin 2
 * Motor 1 IN1 - pin 3
 * 
 * Motor 2 enable - pin 10
 * Motor 2 IN0 - pin 4
 * Motor 2 IN1 - pin 5
*/
#include <L298Nbridge.h>

#include <SimpleRobot.h>

#define LED_PIN 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //blinkNumber(8); // open port while flashing. Needed for Leonardo only  
  robotBegin(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("forwards");
  robotForward(100);
  delay(2000);
  Serial.println("backwards");
  robotReverse(100);
  delay(2000);
//  robotRight(100);
//  delay(500);
//  robotLeft(500);
//  delay(500);
  Serial.println("stop");
  robotStop();
  delay(2000);
}

void blinkNumber( byte number) {
   pinMode(LED_PIN, OUTPUT); // enable the LED pin for output
   while(number--) {
     digitalWrite(LED_PIN, HIGH); delay(100);
     digitalWrite(LED_PIN, LOW);  delay(400);
   }
}


