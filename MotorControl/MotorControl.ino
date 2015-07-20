// Makes the car go forward for five seconds, turning left after three seconds, and right after four seconds

#include <AFMotor.h>

#define LEFT FORWARD
#define RIGHT BACKWARD

// 2 indicates M2 on the SHIELD
AF_DCMotor driveMotor(2, MOTOR12_64KHZ);
// 3 indicates M3 on the SHIELD
AF_DCMotor turnMotor(3, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);

  turnMotor.setSpeed(255); // Max is 255
  driveMotor.setSpeed(255);
}

bool done = true;

void loop() {
  if (done) {
    driveMotor.run(FORWARD);
    delay(3000);
  
    turnMotor.run(LEFT);
    delay(1000);

    turnMotor.run(RIGHT);
    delay(1000);

    turnMotor.run(RELEASE);
    driveMotor.run(RELEASE);
    done = false;
  }
}
