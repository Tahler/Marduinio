// Makes the car go forward for 1 second, pause for 1 second, backward for 1 second, pause for 1 second, repeat.

#include <AFMotor.h>

// 2 indicates M2 on the SHIELD
AF_DCMotor driveMotor(2, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);

  driveMotor.setSpeed(255); // Max is 255
}

void loop() {
  driveMotor.run(FORWARD);
  delay(1000);

  driveMotor.run(RELEASE);
  delay(1000);
  
  driveMotor.run(BACKWARD);
  delay(1000);

  driveMotor.run(RELEASE);
  delay(1000);
}
