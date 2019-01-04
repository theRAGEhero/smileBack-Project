class Fsr {
  public:
    byte pin;
    int sensorValue;
    byte averageValueOneSecond = 0;
    int sensorValueOneMinute = 0;
    byte averageValueOneMinute = 0;
    Fsr(byte pin){
      this -> pin = pin;
    }
};
