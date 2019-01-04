#include <SoftwareSerial.h>
#include <EEPROM.h>
#include "backsmile.h"

\\lol
void loop() {

  readAllSensors();

  if (millis() - previousMillis >= oneSecond) {   //1 second

    previousMillis = millis();

    calculateAverageValueOneSecond();

    digitalWrite(buzzer, LOW);
    digitalWrite(vibration, LOW);

    if (anythingActivated() == true) {

      sittingSeconds++;

      if (onlyLumbarActivated() == false && allFourZonesActivated() == false) {
        badPostureSeconds++;
      }

      digitalWrite(buzzer, LOW);
      digitalWrite(vibration, LOW);

      sittCurrentMillis = millis();

      checkMaxSitting();  //

      checkBadPosture();
    }
    else {

      breakSeconds++;
      if (breakSeconds == standUpTime) {
        resetEverything();

      }

      if (badPostureSeconds >= 1) {
        badPostureSeconds--;
      }
    }

    sendBluetooth();
    updateSetting();


    sumSensorMinute();

    secondCounter++;
    if( secondCounter == 59){   // one minute

        averageOneMinute();
        collectData();
 
      
      secondCounter = 0;
    }
    
  }
}
