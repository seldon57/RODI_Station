float WaterLevelPercent (float TankHeight, float WaterDistance)
{
	
	float level = 0.0;
	level = TankHeight - WaterDistance;
	level = level / TankHeight * 100.0
	return level;
  
}