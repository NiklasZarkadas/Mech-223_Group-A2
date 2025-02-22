
//function pins
const int motor = 3; 
const int photo = A0;

//status LEDs for testing 
//const int slippingLED = 8;
//const int motorLED = 9;

// Global Vars for measuremnt system

// Radius of drive wheel in meters
const float wheelRadius = 0.015; 
// Number of breaks in measuremnt wheel
const int slitNum = 6; 
// gear ratio Mes wheel - drive wheels
const int mesGearRat = 1; 

// Global Vars for track

// distance of straight track
const int straightDist = 8; 
// straight cutoff dist 
const int cutoffDist = 5; 
// raduis of track curve (m)
const float curveRadius = 5.0; 
// speed the curve should be taken at (m/s)
const float curveSpeed = 5.0; 


// gloabal varibles for cart control
bool startCode = false;
bool hill = false; //0 straight, 1 curved, 2 uphill
int motorSpeed = 255; 
float distance = 0; 

//Measuring and storing W 
float W; 
int wIndex = 0; 

// fucntion needed stuff
int lastVal = 0;

long startTime = 0; 
long endTime = 0;
int difference = 0; 


void setup() {
  pinMode(photo, INPUT);  //Tells the Arduino that digital pipin 2 is going to give it information.
  pinMode(motor, OUTPUT);   //Tells the Arduino that it is going to give commands to digital pin 9.

  Serial.begin(750);
}

void loop() {
  analogWrite(motor, 255); // Set motor speed

  int currentVal = analogRead(photo); // Read the sensor value
  //Serial.print("Sensor Value: ");
  

  if (currentVal > 20 && lastVal < 10) {
    if (startTime == 0) {
      startTime = millis();
    
    } else if (endTime == 0) {
      endTime = millis();
    } 
  }
  if (endTime != 0 && startTime != 0) {
      difference = endTime - startTime;
      
      Serial.print("difference ");
      Serial.println(difference);
      
      W = calcW(difference); // Calculate angular velocity
      Serial.print("Angular Velocity (m/s): ");
      Serial.println(W);

      endTime = 0;
      startTime = 0; 
    }
  Serial.println(currentVal);

  lastVal = currentVal; // Update last sensor value
}
