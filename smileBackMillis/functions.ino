void readAllSensors() {
  /*
    dorsal_DX -> sensorValue += analogRead (dorsal_DX -> pin);
    dorsal_sx -> sensorValue += analogRead (dorsal_sx -> pin);
    centUp_DX -> sensorValue += analogRead (centUp_DX -> pin);
    centUp_sx -> sensorValue += analogRead (centUp_sx -> pin);
    centDown_DX -> sensorValue += analogRead (centDown_DX -> pin);
    centDown_sx -> sensorValue += analogRead (centDown_sx -> pin);
    lumbar_DX -> sensorValue += analogRead (lumbar_DX -> pin);
    lumbar_sx -> sensorValue += analogRead (lumbar_sx -> pin);*/


  dorsal_DX -> sensorValue += map(analogRead (dorsal_DX -> pin), 0, 685, 0, 9 );
  dorsal_sx -> sensorValue += map(analogRead (dorsal_sx -> pin), 0, 685, 0, 9 );
  centUp_DX -> sensorValue += map(analogRead (centUp_DX -> pin), 0, 685, 0, 9 );
  centUp_sx -> sensorValue += map(analogRead (centUp_sx -> pin), 0, 685, 0, 9 );
  centDown_DX -> sensorValue += map(analogRead (centDown_DX -> pin), 0, 685, 0, 9 );
  centDown_sx -> sensorValue += map(analogRead (centDown_sx -> pin), 0, 685, 0, 9 );
  lumbar_DX -> sensorValue += map(analogRead (lumbar_DX -> pin), 0, 685, 0, 9 );
  lumbar_sx -> sensorValue += map(analogRead (lumbar_sx -> pin), 0, 685, 0, 9 );

  counterOfAnalogRead++;
}

void calculateAverageValueOneSecond() {


  dorsal_DX -> averageValueOneSecond = dorsal_DX -> sensorValue / counterOfAnalogRead ;
  dorsal_sx -> averageValueOneSecond = dorsal_sx -> sensorValue / counterOfAnalogRead ;
  centUp_DX -> averageValueOneSecond = centUp_DX -> sensorValue / counterOfAnalogRead ;
  centUp_sx -> averageValueOneSecond = centUp_sx -> sensorValue / counterOfAnalogRead ;
  centDown_DX -> averageValueOneSecond = centDown_DX -> sensorValue / counterOfAnalogRead ;
  centDown_sx -> averageValueOneSecond = centDown_sx -> sensorValue / counterOfAnalogRead ;
  lumbar_DX -> averageValueOneSecond = lumbar_DX -> sensorValue / counterOfAnalogRead ;
  lumbar_sx -> averageValueOneSecond = lumbar_sx -> sensorValue / counterOfAnalogRead ;


  /*
    dorsal_DX -> averageValueOneSecond = map(dorsal_DX -> averageValueOneSecond, 0, 700, 0, 9 );
    dorsal_sx -> averageValueOneSecond = map(dorsal_sx -> averageValueOneSecond, 0, 700, 0, 9 );
    centUp_DX -> averageValueOneSecond = map(centUp_DX -> averageValueOneSecond, 0, 700, 0, 9 );
    centUp_sx -> averageValueOneSecond = map(centUp_sx -> averageValueOneSecond, 0, 700, 0, 9 );
    centDown_DX -> averageValueOneSecond = map(centDown_DX -> averageValueOneSecond, 0, 700, 0, 9 );
    centDown_sx -> averageValueOneSecond = map(centDown_sx -> averageValueOneSecond, 0, 700, 0, 9 );
    lumbar_DX -> averageValueOneSecond = map(lumbar_DX -> averageValueOneSecond, 0, 700, 0, 9 );
    lumbar_sx -> averageValueOneSecond = map(lumbar_sx -> averageValueOneSecond, 0, 700, 0, 9 );*/

  serialDiagnostic();

  dorsal_DX -> sensorValue = 0;
  dorsal_sx -> sensorValue = 0;
  centUp_DX -> sensorValue = 0;
  centUp_sx -> sensorValue = 0;
  centDown_DX -> sensorValue = 0;
  centDown_sx -> sensorValue = 0;
  lumbar_DX -> sensorValue = 0;
  lumbar_sx -> sensorValue = 0;

  counterOfAnalogRead = 0;

}
bool allFourZonesActivated() {
  if (((dorsal_sx -> averageValueOneSecond > zeroPoint) || (dorsal_DX -> averageValueOneSecond > zeroPoint)) &&
      ((centUp_sx -> averageValueOneSecond > zeroPoint) || (centUp_DX -> averageValueOneSecond > zeroPoint)) &&
      ((centDown_sx -> averageValueOneSecond > zeroPoint) || (centDown_DX -> averageValueOneSecond > zeroPoint)) &&
      ((lumbar_sx -> averageValueOneSecond > zeroPoint) || (lumbar_DX -> averageValueOneSecond > zeroPoint))) {

    return true;
  }
  else {
    breakSeconds = 0;
    return false;
  }
}

