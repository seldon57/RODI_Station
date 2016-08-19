bool PressureSwitchRead(int PressureSwitchPin)
{
  if(digitalRead(PressureSwitchPin) == HIGH) //HIGH for a normally closed switch
  { 
    delay(1000); // delay to debounce switch 
    return true; 
  } 
  
  else
  { 
    return false; 
  } 
}
