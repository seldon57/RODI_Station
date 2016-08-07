void RODISystemStatus(RODIStatus status)
{
    switch (status)      
        case RODISTATUS_OFF:
            digitalWrite(FeedSolenoidPin, HIGH);
            digitalWrite(FlushSolenoidPin, HIGH);
            digitalWrite(TankSolenoidPin, HIGH);
            digitalWrite(BoosterPumpPin, HIGH);
            break;
        case RODISTATUS_INITIALFLUSH:
            digitalWrite(FeedSolenoidPin, LOW);
            digitalWrite(FlushSolenoidPin, LOW);
            digitalWrite(TankSolenoidPin, LOW);
            digitalWrite(BoosterPumpPin, LOW);
            break;
        case RODISTATUS_FLUSHING:
            digitalWrite(FeedSolenoidPin, LOW);
            digitalWrite(FlushSolenoidPin, LOW);
            digitalWrite(TankSolenoidPin, LOW);
            digitalWrite(BoosterPumpPin, LOW);
            break;
        case RODISTATUS_RUNNING:
            digitalWrite(FeedSolenoidPin, LOW);
            digitalWrite(FlushSolenoidPin, HIGH);
            digitalWrite(TankSolenoidPin, LOW);
            digitalWrite(BoosterPumpPin, LOW);
            break;
        default:
            std::cout << "Unknown";
            break;
    }
}


TankLevel
status

if(TankLevel == TANKSTATUS_LOWLOW && status == RODISTATUS_OFF)
      status = InitialFlush;


int RODIOff(){			
  while(RODI == Off)
  {
    
    TankLevelStatus = TankStatusRead();
    if(TankLevelStatus == LowLow)
      RODI = InitialFlush;

    Serial.print("RODI Status: Off");
    Serial.println();
    Serial.println();

  }
  return RODI;
}

int RODIInitialFlush(){
  initialtime = now();
  currenttime = now() - initialtime;
  while(currenttime <= InitialFlushTime && RODI == InitialFlush)
  {
  
  TankLevelStatus = TankStatusRead();
  PressureSwitch = PressureSwitchRead();
  if(TankLevelStatus == High)
    RODI = Off; 
  if(TankLevelStatus == HighHigh)
    RODI = Off;
  if(PressureSwitch == true)
    RODI = Off;
  currenttime = now() - initialtime;

  Serial.print("RODI Status: InitialFlush");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();

  }
  if(currenttime >= InitialFlushTime)
    RODI = Running;
  return RODI;
}

int RODIFlushing(){
  initialtime = now();
  currenttime = now() - initialtime;
  while(currenttime <= FlushTime && RODI == Flushing)
  {
  
  TankLevelStatus = TankStatusRead();
  PressureSwitch = PressureSwitchRead();
  if(TankLevelStatus == High)
    RODI = Off; 
  if(TankLevelStatus == HighHigh)
    RODI = Off;
  if(PressureSwitch == true)
    RODI = Off;
  currenttime = now() - initialtime;

  Serial.print("RODI Status: Flushing");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();

  }
  if(currenttime >= FlushTime)
    RODI = Running;
  return RODI;
}

int RODIRunning(){
  initialtime = now();
  currenttime = now() - initialtime;
  while(currenttime <= RunTime && RODI == Running)
  {
  
  TankLevelStatus = TankStatusRead();
  PressureSwitch = PressureSwitchRead();
  if(TankLevelStatus == High)
    RODI = Off; 
  if(TankLevelStatus == HighHigh)
    RODI = Off;
  if(PressureSwitch == true)
    RODI = Off;
  currenttime = now() - initialtime;

  Serial.print("RODI Status: Running");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();

  }
  if(currenttime >= RunTime)
    RODI = Flushing;
  return RODI;
}
