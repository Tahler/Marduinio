// Moves the car forward until it is about to hit something, then backs up for one second, and turns right.

#include <AFMotor.h>

#define LEFT FORWARD
#define RIGHT BACKWARD

// 2 indicates M2 on the SHIELD
AF_DCMotor driveMotor(2, MOTOR12_64KHZ);
// 3 indicates M3 on the SHIELD
AF_DCMotor turnMotor(3, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);

  // 13 is the LED's pin
  pinMode(13, OUTPUT);
  
  // Max speed is 255
  driveMotor.setSpeed(220);
  turnMotor.setSpeed(255);

  driveMotor.run(RELEASE);
  turnMotor.run(RELEASE);
}

int analogValue;

void loop() {
  // A0 is the analog input that the sensor is connected to
  analogValue = analogRead(A0);
  
  Serial.print(analogValue);
  Serial.print("\n");
  
  if (analogValue < 5) 
  {
    driveMotor.run(FORWARD);
  }
  else 
  {
    // Coast for half a second
    driveMotor.run(RELEASE);
//    delay(500);
//    
//    // Go reverse, moving the car's backend to the left.
//    turnMotor.run(LEFT);
//    driveMotor.run(BACKWARD);
//    delay(1000);
//
//    turnMotor.run(RELEASE);
//    driveMotor.run(RELEASE);
  }

  delay(100);
}
