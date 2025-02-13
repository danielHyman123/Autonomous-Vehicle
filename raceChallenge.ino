
//1 Atrium tile = 23.75 cm

///motor for motion (forward and backward)
int motor1pin1 = 2; //on h-bridge
int motor1pin2 = 3; //on h-bridge

//Ultrasonic sensor pins
const int trigPin = 6;
const int echoPin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  //Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  pinMode(8, OUTPUT); //ENA pin
}


void loop() {
  // put your main code here, to run repeatedly:  
  int distance;
  long duration;
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(8, 255); //ENA pin

  //Set trig pin to off
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //Check for wall  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //Calculate distance
  distance = duration * 0.034/2;

  //Go backwards
  if (distance <= 47.5){  //2 blocks
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

  }
  else{
    //Controlling spin direction of motors:
    //Begin going forwards until detect wall 2 blocks away (for 7 blocks) 
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);  
    }
  delay(50);

//End
}











// Pin definitions for the ultrasonic sensor
const int trigPin = 6;  // Trigger pin
const int echoPin = 5;  // Echo pin


void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
 
  // Set the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  // Wait for a moment to ensure serial communication is set up
  delay(1000);
}


void loop() {
  // Variables to store duration and distance
  long duration;
  float distance;


  // Send a pulse to the trigger pin
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);           // Wait for the pin to be stable
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);          // Trigger pulse for 10 microseconds
  digitalWrite(trigPin, LOW);    


  // Read the duration of the echo pulse with no timeout (unlimited wait)
  duration = pulseIn(echoPin, HIGH);  // Remove the timeout to allow longer wait times


  // If no pulse is received, duration will be 0
  if (duration == 0) {
    Serial.println("No pulse received. Check the sensor.");
  } else {
    // Calculate the distance (in cm)
    distance = duration * 0.0344 / 2;  // Speed of sound: 0.0344 cm/μs, divide by 2 because it's a round-trip
 
    // Print the distance to the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);  // Print the distance in cm
    Serial.println(" cm");
    if(distance <= 48)
  }


  // Wait a little before taking another measurement
  delay(500);  // Wait for 500 ms before the next reading
}







