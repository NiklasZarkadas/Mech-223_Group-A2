
//function pins
const int motor = 6; 
const int photo = A4;
const int button = 13;

//status LEDs for testing 
const int curveLED = 8;
const int motorLED = 12;

// Global Vars for measuremnt system

// Radius of drive wheel in meters
const float wheelRadius = 0.013; 
// Number of breaks in measuremnt wheel
const int slitNum = 2; 
// gear ratio Mes wheel - drive wheels
const int mesGearRat = 1; 

// Global Vars for track

// distance of straight track
const int straightDist = 1; 
// straight cutoff dist 
const int cutoffDist = 1; 
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
int startTime = 0;
int endTime = 0;
int difference;

// fucntion needed stuff
int lastVal = 0;


void setup() 
{
  //function output pins
  pinMode(motor, OUTPUT); 
  //function input pins
  pinMode(photo, INPUT);    
  pinMode(button, INPUT); 

  //status output pins
  pinMode(curveLED, OUTPUT); 
  pinMode(motorLED, OUTPUT); 


  Serial.begin(1200); 
}

void loop() {
 
 if (digitalRead(button) == HIGH)
 {
  startCode = true;
  Serial.println("Button Pushed");
 }

if (startCode == true) 
{
  analogWrite(motor, motorSpeed);

  int currentVal = analogRead(photo); // Read the sensor value
   Serial.println(currentVal);

  if (currentVal > 5 && lastVal < 5) {
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
      
      W = mesGearRat*(2.0*PI/slitNum)/(difference/1000.0); // Calculate angular velocity

      Serial.print("Angular Velocity");
      Serial.println(W);

      startTime = endTime; 
      endTime = 0;
     
     distance += (1.0*difference/1000.0)*wheelRadius*W;;
    }

  lastVal = currentVal; // Update last sensor value


  if (hill == false)
  {
    

    if (distance >= cutoffDist)
    {
      digitalWrite(motorLED, HIGH);

      if (W*wheelRadius <= curveSpeed && motorSpeed < 255)
      {
        motorSpeed += 1;
        delay(10);
      }
      else if (motorSpeed > 0)
      {
        motorSpeed -= 1;
         delay(10);
      }
    }

    Serial.print("motor Speed ");
    Serial.println(motorSpeed);

  
    if (distance >= straightDist + PI * curveRadius )
    {
      hill = true; 
      motorSpeed = 255; 
    }

  }
    Serial.println(distance);




}
}