bool onlyLumbarActivated() {
  if ((dorsal_sx -> averageValueOneSecond <= zeroPoint) && (dorsal_DX -> averageValueOneSecond <= zeroPoint) &&
      (centUp_sx -> averageValueOneSecond <= zeroPoint) && (centUp_DX -> averageValueOneSecond <= zeroPoint) &&
      (centDown_sx -> averageValueOneSecond <= zeroPoint) && (centDown_DX -> averageValueOneSecond <= zeroPoint) &&
      ((lumbar_sx -> averageValueOneSecond > zeroPoint) || (lumbar_DX -> averageValueOneSecond > zeroPoint))) {

    return true;
  }
  else {
    breakSeconds = 0;
    return false;
  }
}

bool anythingActivated() {
  if ((dorsal_sx -> averageValueOneSecond <= zeroPoint) && (dorsal_DX -> averageValueOneSecond <= zeroPoint) &&
      (centUp_sx -> averageValueOneSecond <= zeroPoint) && (centUp_DX -> averageValueOneSecond <= zeroPoint) &&
      (centDown_sx -> averageValueOneSecond <= zeroPoint) && (centDown_DX -> averageValueOneSecond <= zeroPoint) &&
      (lumbar_sx -> averageValueOneSecond <= zeroPoint) && (lumbar_DX -> averageValueOneSecond <= zeroPoint)) {

    return false;
  }
  else {
    return true;
  }
}

void resetEverything() {

  badPostureSeconds = 0;
  sittingSeconds = 0;
  coefficient = 1;
  counterOfAnalogRead = 0;

  dorsal_DX -> sensorValue = 0;
  dorsal_sx -> sensorValue = 0;
  centUp_DX -> sensorValue = 0;
  centUp_sx -> sensorValue = 0;
  centDown_DX -> sensorValue = 0;
  centDown_sx -> sensorValue = 0;
  lumbar_DX -> sensorValue = 0;
  lumbar_sx -> sensorValue = 0;

  dorsal_DX -> averageValueOneSecond;
  dorsal_sx -> averageValueOneSecond;
  centUp_DX -> averageValueOneSecond;
  centUp_sx -> averageValueOneSecond;
  centDown_DX -> averageValueOneSecond;
  centDown_sx -> averageValueOneSecond;
  lumbar_DX -> averageValueOneSecond;
  lumbar_sx -> averageValueOneSecond;

  dorsal_DX -> sensorValueOneMinute = 0;
  dorsal_sx -> sensorValueOneMinute = 0;
  centUp_DX -> sensorValueOneMinute = 0;
  centUp_sx -> sensorValueOneMinute = 0;
  centDown_DX -> sensorValueOneMinute = 0;
  centDown_sx -> sensorValueOneMinute = 0;
  lumbar_DX -> sensorValueOneMinute = 0;
  lumbar_sx -> sensorValueOneMinute = 0;

  dorsal_DX -> sensorValueOneMinute = 0;
  dorsal_sx -> sensorValueOneMinute = 0;
  centUp_DX -> sensorValueOneMinute = 0;
  centUp_sx -> sensorValueOneMinute = 0;
  centDown_DX -> sensorValueOneMinute = 0;
  centDown_sx -> sensorValueOneMinute = 0;
  lumbar_DX -> sensorValueOneMinute = 0;
  lumbar_sx -> sensorValueOneMinute = 0;



}

void feedback() {
  if (soundSetting == true) {
    digitalWrite(buzzer, HIGH);
  }
  if (vibrationSetting == true) {
    digitalWrite(vibration, HIGH);
  }
}

