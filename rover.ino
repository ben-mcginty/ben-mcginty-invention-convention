// (c) Benjamin McGinty 2020

// +---------+---------+
// |  Robot  |         |
// +---------+---------+
// | Servo1A | Servo1B |
// | Servo2A | Servo2B |
// +---------+---------+

#include <Servo.h>
#include <SoftwareSerial.h> 

SoftwareSerial Device(2, 3); // RX | TX 
int flag = 0; 

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


// create variable for target location
int targetAngle = 15;

int powerLevel = 100;
//angles to turn on the spot (will require calibration)
int 1ASpotTurn = 10;
int 1BSpotTurn = 10;
int 2ASpotTurn = 10;
int 2BSpotTurn = 10;

void setup() 
{   
 Serial.begin(9600); 
 Device.begin(9600); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 

  // Attach the Servo variable to a pin:
  servo1A.attach(servoPin1A);
  servo1B.attach(servoPin1B);
  servo2A.attach(servoPin2A);
  servo2B.attach(servoPin2B);

  pinMode(2, OUTPUT); // forwards command
  pinMode(3, OUTPUT); // backwards commmand
} 

void loop() 
{ 
  if (Device.available()){
    message = Device.read();
    if (powerLevel >= 20){
    
      if (message == "Forwards")
      {
        digitalWrite(2, HIGH);
      }
      else if (message == "Backwards")
      {
        digitalWrite(3, HIGH);
      }
      else if (message == "Brake")
      {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
      }
      else if (message == "Turn on spot")
      {
        turnOnSpot();
      }
      else if (int(message) =< 360)
      {
        targetAngle = int(message);
        steeringAngle(targetAngle);
      }
    }
    else{
      Serial.println("Power too low, please charge");
    }
  }  
}  

// steer all sevos to targetAngle
void steeringAngle(int targetAngle){
  servo1A.write(targetAngle);
  servo1B.write(targetAngle);
  servo2A.write(targetAngle);
  servo2B.write(targetAngle);
  delay(1000);
}

void turnOnSpot(){
  servo1A.write(1ASpotTurn);
  servo1B.write(1BSpotTurn);
  servo2A.write(2ASpotTurn);
  servo2B.write(2BSpotTurn);
  delay(1000);
}