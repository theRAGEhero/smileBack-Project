void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(vibration, OUTPUT);
  pinMode(pinBluetooth, OUTPUT);




  dorsal_DX = new Fsr(1);    // pin
  dorsal_sx = new Fsr(0);

  centUp_DX = new Fsr(3);
  centUp_sx = new Fsr(2);

  centDown_DX = new Fsr(6);
  centDown_sx = new Fsr(7);

  lumbar_DX = new Fsr(5);
  lumbar_sx = new Fsr(4);



}
