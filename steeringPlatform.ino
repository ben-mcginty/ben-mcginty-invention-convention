// (c) Benjamin McGinty 2020

// +---------+---------+
// |  Robot  |         |
// +---------+---------+
// | Servo1A | Servo1B |
// | Servo2A | Servo2B |
// +---------+---------+

// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo servo1A;
Servo servo1B;
Servo servo2A;
Servo servo2B;

// Define the servo pin:
#define servoPin1A 9
#define servoPin1B 10
#define servoPin2A 11
#define servoPin2B 12

// Create a variable to store the servo position:
int angle = 0;

// create variable for target location
int targetAngle = 15;

void setup() {
  // Attach the Servo variable to a pin:
  servo1A.attach(servoPin1A);
  servo1B.attach(servoPin1B);
  servo2A.attach(servoPin2A);
  servo2B.attach(servoPin2B);
}
void loop() {
  // call steeringAngle function
  steeringAngle(targetAngle, angle);
}

// steer all sevos to targetAngle
void steeringAngle(int targetAngle, int angle){
  servo1A.write(targetAngle);
  servo1B.write(targetAngle);
  servo2A.write(targetAngle);
  servo2B.write(targetAngle);
  delay(1000);
}
