/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (mySwitch.available()) {
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );
    if (mySwitch.getReceivedValue()==3){
      digitalWrite(LED_BUILTIN, HIGH);}
    if (mySwitch.getReceivedValue()==1){
      digitalWrite(LED_BUILTIN, LOW);}
    mySwitch.resetAvailable();
  }
}
