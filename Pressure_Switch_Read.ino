bool PressureSwitchRead(int PressureSwitchPin)
{
  
  if(digitalRead(PressureSwitchPin) == LOW)
  { 
    delay(1000); // delay to debounce switch 
    return true; 
  } 
  
  else
  { 
    return false; 
  } 
  
}