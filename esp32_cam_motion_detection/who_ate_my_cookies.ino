#include <WiFi.h>
#include <HTTPClient.h>
#include <sstream>
 
const char* ssid = "WIFI_SSID";
const char* password =  "WIFI_PASSWORD";
 
const char * messagingServiceSid = "yourMessagingServiceId";
const char * to = "destinationPhoneNumber";
const char * accountNr = "yourAccountNr;
const char * twilioPassword = "yourApiKey";
 
bool sendSMS(const char * body){
 
  std::stringstream url;
  url << "https://api.twilio.com/2010-04-01/Accounts/" << accountNr <<"/Messages";
 
  std::stringstream urlEncodedBody;
  urlEncodedBody << "MessagingServiceSid=" << messagingServiceSid << "&To=" << to << "&Body=" << body;
 
  Serial.print("\nURL: ");
  Serial.println(url.str().c_str());
  Serial.print("Encoded body: ");
  Serial.println(urlEncodedBody.str().c_str());
   
 
  HTTPClient http;
 
  http.begin(url.str().c_str());
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.setAuthorization(accountNr, twilioPassword);
   
  int httpCode = http.POST(urlEncodedBody.str().c_str());                                               
  
  if (httpCode > 0) {
 
      String payload = http.getString();
 
      Serial.print("\nHTTP code: ");
      Serial.println(httpCode);
 
      Serial.print("\nResponse: ");
      Serial.println(payload);
    }
 
  else {
    Serial.println("Error on HTTP request:");
    Serial.println(httpCode);
  }
 
  http.end();
 
  return httpCode == 201;
 
}

const int PIN_TO_SENSOR = 13; // GIOP19 pin connected to OUTPUT pin of sensor
const int LED = 4;
int pinStateCurrent   = LOW;  // current state of pin
int pinStatePrevious  = LOW;  // previous state of pin

int msg_count = 0;

void setup() {
  Serial.begin(115200);            // initialize serial
  pinMode(PIN_TO_SENSOR, INPUT); // set ESP32 pin to input mode to read value from OUTPUT pin of sensor
  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");

//  bool result = sendSMS("Cookie Thief Detected. Photo Saved");
}

void loop() {
  pinStatePrevious = pinStateCurrent; // store old state
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);   // read new state

  if (pinStatePrevious == LOW && pinStateCurrent == HIGH) {   // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
    digitalWrite(LED, HIGH);
    if(msg_count%4 == 0){
      bool result = sendSMS("Cookie Thief Detected. Photo Saved");
      Serial.println("SMS Sent");
    }
    msg_count = msg_count + 1;
    // TODO: turn on alarm, light or activate a device ... here
  }
  else
  if (pinStatePrevious == HIGH && pinStateCurrent == LOW) {   // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
    digitalWrite(LED, LOW);
    // TODO: turn off alarm, light or deactivate a device ... here
  }
}
