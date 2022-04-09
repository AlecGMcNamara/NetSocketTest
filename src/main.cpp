#include <Arduino.h>
#include <WiFi.h>
 
const char* ssid = "SKYPEMHG";
const char* password =  "8NHetSWQAJ75";
const uint16_t port = 7100;
const char * host = "192.168.0.2";  //host PC
 
void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
}
 
void loop()
{
    WiFiClient client;
     if (!client.connect(host, port)) {
         Serial.println("Connection to host failed");
         delay(1000);
        return;
    }
    Serial.println("Connected to server successful!");
    client.print("Hello from ESP32 Number 3");
    Serial.println("Disconnecting...");
    client.stop();
    delay(10000);
}