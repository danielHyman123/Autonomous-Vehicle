#include <Servo.h>
Servo Serv;


// defines pins numbers
const int trigPin = 6;
const int echoPin = 5;
const int forwardPin = 2;
const int servoPin = 11;


// defines variables
long duration;
int distance;


void setup() {
  // Sets the trigPin as an Output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication 
  pinMode(forwardPin, OUTPUT);
  pinMode(8, OUTPUT); 
  pinMode(servoPin, OUTPUT);
  Serv.attach(servoPin, 600, 1000);

}
void loop() {
//Sets the speed
	analogWrite(8, 150);

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
 
  if (distance <=71.25){  //3 Atrium blocks to make it into the launch zone. (we can change this distance wif we like)
    digitalWrite(forwardPin, LOW);
    Serv.write(150);


   
  }
  else{
      digitalWrite(forwardPin, HIGH);
      Serv.write(0);


  }
}