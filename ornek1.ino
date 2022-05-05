byte relON[] = {0xA0, 0x01, 0x01, 0xA2}; //Hex command to send to serial for open relay
byte relOFF[] = {0xA0, 0x01, 0x00, 0xA1}; //Hex command to send to serial for close relay

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.write(relON, sizeof(relON));
delay(3000);
Serial.write(relOFF, sizeof(relOFF));
delay(3000);
}
