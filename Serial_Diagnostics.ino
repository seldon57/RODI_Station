void LCDOutput(TankStatus TankLevel, float percent, RODIStatus status, time_t CurrentTime)
{

  if(TankLevel == TANKSTATUS_LOWLOW)
  {
    lcd.setCursor(14,0);
    lcd.print("      ");
    lcd.setCursor(14,0);
    lcd.print("LowLow");
  }
  if(TankLevel == TANKSTATUS_LOW)
  {
    lcd.setCursor(14,0);
    lcd.print("      ");
    lcd.setCursor(17,0);
    lcd.print("Low");
  }
  if(TankLevel == TANKSTATUS_NORMAL)
  {
    lcd.setCursor(14,0);
    lcd.print("      ");
    lcd.setCursor(14,0);
    lcd.print("Normal");
  }
  if(TankLevel == TANKSTATUS_HIGH)
  {
    lcd.setCursor(14,0);
    lcd.print("      ");
    lcd.setCursor(16,0);
    lcd.print("High");
  }
  if(TankLevel == TANKSTATUS_HIGHHIGH)
  {
    lcd.setCursor(14,0);
    lcd.print("      ");
    lcd.setCursor(15,0);
    lcd.print("HHigh");
  }
  
  lcd.setCursor(14,1);
  lcd.print("      ");
  lcd.setCursor(14,1);
  lcd.print(percent);
  lcd.setCursor(19,1);
  lcd.print("%");

  if(status == RODISTATUS_OFF)
  {
    lcd.setCursor(15,2);
    lcd.print("     ");
    lcd.setCursor(17,2);
    lcd.print("OFF");
  }
  if(status == RODISTATUS_INITIALFLUSH)
  {
    lcd.setCursor(15,2);
    lcd.print("     ");
    lcd.setCursor(15,2);
    lcd.print("Flush");
  }
  if(status == RODISTATUS_FLUSHING)
  {
    lcd.setCursor(15,2);
    lcd.print("     ");
    lcd.setCursor(15,2);
    lcd.print("Flush");
  }
  if (status == RODISTATUS_RUNNING)
  {
    lcd.setCursor(15,2);
    lcd.print("     ");
    lcd.setCursor(17,2);
    lcd.print("Run");
  }
  
  lcd.setCursor(15,3);
  lcd.print("     ");
  lcd.setCursor(15,3);
  lcd.print(CurrentTime);
  lcd.setCursor(19,3);
  lcd.print("s");

}
