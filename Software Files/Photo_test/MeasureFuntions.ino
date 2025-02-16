
// Global Vars for measuremnt system

// Radius of drive wheel in meters
const float wheelRadius = 0.015; 
// Number of breaks in measuremnt wheel
const float breakNum = 5.0; 
// gear ratio Mes wheel - drive wheels
const float mesGearRat = 5.0; 

float calcW(float difference)
{

  float W = (2.0*PI/breakNum)/difference; 

  return W; 

}

//float calcSpeed(float W)
//{
   
//float speed = wheelRadius*W*mesGearRat;

  // return speed; 

//}

float calcDist(float W, float difference)
{
  float speed = wheelRadius*W*mesGearRat;

  float dist = difference*speed; 

  return dist;

}



