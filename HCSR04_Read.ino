float HCSR04Read(int trigPin,int echoPin)
{
  
  float AvgDuration = 0;

  for (int i = 0; i < 5; ++i)
  {
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
 
    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
  
    AvgDuration = AvgDuration + pulseIn(echoPin, HIGH);
  }

  AvgDuration = AvgDuration / 5.00;
 
  // convert the time into a distance in mm
  return (AvgDuration/2.00) / 2.91;
    
}
