
//function pins
const int motor = 3; 
const int photo = A1;
const int button = 2;

//status LEDs for testing 
//const int slippingLED = 8;
//const int motorLED = 9;

// Global Vars for measuremnt system

// Radius of drive wheel in meters
const float wheelRadius = 0.015; 
// Number of breaks in measuremnt wheel
const int slitNum = 2; 
// gear ratio Mes wheel - drive wheels
const int mesGearRat = 5; 

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
float W[10]; 
int wIndex = 0; 

// fucntion needed stuff
float lastVal = 0;


void setup() 
{
  //function output pins
  pinMode(motor, OUTPUT); 
  //function input pins
  pinMode(photo, INPUT);    
  pinMode(button, INPUT); 

  //status output pins
  pinMode(slippingLED, OUTPUT); 
  pinMode(motorLED, OUTPUT); 


  //Serial.begin(1200); 
}

void loop() {
 
 if (digitalRead(button) == HIGH)
 {
  startCode = true;
 }

if (startCode == true) 
{
  analogWrite(motor, motorSpeed);

  W[wIndex] = calcW(measureDiff()); 

  if (hill == false)
  {
    distance += calcDist(W[wIndex], measureDiff());

    if (distance >= cutoffDist)
    {

      if (W[wIndex]*wheelRadius <= curveSpeed)
      {
        motorSpeed += 5;
      }
      else
      {
        motorSpeed -= 5;
      }
    }
  
    if (distance >= straightDist + PI * curveRadius )
    {
      hill = true; 
      motorSpeed = 255; 
    }

  }

  else
  {
    
  }


}



//very end of code
 wIndex++;

if (W[10] != 0)
{
  wIndex = 0;
  memset(W,0,10); 
}


}
