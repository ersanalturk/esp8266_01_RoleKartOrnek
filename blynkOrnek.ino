/*control relay looking at virtual pin sent from Blynk and serial writing commands to chip onboard Relay board - works */

#define BLYNK_TEMPLATE_ID "" //bilgi girişi
#define BLYNK_DEVICE_NAME "" //bilgi girişi
#define BLYNK_AUTH_TOKEN "" //bilgi girişi
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "" //bilgi girişi
char pass[] = "" //bilgi girişi

BlynkTimer timer;

byte relON[] = {0xA0, 0x01, 0x01, 0xA2}; //Hex command to send to serial for open relay
byte relOFF[] = {0xA0, 0x01, 0x00, 0xA1}; //Hex command to send to serial for close relay

void setup()
{
// Debug console
Serial.begin(9600);

Blynk.begin(auth, ssid, pass);
// You can also specify server: (Blynk sample code)
//Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
//Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

// Relay on off
BLYNK_WRITE(V0) {
int button = param.asInt(); // read button
if (button == 1) {
Serial.write(relON, sizeof(relON));
}
else {
Serial.write(relOFF, sizeof(relOFF));
}
}

void loop()
{
Blynk.run();
}
