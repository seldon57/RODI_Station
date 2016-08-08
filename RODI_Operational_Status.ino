
RODIStatus RODIOperationalStatus(RODIStatus status, TankStatus TankLevel, bool PressureSwitch, time InitialTime)
{

  time CurrentTime;

  if(TankLevel == TANKSTATUS_HIGH || TankLevel == TANKSTATUS_HIGHHIGH || PressureSwitch == true)
  {
    status = RODISTATUS_OFF;
    RODISystemStatus(status);

    Serial.print("RODI Status: Off");
    Serial.println();
    Serial.println();
  }

if(TankLevel == TANKSTATUS_LOWLOW && status == RODISTATUS_OFF)
{
  status = RODISTATUS_INITIALFLUSH;
  RODISystemStatus(status);

  Serial.print("RODI Status: InitialFlush");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();
}

CurrentTime = now() - InitialTime;

if(CurrentTime >= InitialFlushTime && status == RODISTATUS_INITIALFLUSH)
{
  status = RODISTATUS_RUNNING;
  RODISystemStatus(status);

  Serial.print("RODI Status: Running");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();
}

if(CurrentTime >= FlushTime && status == RODISTATUS_FLUSHING)
{
  status = RODISTATUS_RUNNING;
  RODISystemStatus(status);

  Serial.print("RODI Status: Running");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();
}

if(CurrentTime >= RunTime && status == RODISTATUS_RUNNING)
{
  status = RODISTATUS_FLUSHING;
  RODISystemStatus(status);

  Serial.print("RODI Status: Flushing");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();
}

  return status;
}
