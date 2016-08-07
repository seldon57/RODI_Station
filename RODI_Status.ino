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

Initialize status and initialStatus to off

if(initialStatus != status)
  initialtime = now();

TankLevelStatus = TankStatusRead();
PressureSwitch = PressureSwitchRead();

if(TankLevelStatus == High || TankLevelStatus == HighHigh || PressureSwitch == true)
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

currenttime = now() - initialtime;

if(currenttime >= InitialFlushTime && status == RODISTATUS_INITIALFLUSH)
{
  status = RODISTATUS_RUNNING;
  RODISystemStatus(status);

  Serial.print("RODI Status: Running");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();
}

if(currenttime >= FlushTime && status == RODISTATUS_FLUSHING)
{
  status = RODISTATUS_RUNNING;
  RODISystemStatus(status);

  Serial.print("RODI Status: Running");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();
}

if(currenttime >= RunTime && status == RODISTATUS_RUNNING)
{
  status = RODISTATUS_FLUSHING;
  RODISystemStatus(status);

  Serial.print("RODI Status: Flushing");
  Serial.println();
  Serial.print(currenttime);
  Serial.println();
  Serial.println();
}
