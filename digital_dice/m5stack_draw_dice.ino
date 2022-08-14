#include <M5Core2.h>

void setup() {
  M5.begin();   //Initialize M5Core2
//  M5.Lcd.fillRoundRect(55, 55, 30, 50, 10, GREEN);//Draw a green rounded rectangle with a width and height of 30, 50 and a rounded radius of 10 at (55, 55).

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(YELLOW); 
  M5.Lcd.setTextSize(6); 

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(35, 50);
  M5.Lcd.print("DIGITAL");
  M5.Lcd.setCursor(75, 115);
  M5.Lcd.print("DICE");

  delay(9000);

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(YELLOW); 
  M5.Lcd.setTextSize(5); 

  M5.Lcd.clear(WHITE);
  M5.Lcd.setCursor(20, 10);
  M5.Lcd.print("Welcome");
}

void loop() {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(155, 20);
  M5.Lcd.print("1");

  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);

  M5.Lcd.fillCircle(160, 150, 25, RED);

  delay(2000);

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(155, 20);
  M5.Lcd.print("2");

  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);

  M5.Lcd.fillCircle(120, 150, 20, RED);
  M5.Lcd.fillCircle(200, 150, 20, RED);

  delay(2000);

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(155, 20);
  M5.Lcd.print("3");

  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);

  M5.Lcd.fillCircle(160, 120, 20, RED);
  M5.Lcd.fillCircle(120, 180, 20, RED);
  M5.Lcd.fillCircle(200, 180, 20, RED);

  delay(2000);

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(155, 20);
  M5.Lcd.print("4");

  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);

  M5.Lcd.fillCircle(120, 190, 20, RED);
  M5.Lcd.fillCircle(200, 190, 20, RED);
  M5.Lcd.fillCircle(120, 120, 20, RED);
  M5.Lcd.fillCircle(200, 120, 20, RED);

  delay(2000);

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(155, 20);
  M5.Lcd.print("5");

  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);

  M5.Lcd.fillCircle(120, 110, 20, RED);
  M5.Lcd.fillCircle(200, 110, 20, RED);
  M5.Lcd.fillCircle(160, 150, 20, RED);
  M5.Lcd.fillCircle(120, 190, 20, RED);
  M5.Lcd.fillCircle(200, 190, 20, RED);

  delay(2000);

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(155, 20);
  M5.Lcd.print("6");

  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);

  M5.Lcd.fillCircle(120, 150, 20, RED);
  M5.Lcd.fillCircle(200, 150, 20, RED);
  M5.Lcd.fillCircle(120, 100, 20, RED);
  M5.Lcd.fillCircle(200, 100, 20, RED);
  M5.Lcd.fillCircle(120, 200, 20, RED);
  M5.Lcd.fillCircle(200, 200, 20, RED);

  delay(2000);
  
  }
