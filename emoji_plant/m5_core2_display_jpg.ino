/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5Core2 sample source code
*                          配套  M5Core2 示例源代码
* Visit the website for more information：https://docs.m5stack.com/en/core/core2
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/core/core2
*
* describe：Display Example.  显示屏示例
* date：2021/7/21
*******************************************************************************
*/
#include <M5Core2.h>

//#include <M5Stack.h>

//#include <M5Stack.h>
extern uint8_t nightcrop[];

void setup(void) {
    M5.begin();
//    M5.Power.begin();
    // Draw the jpeg file "p2.jpg" from TF(SD) card
    M5.Lcd.setBrightness(200);
//    M5.Lcd.drawJpg(nightcrop, 10062); 
//    M5.Lcd.drawBmpFile(SD, "/nightcrop.bmp",0,0);
//    delay(3000);
//    M5.Lcd.clear(WHITE);
//    M5.Lcd.drawBmpFile(SD, "/m5_logo.bmp",0,0);
//    delay(3000);
//    M5.Lcd.clear(WHITE);
//    M5.Lcd.drawJpgFile(SD, "/tetris.jpg", 20, 30, 40, 50);
//    delay(3000);
//    M5.Lcd.drawJpgFile(SD, "/over.jpg", 20, 30, 40, 50);
//    delay(3000);
    // M5.Lcd.drawJpgFile(SD, "/p1.jpg", 20, 30, 40, 50);
    // M5.Lcd.drawJpgFile(fs::FS &fs, const char *path, ui  nt16_t x, uint16_t y,
    // uint16_t maxWidth, uint16_t maxHeight, uint16_t offX, uint16_t offY,
    // jpeg_div_t scale);
}

void loop() {
    M5.Lcd.drawJpgFile(SD, "/happy.jpg");
    delay(3000);
    M5.Lcd.drawJpgFile(SD, "/thirsty.jpg");
    delay(3000);
    M5.Lcd.drawJpgFile(SD, "/cold.jpg");
    delay(3000);
    M5.Lcd.drawJpgFile(SD, "/hot.jpg");
    delay(3000);
    M5.Lcd.drawJpgFile(SD, "/night.jpg");
    delay(3000);
    M5.Lcd.drawJpgFile(SD, "/over.jpg");
    delay(3000);
//    M5.Lcd.clear(WHITE);
//    delay(3000);
//    delay(3000);
//    M5.Lcd.drawJpgFile(SD, "/smile.jpg");
//    delay(3000);
//    M5.Lcd.drawBmpFile(SD, "/happy.bmp",0,0);
//    delay(3 000);
//    M5.Lcd.clear(WHITE);
//    M5.Lcd.drawBmpFile(SD, "/hot.bmp",0,0);
//    delay(3000);
//    M5.Lcd.clear(WHITE);
//    M5.Lcd.drawBmpFile(SD, "/thirsty.bmp",0,0);
//    delay(3000);
//    M5.Lcd.clear(WHITE);
//    M5.Lcd.drawBmpFile(SD, "/over.bmp",0,0);
//    delay(3000);
//    M5.Lcd.clear(WHITE);
//    M5.Lcd.drawBmpFile(SD, "/cold.bmp",0,0);
//    delay(3000);
//    M5.Lcd.clear(WHITE);
//    M5.Lcd.drawBmpFile(SD, "/night.bmp",0,0);
//    delay(3000);
//    M5.Lcd.clear(WHITE);
    }
