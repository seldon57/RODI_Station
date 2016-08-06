float WaterLevelPercent (float TankHeight, float distToWater)
{
	
	float level = 0.0;
	level = TankHeight - distToWater;
	level = level / TankHeight * 100.0
	return level;
  
}
