#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJSON.h>

const char* ssid = "SKYPEMHG";
const char* password =  "8NHetSWQAJ75";
const uint16_t port = 7100;
//const char * host = "192.168.0.2";  //host PC Macbook
const char * host = "192.168.0.56";   //host Gaming PC

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

  pinMode(4,INPUT_PULLDOWN);
  pinMode(0,INPUT_PULLDOWN);
  pinMode(2,INPUT_PULLDOWN);
  pinMode(15,INPUT_PULLDOWN);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
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
    Serial.println("Connection to server successful!");
    client.print (sendMessage());    
    Serial.println("Disconnecting...");
    client.stop();
    delay(10000);
}