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

//int RODIInitialFlushTime = 120;
//int RODIFlushTime = 30;
//int RODIRunTime = 3600;

int RODIInitialFlushTime = 10;
int RODIFlushTime = 5;
int RODIRunTime = 15;

float TankHeight = 850.0;  // Height of the tank in mm from the bottom to the sensor

time_t InitialTime;

enum TankStatus
{
    TANKSTATUS_LOWLOW,  //0
    TANKSTATUS_LOW,     //1
    TANKSTATUS_NORMAL,  //2
    TANKSTATUS_HIGH,    //3
    TANKSTATUS_HIGHHIGH //4
};

enum RODIStatus
{
    RODISTATUS_OFF,           //0
    RODISTATUS_INITIALFLUSH,  //1
    RODISTATUS_FLUSHING,      //2
    RODISTATUS_RUNNING        //3
};

RODIStatus initialStatus;
RODIStatus status;

TankStatus TankLevelStatus(TankStatus level, float percent, float distToWater);

float HCSR04Read(int trigPin, int echoPin);

float WaterLevelPercent (float TankHeight, float distToWater);

bool PressureSwitchRead(int PressureSwitchPin);

void SerialDiagnostics(float value1);

RODIStatus RODIOperationalStatus(RODIStatus status, TankStatus TankLevel, bool PressureSwitch, time_t InitialTime, time_t CurrentTime);

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
  
  pinMode(FeedSolenoidPin, OUTPUT);
  pinMode(FlushSolenoidPin, OUTPUT);
  pinMode(TankSolenoidPin, OUTPUT);
  pinMode(BoosterPumpPin, OUTPUT);

  initialStatus = RODISTATUS_OFF;
  status = RODISTATUS_OFF;

  InitialTime = now();
  
}

void loop() 
{

  bool PressureSwitch;
  PressureSwitch = PressureSwitchRead(PressureSwitchPin);

  Serial.print("Pressure Switch: ");
  Serial.print(PressureSwitch);
  Serial.println();
  Serial.println();

  float distToWater;  //Distance in mm
  distToWater = HCSR04Read(trigPin,echoPin);

  Serial.print("Distance to water (mm): ");
  Serial.print(distToWater);
  Serial.println();
  Serial.println();
  
  float percent;
  percent = WaterLevelPercent (TankHeight, distToWater);

  Serial.print("Percent Full: ");
  Serial.print(percent);
  Serial.println();
  Serial.println();
  
  TankStatus TankLevel;
  TankLevel = TankLevelStatus(TankLevel, percent, distToWater);

  Serial.print("Tank Level Status: ");
  Serial.print(TankLevel);
  Serial.println();
  Serial.println();

  if(initialStatus != status)
  {
    InitialTime = now();
    initialStatus = status;
    Serial.print("Initial Time Reset");
    Serial.println();
    Serial.println();
  } 

  time_t CurrentTime;
  CurrentTime = now() - InitialTime;

  status = RODIOperationalStatus(status, TankLevel, PressureSwitch, InitialTime, CurrentTime);

  //SerialDiagnostics(distToWater);
  
  //Serial.print("mm: ");
  //Serial.print(distToWater);
  //Serial.println();
  //Serial.println();

  delay(1000);

}
