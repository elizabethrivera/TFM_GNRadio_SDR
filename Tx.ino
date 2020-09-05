#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
void setup(){
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop(){
  //mySwitch.send("01100011011011110110111001100110");
  mySwitch.send("0011");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  mySwitch.send("0001");
  delay(2000);
}
