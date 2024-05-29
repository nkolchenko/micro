/*
 * Connects the ESP8266 NodeMCU board to wifi and prints the IP address
 * 
 * by:
 * ROBOSANS
 * based on ThingSpeak Library example
 * 
 * https://www.robosans.com/
 */

#include "ESP8266WiFi.h"

// WiFi parameters to be configured
const char* ssid = ""; // Write here your router's username
const char* password = ""; // Write here your router's passward

WiFiClient TCP_Client;
unsigned char buffer[80];
char humidity[5];
unsigned int  TCPPort = 2003;
IPAddress     TCP_Server(192, 168, 20, 100);
const String  Devicename = "Device_1";
const String  topic = "esp8266.cpu_temp";
const String  timestamp = "-1";
String result;

void setup(void)
{ 
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
  Connect_To_Server();
  
}

void loop() {
  Send_Request_To_Server();
}



void Send_Request_To_Server() {
unsigned long tNow;
    
  //tNow=millis();
  dtostrf(10.5, 5, 1, humidity); // create a char[] out of the tNow
  //esp8266.cpu_temp 36.6 -1
  //result = ("esp8266.cpu_temp "+ humidity + " -1");
  result += "esp8266.cpu_temp ";
  result += humidity;
  result += " -1";
  Serial.println(result);
  TCP_Client.println(result);
 delay(60000);// Send Data
 // TCP_Client.flush();                                     // Empty Bufffer 
  
}

void Connect_To_Server() {
  if(TCP_Client.connect(TCP_Server, TCPPort)){
    Serial.println    ("<" + Devicename + "-CONNECTED>");
  }
}
