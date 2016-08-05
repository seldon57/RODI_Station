TankStatus TankLevelStatus(TankStatus level, float percent, float distance)
{
  
  //14.2875 mm equals 1 gallon

  // Tank level state change while filling
  if ((level == LowLow) && (percent > 28.575/850*100))    // at 2 gallons
    level = Low;
  if ((level == Low) && (percent > 85.725/850*100))       // at 6 gallons
    level = Normal;
  if ((level == Normal) && (percent > 642.9375/850*100))  //at 45 gallons
    level = High;
  if ((level == High) && (percent > 785.8125/850*100))    // at 55 gallons
    level = HighHigh;

  //Tank level state change while emptying
  if ((level == HighHigh) && (percent < 714.375/850*100)) // at 50 gallons
    level = High;
  if ((level == High) && (percent < 628.65/850*100))      // at 44 gallons
    level = Normal;
  if ((level == Normal) && (percent < 71.4375/850*100))   // at 5 gallons
    level = Low;
  if ((level == Low) && (percent < 14.2875/850*100))      // at 1 gallon
    level = LowLow;

  //Tank level state change if HC-SR04 is not acting properly or fails
  if (distance > 2000)      // HC-SR04 is directly up against what it is measuring
    level = HighHigh;
  if (distance == 0)        // HC-SR04 has failed or is disconnected
    level = HighHigh;
    
  return level;
}
