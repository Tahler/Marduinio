/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

int sensorPin = A0;
int ledPin = 13;

int sensorValue = 0;

int oldAng = 0;
int newAng = 180;
int anaRead;

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin


void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() 
{ 
  anaRead = analogRead(sensorPin);
  sensorValue = map(anaRead, 100, 550, 0, 180);
  if(sensorValue > oldAng + 5 || sensorValue < oldAng - 5){
    oldAng = sensorValue;
  }
  
  Serial.print("read from Analog: ");
  Serial.print(anaRead);
  Serial.print("\nconverted from Analog: ");
  Serial.print(sensorValue);
  Serial.print("\n");
  
  myservo.write(oldAng);
  delay(50);
} 

