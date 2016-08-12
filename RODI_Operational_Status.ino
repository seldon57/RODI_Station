
RODIStatus RODIOperationalStatus(RODIStatus status, TankStatus TankLevel, bool PressureSwitch, time_t InitialTime)
{

  time_t CurrentTime;
  CurrentTime = now() - InitialTime;

  if(TankLevel == TANKSTATUS_HIGH || TankLevel == TANKSTATUS_HIGHHIGH || PressureSwitch == false)
  {
    status = RODISTATUS_OFF;
    RODIOperation(status);

    Serial.print("RODI Status: Off");
    Serial.println();
    Serial.print("Current Time: "); 
    Serial.print(CurrentTime);
    Serial.println();
    Serial.println();

    return status;
  }

  if(TankLevel == TANKSTATUS_LOWLOW && status == RODISTATUS_OFF)
  {
    status = RODISTATUS_INITIALFLUSH;
    RODIOperation(status);

    Serial.print("RODI Status: InitialFlush");
    Serial.println();
    Serial.print("Current Time: ");
    Serial.print(CurrentTime);
    Serial.println();
    Serial.println();

    return status;
  }

  if(CurrentTime >= RODIInitialFlushTime && status == RODISTATUS_INITIALFLUSH)
  {
    status = RODISTATUS_RUNNING;
    RODIOperation(status);

    Serial.print("RODI Status: Running");
    Serial.println();
    Serial.print("Current Time: ");
    Serial.print(CurrentTime);
    Serial.println();
    Serial.println();

    return status;
  }

  if(CurrentTime >= RODIFlushTime && status == RODISTATUS_FLUSHING)
  {
    status = RODISTATUS_RUNNING;
    RODIOperation(status);

    Serial.print("RODI Status: Running");
    Serial.println();
    Serial.print("Current Time: ");
    Serial.print(CurrentTime);
    Serial.println();
    Serial.println();

    return status;
  }

  if(CurrentTime >= RODIRunTime && status == RODISTATUS_RUNNING)
  {
    status = RODISTATUS_FLUSHING;
    RODIOperation(status);

    Serial.print("RODI Status: Flushing");
    Serial.println();
    Serial.print("Current Time: ");
    Serial.print(CurrentTime);
    Serial.println();
    Serial.println();

    return status;
  }

  Serial.print("Current Time: ");
  Serial.print(CurrentTime);
  Serial.println();
  Serial.println();  

  break;
  
}
