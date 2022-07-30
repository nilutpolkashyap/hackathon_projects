#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino.h>
#include <Arduino_JSON.h>

const char* ssid     = "ASUS_X00TD";
const char* password = "biscuitppp";
String openWeatherMapApiKey = "API_KEY";
String city = "CITY_NAME";

String jsonBuffer;

void setup()
{
    Serial.begin(115200);
    delay(10);

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
}

void loop()
{
    String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city +  "&APPID=" + openWeatherMapApiKey;

    jsonBuffer = httpGETRequest(serverPath.c_str());
//      Serial.println(jsonBuffer);
      JSONVar myObject = JSON.parse(jsonBuffer);

    if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }

    Serial.print("Temperature: ");
    Serial.println(myObject["main"]["temp"]);
    Serial.print("Pressure: ");
    Serial.println(myObject["main"]["pressure"]);
    Serial.print("Humidity: ");
    Serial.println(myObject["main"]["humidity"]);
    Serial.print("Timezone: ");
    Serial.println(myObject["timezone"]);

}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
