// Makes the car go forward for five seconds, turning left after three seconds, and right after four seconds

#include <AFMotor.h>

#define LEFT FORWARD
#define RIGHT BACKWARD

// 2 indicates M2 on the SHIELD
AF_DCMotor driveMotor(2, MOTOR12_64KHZ);
// 3 indicates M3 on the SHIELD
AF_DCMotor turnMotor(3, MOTOR12_1KHZ);

void setup() {
  Serial.begin(9600);

  driveMotor.setSpeed(255); // Max is 255
  turnMotor.setSpeed(255); // Max is 255
}

bool done = false;

void loop() {
//  if (!done) {
  driveMotor.setSpeed(255);
  // Straight for 1 second
  driveMotor.run(FORWARD);
  delay(1000);

  // Turn left for 1 second
  turnMotor.run(RIGHT); 
  delay(10);
  turnMotor.run(LEFT);
  delay(1000);

  // Turn right for 1 second
  turnMotor.run(LEFT);    
  delay(10);
  turnMotor.run(RIGHT);
  delay(1000);

  // Straight backward for 1 second at half speed
  turnMotor.run(RELEASE);
  driveMotor.run(RELEASE);
  driveMotor.setSpeed(127);
  driveMotor.run(BACKWARD);
  delay(1000);

  driveMotor.run(RELEASE);
  
//  done = true;
//  }
}
