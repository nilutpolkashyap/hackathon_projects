#include <M5Core2.h>
#include "DHT.h"
#define DHTTYPE DHT11 

#define DHTPIN 13 // Port C , Pin 33 for Port A 
#define LDRPIN 33   // Port A 
#define MSTPIN 36 // Port B

DHT dht(DHTPIN, DHTTYPE);

#define LOW_TEMP_THRESOLD 15
#define HIGH_TEMP_THRESOLD 35
#define DAY_LIGHT_THRESOLD 500
#define NIGHT_LIGHT_THRESOLD 100  //10
#define LOW_SOIL_MOISTURE_THRESOLD 3800
#define HIGH_SOIL_MOISTURE_THRESOLD 2000

int temp = 0;
int ldr_value;
int moisture = 0;

void setup() {
  Serial.begin(115200);
  Serial.println(F("EMOJI PLANT TEST"));
  
  dht.begin();
  pinMode(MSTPIN, INPUT);
  pinMode(LDRPIN, INPUT);

  M5.begin();
  M5.Lcd.setBrightness(200);
}

void loop() {
  delay(2000);
  
  temp = dht.readTemperature();
  moisture = analogRead(MSTPIN);
  ldr_value = analogRead(LDRPIN);
  ldr_value = ldr_value-2500;

  Serial.print("Temperature: ");
  Serial.println(temp);

  Serial.print("Soil Moisture: ");
  Serial.println(moisture);

  Serial.print("LDR Value: ");
  Serial.println(ldr_value);

//  M5.Lcd.drawJpgFile(SD, "/happy.jpg");
//  delay(3000);
//  M5.Lcd.drawJpgFile(SD, "/thirsty.jpg");
//  delay(3000);
//  M5.Lcd.drawJpgFile(SD, "/cold.jpg");
//  delay(3000);
//  M5.Lcd.drawJpgFile(SD, "/hot.jpg");
//  delay(3000);
//  M5.Lcd.drawJpgFile(SD, "/night.jpg");
//  delay(3000);
//  M5.Lcd.drawJpgFile(SD, "/over.jpg");
//  delay(3000);

  if (ldr_value <= NIGHT_LIGHT_THRESOLD)
  {
    M5.Lcd.drawJpgFile(SD, "/night.jpg");
  }
  else 
  {
    if (moisture >= LOW_SOIL_MOISTURE_THRESOLD)
    {
      M5.Lcd.drawJpgFile(SD, "/thirsty.jpg");
    }
    else if (moisture <= HIGH_SOIL_MOISTURE_THRESOLD )
    {
      M5.Lcd.drawJpgFile(SD, "/over.jpg");
    }
    else 
    {
      if (temp >= HIGH_TEMP_THRESOLD)
      {
        M5.Lcd.drawJpgFile(SD, "/hot.jpg");
      }
      else if (temp <= LOW_TEMP_THRESOLD)
      {
        M5.Lcd.drawJpgFile(SD, "/cold.jpg");
      }
      else
      {
        M5.Lcd.drawJpgFile(SD, "/happy.jpg");
      }
    }
  }

}
