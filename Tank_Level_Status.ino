TankStatus TankLevelStatus(TankStatus level, float percent, float distance)
{
  
  //14.2875 mm equals 1 gallon

  // Tank level state change while filling
  if ((level == TANKSTATUS_LOWLOW) && (percent > 28.575/870*100))    // at 2 gallons
    level = TANKSTATUS_LOW;
  if ((level == TANKSTATUS_LOW) && (percent > 85.725/870*100))       // at 6 gallons
    level = TANKSTATUS_NORMAL;
  if ((level == TANKSTATUS_NORMAL) && (percent > 642.9375/870*100))  //at 45 gallons
    level = TANKSTATUS_HIGH;
  if ((level == TANKSTATUS_HIGH) && (percent > 785.8125/870*100))    // at 55 gallons
    level = TANKSTATUS_HIGHHIGH;

  //Tank level state change while emptying
  if ((level == TANKSTATUS_HIGHHIGH) && (percent < 714.375/870*100)) // at 50 gallons
    level = TANKSTATUS_HIGH;
  if ((level == TANKSTATUS_HIGH) && (percent < 628.65/870*100))      // at 44 gallons
    level = TANKSTATUS_NORMAL;
  if ((level == TANKSTATUS_NORMAL) && (percent < 71.4375/870*100))   // at 5 gallons
    level = TANKSTATUS_LOW;
  if ((level == TANKSTATUS_LOW) && (percent < 14.2875/870*100))      // at 1 gallon
    level = TANKSTATUS_LOWLOW;

  //Tank level state change if HC-SR04 is not acting properly or fails
  if (distance > 2000)      // HC-SR04 is directly up against what it is measuring
    level = TANKSTATUS_HIGHHIGH;
  if (distance == 0)        // HC-SR04 has failed or is disconnected
    level = TANKSTATUS_HIGHHIGH;
    
  return level;
}
