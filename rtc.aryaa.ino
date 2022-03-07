#include <RTClib.h>
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial ss(0,1);

RTC_DS3231 rtc;

char t[32];

void setup() 
{
  ss.begin(115200);
  Serial.begin(115200);
  Wire.begin();

  rtc.begin();
  rtc.adjust(DateTime(F(__TIME__)));
  rtc.adjust(DateTime(0,0,0));
  

}

void loop()
{
  DateTime now = rtc.now();

  sprintf(t, "%2d:%2d:%02d",  now.hour(), now.minute(),now.second());  
  
  Serial.print("<");
  Serial.print(t);
  Serial.print(">");
  Serial.println();

  

  delay(1000);
}
