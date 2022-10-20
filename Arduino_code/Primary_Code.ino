
// defines pins numbers
const int trigPinL = 9; //Left sensor
const int echoPinL = 10;//Left sensor
const int trigPinR= 12;//Right sensor
const int echoPinR= 11;//Right sensor
const int transistorL = 2;
const int transistorR = 1;



// defines variables
long durationL;
int distanceL;
long durationR;//This will be displaying the distances for the right sensor (looking from the back)
int distanceR; //This will be displaying the distances for the right sensor (looking from the back)

//Setup code for arduino
void setup() {
  pinMode(trigPinL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinL, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPinR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinR, INPUT); // Sets the echoPin as an Input
  
  pinMode(13, OUTPUT); //This section defines the left motor transistor which is used for left motor
  pinMode (transistorL, OUTPUT);
  pinMode(8, OUTPUT); //This sets up the RIGHT wheel
  pinMode (transistor, OUTPUT);//Sets up our Right transistor
  
}
//The loop that gets executed
void loop() {
  
  // Left sensor?
  // Clears the trigPin
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationL = pulseIn(echoPinL, HIGH);
  // Calculating the distance
  distanceL = durationL * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance L: ");
  Serial.println(distanceL);

    // Left sensor?
  // Clears the trigPin
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationR = pulseIn(echoPinR, HIGH);
  // Calculating the distance
  distanceR = durationR * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance R: ");
  Serial.println(distanceR);

    // Left Wheel
  digitalWrite(13,1); // Turns on the left motor
  digitalWrite (transistorL, HIGH); //Turns on transistor left which is required for the left motor to move 
    // Right Wheel 
  digitalWrite(8,1); // Turns on the right motor
  digitalWrite (transistor, HIGH); //Turns on right transistor

  //If statement that checks if the sensors are less than a certain value (right sensor)
 if (distanceR < 10) {
 digitalWrite(8,0);
 delay(3000); //Will delay for 3 seconds
 digitalWrite(8,1); 
}
//If statement for left sensors
if (distanceL < 10) {
 digitalWrite(13,0);
 delay(3000); //Will delay for 3 seconds
 digitalWrite(13,1); 
}


}
