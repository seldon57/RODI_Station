

const int trigPin;    //Pin on Arduino that will be used to trigger the HC-SR04
const int echoPin;    //Pin on Arduino that will be used to echo the HC-SR04
const int PressureSwitchPin;

float TankHeight = 850;	// Height of the tank in mm from the bottom to the sensor
float HCSR04Read(int x,int y);
float WaterLevelPercent (float a, float b);

bool PressureSwitchRead(int PressureSwitchPin);

void setup() 
{

  //Serial Port begin
  Serial.begin (9600);
  
  // Define the IO Pins
  trigPin = 4;
  echoPin = 5;
  PressureSwitchPin = 6;
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(PressureSwitchPin, INPUT);
  
}

void loop() 
{

  float distToWater;  //Distance in mm
  distToWater = HCSR04Read(trigPin,echoPin);
  
  Serial.print("mm: ");
  Serial.print(distToWater);
  Serial.println();
  Serial.println();
  
  delay(250);

}
