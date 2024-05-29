/*
 * Connects the ESP8266 NodeMCU board to wifi, BME280 and sends data to remote Grafana

 */

#include "ESP8266WiFi.h"
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;
WiFiClient TCP_Client;


// WiFi parameters to be configured
const char* ssid = ""; // Write here your router's username
const char* password = ""; // Write here your router's passward

bool bme280_status;
delayTime = 60000;
unsigned char buffer[80];
char humidity[5];
unsigned int TCPPort = 2003;
IPAddress    TCP_Server(192, 168, 20, 100);
const String Devicename = "ESP8266";
const String topic = "esp8266.cpu_temp";
const String timestamp = "-1";
String result;

void setup(void)
{ 
  Serial.begin(9600); //Enable Serial

  bme280_status = bme.begin();
  if (!bme280_status) {
      Serial.print("BME280 NOT FOUND");
      while (1);
    }
  WiFi.begin(ssid, password); //Connect to WiFi
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
  // Check if Grafana server is up
  Connect_To_Server();
}

void loop() {
  Send_Request_To_Server();
  delay(delayTime);
}


void Send_Request_To_Server() {
//unsigned long tNow;
    
  //tNow=millis();
  //dtostrf(10.5, 5, 1, humidity); // create a char[] out of the tNow
  //esp8266.cpu_temp 36.6 -1
  //result = ("esp8266.cpu_temp "+ humidity + " -1");
  Serial.println(prepare_data("bme280.temp",bme.readTemperature()));
  Serial.println(prepare_data("bme280.pressure",bme.readPressure() / 100.0F));
  Serial.println(prepare_data("bme280.humidity",bme.readHumidity()));

  Serial.println(result);
  //TCP_Client.println(result);
 // TCP_Client.flush();                                     // Empty Bufffer 
  
}

void prepare_data (topic, value) {
  // this crafts string like "esp8266.cpu_temp 36.6 -1"
  payload = "";
  payload += topic;
  payload += " ";
  payload += value;
  payload += " -1";
}

void Connect_To_Server() {
  if(TCP_Client.connect(TCP_Server, TCPPort)){
    Serial.println    ("<" + Devicename + "-CONNECTED>");
  }
}
