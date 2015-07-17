
#include<Servo.h>
Servo myservo;
int i = 0;
void setup() {
  Serial.begin(9600);
  myservo.attach(9, 0, 360);
}

void loop() {
  i++;
  if(i == 360){
    i = 0;
  }
  Serial.print("\n");
  Serial.print(i);
  myservo.write(i);
  delay(10);

}
