/*
* created by seldon on RC
* 
* Automated RODI Filling Station
*
* 55 Gallon Drum Level Monitoring Using Ultrasonic Sensor HC-SR04
*
*/

#include <Time.h>
#include <TimeLib.h>

int trigPin;    //Pin on Arduino that will be used to trigger the HC-SR04
int echoPin;    //Pin on Arduino that will be used to echo the HC-SR04
int PressureSwitchPin;

int FeedSolenoidPin;
int FlushSolenoidPin;
int TankSolenoidPin;
int BoosterPumpPin;

int RODIInitialFlushTime = 120;
int RODIFlushTime = 30;
int RODIRunTime = 3600;

float TankHeight = 850.0;  // Height of the tank in mm from the bottom to the sensor

time_t InitialTime;

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

RODIStatus initialStatus;
RODIStatus status;

TankStatus TankLevelStatus(TankStatus level, float percent, float distToWater);

float HCSR04Read(int trigPin, int echoPin);

float WaterLevelPercent (float TankHeight, float distToWater);

bool PressureSwitchRead(int PressureSwitchPin);

void SerialDiagnostics(float value1);

RODIStatus RODIOperationalStatus(RODIStatus status, TankStatus TankLevel, bool PressureSwitch, time_t InitialTime);

void RODIOperation(RODIStatus status);




void setup() 
{

  //Serial Port begin
  Serial.begin (9600);
  
  // Define the IO Pins
  trigPin = 4;
  echoPin = 5;
  PressureSwitchPin = 6;
  FeedSolenoidPin = 7;
  FlushSolenoidPin = 8;
  TankSolenoidPin = 9;
  BoosterPumpPin = 10;
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(PressureSwitchPin, INPUT);

  initialStatus = RODISTATUS_OFF;
  status = RODISTATUS_OFF;

  InitialTime = now();
  
}

void loop() 
{

  bool PressureSwitch;
  PressureSwitch = PressureSwitchRead(PressureSwitchPin);

  float distToWater;  //Distance in mm
  distToWater = HCSR04Read(trigPin,echoPin);
  
  float percent;
  percent = WaterLevelPercent (TankHeight, distToWater);
  
  TankStatus TankLevel;
  TankLevel = TankLevelStatus(TankLevel, percent, distToWater);

  if(initialStatus != status)
  {
    InitialTime = now();
    initialStatus = status;
  } 

  status = RODIOperationalStatus(status, TankLevel, PressureSwitch, InitialTime);



  //SerialDiagnostics(distToWater);


  
  //Serial.print("mm: ");
  //Serial.print(distToWater);
  //Serial.println();
  //Serial.println();
  //delay(250);

}
