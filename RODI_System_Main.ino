/*
* created by seldon on RC
* 
* Automated RODI Filling Station
*
* 55 Gallon Drum Level Monitoring Using Ultrasonic Sensor HC-SR04
*
*/

int trigPin;    //Pin on Arduino that will be used to trigger the HC-SR04
int echoPin;    //Pin on Arduino that will be used to echo the HC-SR04
int PressureSwitchPin;
int RODIInitialFlushTime = 120;
int RODIFlushTime = 30;
int RODIRunTime = 3600;

time InitialTime;

TankStatus TankLevelStatus(TankStatus level, float percent, float distToWater);

float TankHeight = 850.0;	// Height of the tank in mm from the bottom to the sensor
float HCSR04Read(int trigPin, int echoPin);
float WaterLevelPercent (float TankHeight, float distToWater);

bool PressureSwitchRead(int PressureSwitchPin);

void SerialDiagnostics(float value1);

RODIStatus RODIOperationalStatus(RODIStatus status, TankStatus TankLevel, bool PressureSwitch, time InitialTime);


enum TankStatus
{
    TANKSTATUS_LOWLOW,
    TANKSTATUS_LOW,
    TANKSTATUS_NORMAL,
    TANKSTATUS_HIGH,
    TANKSTATUS_HIGHHIGH
};

enum RODIStatus
{
    RODISTATUS_OFF,
    RODISTATUS_INITIALFLUSH,
    RODISTATUS_FLUSHING,
    RODISTATUS_RUNNING
};

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
  
  float percent;
  percent = WaterLevelPercent (TankHeight, distToWater);
  
  TankLevel = TankLevelStatus(TankLevel, Percent, distToWater);

  PressureSwitch = PressureSwitchRead(PressureSwitchPin);

  initialStatus = RODISTATUS_OFF;
  status = RODISTATUS_OFF;

  if(initialStatus != status)
    InitialTime = now();

  status = RODIOperationalStatus(status, TankLevel, PressureSwitch, InitialTime);



  //SerialDiagnostics(distToWater);


  
  //Serial.print("mm: ");
  //Serial.print(distToWater);
  //Serial.println();
  //Serial.println();
  //delay(250);

}