void serialDiagnostic() {

  Serial.print("\ndorsal_sx  ");
  Serial.print(dorsal_sx -> averageValueOneSecond);
  Serial.print("      dorsal_dx  ");
  Serial.print(dorsal_DX -> averageValueOneSecond);

  Serial.print("\ncentUp_sx ");
  Serial.print(centUp_sx -> averageValueOneSecond);
  Serial.print("      centUp_dx ");
  Serial.print(centUp_DX -> averageValueOneSecond);

  Serial.print("\ncentDown_sx  ");
  Serial.print(centDown_sx -> averageValueOneSecond);
  Serial.print("      centDown_dx  ");
  Serial.print(centDown_DX -> averageValueOneSecond);

  Serial.print("\nlumbar_sx  ");
  Serial.print(lumbar_sx -> averageValueOneSecond);
  Serial.print("      lumbar_dx  ");
  Serial.print(lumbar_DX -> averageValueOneSecond);
  Serial.print("\n");
  Serial.print("Times of read in a second: ");
  Serial.print(counterOfAnalogRead);

  Serial.print("\n\n");
  Serial.print("\nTotal Sitting: ");
  Serial.print(sittingSeconds);
  Serial.print("      Wrong sitting: ");
  Serial.print(badPostureSeconds);

  Serial.print("\nBreak seconds: ");
  Serial.print(breakSeconds);
  Serial.print("\nBluetooth setting: ");
  Serial.print(bluetoothSetting);
  Serial.print("\tSound setting: ");
  Serial.print(soundSetting);
  Serial.print("\nVibration setting: ");
  Serial.print(vibrationSetting);
  Serial.print("\tMax sitting: ");
  Serial.print(maxSitting);
  Serial.print("\nmaxWrongPosture: ");
  Serial.print(maxWrongPosture);
  Serial.println("\n Stringa drive");
  Serial.print(g_drive); 
  Serial.print("\n");



  Serial.println(dorsal_DX -> sensorValueOneMinute);
  Serial.println(dorsal_sx -> sensorValueOneMinute);
  Serial.println(centUp_DX -> sensorValueOneMinute);
  Serial.println(centUp_sx -> sensorValueOneMinute);
  Serial.println(centDown_DX -> sensorValueOneMinute);
  Serial.println(centDown_sx -> sensorValueOneMinute);
  Serial.println(lumbar_DX -> sensorValueOneMinute);
  Serial.println(lumbar_sx -> sensorValueOneMinute);

  
}

void checkBadPosture() {
  if ((badPostureSeconds >= (maxWrongPosture * 60)) && 
  (allFourZonesActivated() == false || onlyLumbarActivated() == false || anythingActivated() == false)) {

    feedback();
    Serial.write("\n Sei stato seduto male.");

  }
}

void checkMaxSitting() {
  if (sittingSeconds >= (maxSitting * 60)) {

    if ((millis() - sittCurrentMillis) >= (60000 * coefficient)) {

      if ( coefficient >= 0.16) {
        coefficient -= 0.15;
      }

      feedback();
      Serial.write("\n Sei stato seduto troppo.");


    }
  }
}

void sendBluetooth() {

  int receiveData;
  String sendData;

  if (bluetoothSetting == true) {
    digitalWrite(pinBluetooth, HIGH);

    if (Bluetooth.available()) { //wait for data received
      receiveData = Bluetooth.read();

      int settings[10];
      String reader = "";

      if (receiveData == '1') { //send and receive data

        sendData =  dorsal_sx -> averageValueOneSecond;
        sendData += ";";
        sendData += dorsal_DX -> averageValueOneSecond;
        sendData += ";";
        sendData += centUp_sx -> averageValueOneSecond;
        sendData += ";";
        sendData += centUp_DX -> averageValueOneSecond;
        sendData += ";";
        sendData += centDown_sx -> averageValueOneSecond;
        sendData += ";";
        sendData += centDown_DX -> averageValueOneSecond;
        sendData += ";";
        sendData += lumbar_sx -> averageValueOneSecond;
        sendData += ";";
        sendData += lumbar_DX -> averageValueOneSecond;

        //Serial.println(sendData);
        Bluetooth.print(sendData);
        Bluetooth.flush();

        for (int i = 0; i < 4; i++) {
          reader = Bluetooth.readStringUntil(';');
          settings[i] = reader.toInt();
        }

        for ( int i = 0; i < 4; i++) {
          if (settings[i] != EEPROM.read(i)) {
            EEPROM.write(i, settings[i]);
          }
        }
        receiveData = ' ';
      }

      else if (receiveData == ' ' && receiveData != '1' && receiveData != '2' && receiveData != '3') {
        ;
      }
    }
  }
  else {
    digitalWrite(pinBluetooth, LOW);
  }
}

