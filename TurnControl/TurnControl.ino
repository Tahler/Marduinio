// Makes the car go forward for five seconds, turning left after three seconds, and right after four seconds

#include <AFMotor.h>

#define LEFT FORWARD
#define RIGHT BACKWARD

// 2 indicates M2 on the SHIELD
AF_DCMotor turnMotor(2, MOTOR12_1KHZ);

void setup() {
  Serial.begin(9600);

  turnMotor.setSpeed(255); // Max is 255
}

bool left = true;

void loop() {
  if (left) 
  {
    turnMotor.run(RIGHT);    
    delay(10);
    turnMotor.run(LEFT);
  }
  else 
  {
    turnMotor.run(LEFT);    
    delay(10);
    turnMotor.run(RIGHT);
  }
  delay(1000);

  turnMotor.run(RELEASE);
  delay(1000);
  left = !left;
}
