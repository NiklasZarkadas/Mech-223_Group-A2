int measureDiff(int lasVal, int startTime, int endTime)
{ 
  int difference;

  if (analogRead(photo) > 0 && lastVal == 0)
  {
    if (startTime == 0)
    {
      startTime = millis();
    }

    else if (endTime == 0)
    {
      endTime = millis();
    }

    else
    {
      difference = endTime - startTime;

      endTime = 0;
      startTime = 0;

    }

  return difference; 

  }
}

float calcW (int difference)
{
  float W = mesGearRat*(2.0*PI/slitNum)/(difference/1000.0); 

  return W; 
}


float calcDist(float W, int difference)
{
  float speed = wheelRadius*W;

  float dist = (1.0*difference)*speed; 

  return dist;

}





 