void updateSetting() {
  switch (EEPROM.read(0)) {
    case 0:
      maxWrongPosture = 2;
      break;

    case 1:
      maxWrongPosture = 15;
      break;

    case 2:
      maxWrongPosture = 10;
      break;

    default:
      maxWrongPosture = 5;
      break;
  }
  switch (EEPROM.read(1)) {
    case 0:
      maxSitting = 15;
      break;

    case 1:
      maxSitting = 30;
      break;

    case 2:
      maxSitting = 60;
      break;

    default:
      maxSitting = 15;
      break;
  }

  switch (EEPROM.read(2)) {
    case 0:
      soundSetting = false;
      break;

    case 1:
      soundSetting = true;
      break;

    default:
      soundSetting = true;
      break;
  }
  switch (EEPROM.read(3)) {
    case 0:
      vibrationSetting = false;
      break;

    case 1:
      vibrationSetting = true;
      break;

    default:
      vibrationSetting = true;
      break;
  }
  /*
    switch (EEPROM.read(4)) {
    case 0:
      bluetoothSetting = false;
      break;

    case 1:
      bluetoothSetting = true;
      break;

    default:
      bluetoothSetting = true;
      break;
    }*/
}

void collectData() {

  if (blockDataCounter < 3){   //15

  g_drive += dorsal_DX -> averageValueOneMinute;
  g_drive += dorsal_sx -> averageValueOneMinute;
  g_drive += centUp_DX -> averageValueOneMinute;
  g_drive += centUp_sx -> averageValueOneMinute;
  g_drive += centDown_DX -> averageValueOneMinute;
  g_drive += centDown_sx -> averageValueOneMinute;
  g_drive += lumbar_DX -> averageValueOneMinute;
  g_drive += lumbar_sx -> averageValueOneMinute;
  g_drive += ";";

  dorsal_DX -> averageValueOneMinute = 0 ;
  dorsal_sx -> averageValueOneMinute = 0 ;
  centUp_DX -> averageValueOneMinute = 0 ;
  centUp_sx -> averageValueOneMinute = 0 ;
  centDown_DX -> averageValueOneMinute = 0 ;
  centDown_sx -> averageValueOneMinute = 0 ;
  lumbar_DX -> averageValueOneMinute = 0 ;
  lumbar_sx -> averageValueOneMinute = 0 ;

  blockDataCounter++;
  }
  else{

    //turn ON wifi pin with transistor
    Serial.print(g_drive); 
    g_drive = "";

    
    blockDataCounter=0;
  }

}

void sumSensorMinute() {
  dorsal_DX -> sensorValueOneMinute += dorsal_DX -> averageValueOneSecond;
  dorsal_sx -> sensorValueOneMinute += dorsal_sx -> averageValueOneSecond;
  centUp_DX -> sensorValueOneMinute += centUp_DX -> averageValueOneSecond;
  centUp_sx -> sensorValueOneMinute += centUp_sx -> averageValueOneSecond;
  centDown_DX -> sensorValueOneMinute += centDown_DX -> averageValueOneSecond;
  centDown_sx -> sensorValueOneMinute += centDown_sx -> averageValueOneSecond;
  lumbar_DX -> sensorValueOneMinute += lumbar_DX -> averageValueOneSecond;
  lumbar_sx -> sensorValueOneMinute += lumbar_sx -> averageValueOneSecond;
}




void averageOneMinute() {

  dorsal_DX -> averageValueOneMinute = dorsal_DX -> sensorValueOneMinute / 60 ;
  dorsal_sx -> averageValueOneMinute = dorsal_sx -> sensorValueOneMinute / 60 ;
  centUp_DX -> averageValueOneMinute = centUp_DX -> sensorValueOneMinute / 60 ;
  centUp_sx -> averageValueOneMinute = centUp_sx -> sensorValueOneMinute / 60 ;
  centDown_DX -> averageValueOneMinute = centDown_DX -> sensorValueOneMinute / 60 ;
  centDown_sx -> averageValueOneMinute = centDown_sx -> sensorValueOneMinute / 60 ;
  lumbar_DX -> averageValueOneMinute = lumbar_DX -> sensorValueOneMinute / 60 ;
  lumbar_sx -> averageValueOneMinute = lumbar_sx -> sensorValueOneMinute / 60 ;
  //I could use the same variable
  dorsal_DX -> sensorValueOneMinute = 0;
  dorsal_sx -> sensorValueOneMinute = 0;
  centUp_DX -> sensorValueOneMinute = 0;
  centUp_sx -> sensorValueOneMinute = 0;
  centDown_DX -> sensorValueOneMinute = 0;
  centDown_sx -> sensorValueOneMinute = 0;
  lumbar_DX -> sensorValueOneMinute = 0;
  lumbar_sx -> sensorValueOneMinute = 0;

}
