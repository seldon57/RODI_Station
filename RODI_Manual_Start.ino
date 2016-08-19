bool RODIManualStartSwitchRead(RODIManualStartPin)
{
  if(digitalRead(RODIManualStartPin) == LOW) //LOW for a normally open switch
  { 
    delay(1000); // delay to debounce switch 
    return true; 
  } 
  
  else
  { 
    return false; 
  } 
}
