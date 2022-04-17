#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJSON.h>

const char* ssid = "SKYPEMHG";
const char* password =  "8NHetSWQAJ75";
const uint16_t port = 7100;
//const char * host = "192.168.0.2";  //host PC
const char * host = "192.168.0.56";

String sendMessage()
{
    StaticJsonDocument<200> jsonSend;

    jsonSend["input1"] = digitalRead(4);
    jsonSend["input2"] = digitalRead(0);
    jsonSend["input3"] = digitalRead(2);
    jsonSend["input4"] = digitalRead(15);

    String strMessage = "";
    serializeJson(jsonSend,strMessage);
    return strMessage;
}

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
    client.print (sendMessage());    
    //
    //Serial.print("Received ");
    //Serial.println(test);
    Serial.println("Disconnecting...");
    client.stop();
    delay(10000);
}