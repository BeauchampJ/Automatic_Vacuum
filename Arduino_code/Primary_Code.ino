
// defines pins numbers
const int trigPinR = 1; //Left sensor
const int echoPinR = 2;//Left sensor
const int trigPinL= 4;//Right sensor
const int echoPinL= 3;//Right sensor

//Defines end wheel pins. A isn't included in our setup
#define A1 5  // Motor A pins
#define A2 6
#define B1 10 // Motor B pins
#define B2 11

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
  
   
  // Sets up the pins for our super cool wheels
 pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);

  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  
  
}
// This is used to set our input to 0, this will change inside of the loop
int  input = 0;
//The loop that gets executed
void loop() {
  // Starts forward movement
  forward();
  
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

// This section is for checking if the distances are a certain length and then having the car do things as a response
if (distanceR < 10) {
  RightPivot();

}
if (distanceL < 10) {
  LeftPivot();
}

delay(200);
  
}

// These are callable functions that get used within our loop code
void forward() {          //function of forward 
  analogWrite(A1, 255);
  analogWrite(A2, 0);
  analogWrite(B1, 255);
  analogWrite(B2, 0);
}

void backward() {         //function of backward
  analogWrite(A1, 0);
  analogWrite(A2, 210);
  analogWrite(B1, 0);
  analogWrite(B2, 210);
}

void Stop() {              //function of stop
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}

void LeftPivot() {
Stop();
delay(300);
backward();
delay(4000);
Stop();
delay(300);
analogWrite(B1, 0);
analogWrite(B2, 210);
analogWrite(A1, 255);
analogWrite(A2, 0);
delay(2000);
Stop();
}

void RightPivot() {
Stop();
delay(300);
backward();
delay(4000);
Stop();
delay(300);
analogWrite(A1, 0);
analogWrite(A2, 210);
analogWrite(B1, 255);
analogWrite(B2, 0);
delay(2000);
Stop();
}
