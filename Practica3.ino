//Welcome to E for Engineer---SUBSCRIBE Now
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//Replace your wifi credentials here
const char* ssid     = "IZZI-RODRIGUEZ";
const char* password = "Amarillo10";

//change your channel number here
unsigned long channel =1689980;//Replace with your own ThingSpeak Account Channle ID

//1,2 and 3 are channel fields. You don't need to change if you are following this tutorial. However, you can modify it according to your application
unsigned int led1 = 1;
unsigned int led2 = 2;
unsigned int led3 = 3;

WiFiClient  client;


void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(12, 0);
  digitalWrite(13, 0);
  digitalWrite(15, 0);
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

void loop() {
 
  //get the last data of the fields
  int led_1 = ThingSpeak.readFloatField(channel, led1);
  int led_2 = ThingSpeak.readFloatField(channel, led2);
  int led_3 = ThingSpeak.readFloatField(channel, led3);
 
  if(led_1 == 1){
    digitalWrite(12, HIGH);
    Serial.println("D1 is On..!");
  }
  else if(led_1 == 0){
    digitalWrite(12, LOW);
    Serial.println("D1 is Off..!");
  }
 
  if(led_2 == 1){
    digitalWrite(13, HIGH);
    Serial.println("D2 is On..!");
  }
  else if(led_2 == 0){
    digitalWrite(13, LOW);
    Serial.println("D2 is Off..!");
  }
 
  if(led_3 == 1){
    digitalWrite(15, HIGH);
    Serial.println("D3 is On..!");
  }
  else if(led_3 == 0){
    digitalWrite(15, LOW);
    Serial.println("D3 is Off..!");
  }
    
  Serial.println(led_1);
  Serial.println(led_2);
  Serial.println(led_3);
  delay(5000);
 
}
