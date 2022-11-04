
// defines pins numbers
const int trigPinR = 1; //Left sensor
const int echoPinR = 2;//Left sensor
const int trigPinL= 4;//Right sensor
const int echoPinL= 8;//Right sensor


// defines variables
long durationL;
int distanceL;
long durationR;//This will be displaying the distances for the right sensor (looking from the back)
int distanceR; //This will be displaying the distances for the right sensor (looking from the back)

void setup() {
  pinMode(trigPinL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinL, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPinR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinR, INPUT); // Sets the echoPin as an Input
  

  
}
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


  
}
