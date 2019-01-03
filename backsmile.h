#define vibration 8
#define buzzer 4
#define pinBluetooth 7
#define zeroPoint 0

//settings
byte maxSitting = 3;               //total sitting time allowed in minutes
byte maxWrongPosture = 1;          //total wrong posture allowed in minutes
byte standUpTime = 30;             // seconds

bool soundSetting = true;
bool vibrationSetting = true;
bool bluetoothSetting = false;


unsigned long previousMillis = 0;  //previous millis
unsigned long sittCurrentMillis = 0;
const int oneSecond = 1000;        //millis of one second

unsigned int sittingSeconds = 0;   //counter of the sitting seconds
int badPostureSeconds = 0;         //counter of the sitting seconds with bad posture
unsigned long breakSeconds = 0;

byte secondCounter = 0;
byte blockDataCounter = 0;
String g_drive="";

float coefficient = 1;

int counterOfAnalogRead = 0;       //counter of all the analog reads made in one second

//declaring Force Sensitive Resistor sensors

class Fsr * dorsal_DX;
class Fsr * dorsal_sx;
class Fsr * centUp_DX;
class Fsr * centUp_sx;
class Fsr * centDown_DX;
class Fsr * centDown_sx;
class Fsr * lumbar_DX;
class Fsr * lumbar_sx;


SoftwareSerial Bluetooth(10, 9); // RX, TX    Declaring bluetooth object


void readAllSensors();                    //it reads all the sensor at once
void calculateAverageValueOneSecond();    //

bool allFourZonesActivated();
bool onlyLumbarActivated();
bool anythingActivated();

void resetEverything();
void feedback();
void serialDiagnostic();
void checkBadPosture();
void checkMaxSitting();
void sendBluetooth();
void updateSetting();
void averageOneMinute();
void sumSensorMinute();
void collectData();
