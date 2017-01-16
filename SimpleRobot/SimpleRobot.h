/*******************************************************
  SimpleRobot.h
  low level motor driver interface
	
  For use with the custom L298Nbridge library
********************************************************/

// defines for left and right motors
const int MOTOR_LEFT  = 0;
const int MOTOR_RIGHT = 1;

extern const int MIN_SPEED;
extern int speedTable[];
extern int rotationTime[];
extern const int SPEED_TABLE_INTERVAL;
extern const int NBR_SPEEDS;

void robotBegin(); 

// speed range is 0 to 100 percent
void robotSetSpeed(int speed);

void robotForward(int speed);

void robotReverse(int speed);

void robotTurnRight(int speed);

void robotTurnLeft(int speed);

void robotStop();

void robotBrake();