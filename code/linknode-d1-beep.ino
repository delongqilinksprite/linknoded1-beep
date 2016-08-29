/* ============================================
LinkSpriteIO library for LinkNode D1 

LinkSpriteIO is an IoT cloud platform to link devices. LinkSprite has released a complete set of hardware for LinkSpriteIO with open source hardware designs and open source firmware.
The overall LinkSpriteIO architecture including LinkSpriteIO cloud, web/desktop/mobile apps and LinkSpriteIO-compatible nodes is illustrated by following graph.

LinkNode D1 is Arduino-compatible WiFi development board which is powered by the high integrated WiFi chip ESP-8266EX.
Thanks for the contribution from open source community who have developed Arduino core for ESP8266, this let Aduino IDE program LinkNode D1 without any change. At the same time, LinkNode D1 has Arduino-compatible pin out which make it very easy to connect to Arduino shield.

auther: Derron form LinkSprite
date:2016.7.13
file:LinkSpriteIO-DIY
===============================================
*/


#include<LinkSpriteIO.h>

String deviceID = "xxxxxxxxxx";
String apikey = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxxx";

LinkSpriteIO linksprite(deviceID,apikey);
const int key = 2;
const int buzzer = 12;
int key_value = 0;

void beep()
{
    int n,i,j;
    for(n = 0;n < 2;n ++)
    {
        for(i = 0;i < 350 ; i++)
        {
            digitalWrite(buzzer,HIGH);
            delayMicroseconds(714);
            digitalWrite(buzzer,LOW);
            delayMicroseconds(714); 
        }  
        for(j = 0;j < 250 ; j++)
        {
            digitalWrite(buzzer,HIGH);
            delayMicroseconds(1000);
            digitalWrite(buzzer,LOW);
            delayMicroseconds(1000); 
        }
        delay(400);  
    }      
}

void setup()
{
    String s;
    Serial.begin(115200);
    linksprite.begin();
    pinMode(key,INPUT);
    pinMode(buzzer,OUTPUT);
}

void loop()
{ 
   key_value = digitalRead(key);
   if(key_value == LOW)
   {
       delay(10);
       if(key_value == LOW)
       {
          linksprite.update("light","1"); 
          beep();
          delay(2000);
          linksprite.update("light","0");
       }
   }
}