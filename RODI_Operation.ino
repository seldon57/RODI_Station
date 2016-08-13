void RODIOperation(RODIStatus status, int FeedSolenoidPin, int FlushSolenoidPin, int TankSolenoidPin, int BoosterPumpPin)
{
    switch (status)      
    {
      case RODISTATUS_OFF:
            digitalWrite(FeedSolenoidPin, HIGH);
            digitalWrite(FlushSolenoidPin, HIGH);
            digitalWrite(TankSolenoidPin, HIGH);
            digitalWrite(BoosterPumpPin, HIGH);
                        
            Serial.print("off");
            Serial.println();
            Serial.println();
            
            break;
        case RODISTATUS_INITIALFLUSH:
            digitalWrite(FeedSolenoidPin, LOW);
            digitalWrite(FlushSolenoidPin, LOW);
            digitalWrite(TankSolenoidPin, LOW);
            digitalWrite(BoosterPumpPin, LOW);
                        
            Serial.print("Iflush");
            Serial.println();
            Serial.println();
            
            break;
        case RODISTATUS_FLUSHING:
            digitalWrite(FeedSolenoidPin, LOW);
            digitalWrite(FlushSolenoidPin, LOW);
            digitalWrite(TankSolenoidPin, LOW);
            digitalWrite(BoosterPumpPin, LOW);
                        
            Serial.print("flush");
            Serial.println();
            Serial.println();
            
            break;
        case RODISTATUS_RUNNING:
            digitalWrite(FeedSolenoidPin, LOW);
            digitalWrite(FlushSolenoidPin, HIGH);
            digitalWrite(TankSolenoidPin, LOW);
            digitalWrite(BoosterPumpPin, LOW);
            
            Serial.print("Run");
            Serial.println();
            Serial.println();

            break;
        default:
            digitalWrite(FeedSolenoidPin, HIGH);
            digitalWrite(FlushSolenoidPin, HIGH);
            digitalWrite(TankSolenoidPin, HIGH);
            digitalWrite(BoosterPumpPin, HIGH);

            Serial.print("Invalid System Status");
            Serial.println();
            Serial.println();
            break;
    }
}
