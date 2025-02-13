
//1 Atrium tile = 23.75 cm

///motor for motion (forward and backward)
int forwardPin = 2; //on h-bridge

void setup() {
  // put your setup code here, to run once:
  pinMode(forwardPin, OUTPUT);
  pinMode(8, OUTPUT); //ENA pin
}


void loop() {
  // put your main code here, to run repeatedly:  

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(8, 255); //ENA pin

  //Forward
  digitalWrite(forwardPin, HIGH);
  

//End
}

