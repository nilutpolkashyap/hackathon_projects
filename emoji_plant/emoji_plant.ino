#include "DHT.h"
#define DHTTYPE DHT11 

#define DHTPIN 13 // Port C , Pin 33 for Port A 
#define LDRPIN 33   // Port A 
#define MSTPIN 36 // Port B

DHT dht(DHTPIN, DHTTYPE);

#define LOW_TEMP_THRESOLD 15
#define HIGH_TEMP_THRESOLD 45
#define DAY_LIGHT_THRESOLD 500
#define NIGHT_LIGHT_THRESOLD 10
#define LOW_SOIL_MOISTURE_THRESOLD 3800
#define HIGH_SOIL_MOISTURE_THRESOLD 300

int temp = 0;
int ldr_value;
int moisture = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(F("EMOJI PLANT TEST"));
  
  dht.begin();
  pinMode(MSTPIN, INPUT);
  pinMode(LDRPIN, INPUT);
}

void loop() {
  delay(2000);
  
  temp = dht.readTemperature();
  moisture = analogRead(MSTPIN);
  ldr_value = analogRead(LDRPIN);

  Serial.println("Temperature: ");
  Serial.println(temp);

  Serial.println("Soil Moisture: ");
  Serial.println(moisture);

  Serial.print("LDR Value: ");
  Serial.println(ldr_value);

}
