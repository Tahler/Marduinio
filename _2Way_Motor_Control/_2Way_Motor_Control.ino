//2-Way motor control
//LOW = off
//HIGH = on
// if analog, put at A0
int motorPin1 =  4;    // One motor wire connected to digital pin 5 changed to 4 because of convienience of shield
// if analog, put at A1
int motorPin2 =  5;    // One motor wire connected to digital pin 6 changed to 5 because of convienience of shield



// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pins as an output:
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT);  
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()                     
{
  rotateLeft(150, 500); // rotate left at speed, for a half second
  rotateRight(300, 1000); // rotate right at speed, for 1 second
  rotateLeftFull(1000); // spin left at full speed, for 1 second
  rotateRigtFull(500); // spin right at full speed, for half a second
}

void rotateLeft(int speedOfRotate, int length){
  analogWrite(motorPin1, speedOfRotate); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits before setting the motor to off
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRight(int speedOfRotate, int length){
  analogWrite(motorPin2, speedOfRotate); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits before setting the motor to off
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
}

void rotateLeftFull(int length){
  digitalWrite(motorPin1, HIGH); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits before setting the motor to off
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRightFull(int length){
  digitalWrite(motorPin2, HIGH); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits before setting the motor to off
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
}
