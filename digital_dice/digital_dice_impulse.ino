

//#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <M5Core2.h>
//#include <esp32_gesture_inferencing.h>
//#include <gesture_gaming_inferencing.h>
#include <m5stack-digital-dice_inferencing.h>

#define FREQUENCY_HZ        60
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

float accX = 0.0F;  
float accY = 0.0F; 
float accZ = 0.0F;
long randNumber;

// objeto da classe Adafruit_MPU6050
//Adafruit_MPU6050 mpu;

float features[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];
size_t feature_ix = 0;

static unsigned long last_interval_ms = 0;


void setup() {
  Serial.begin(115200);

  M5.begin();
  M5.IMU.Init();
  M5.Lcd.begin(); 
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(YELLOW); 
  M5.Lcd.setTextSize(6); 

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(35, 50);
  M5.Lcd.print("DIGITAL");
  M5.Lcd.setCursor(85, 115);
  M5.Lcd.print("DICE");

  delay(6000);

  Serial.print("Features: ");
  Serial.println(EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE);
  Serial.print("Label count: ");
  Serial.println(EI_CLASSIFIER_LABEL_COUNT);

//  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(YELLOW); 
  M5.Lcd.setTextSize(5); 

}

void loop() {
//  sensors_event_t a, g, temp;

  if (millis() > last_interval_ms + INTERVAL_MS) {
    last_interval_ms = millis();

//    mpu.getEvent(&a, &g, &temp);
    M5.IMU.getAccelData(&accX,&accY,&accZ);

    features[feature_ix++] = accX;
    features[feature_ix++] = accY;
    features[feature_ix++] = accZ;

    if (feature_ix == EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
//      Serial.println("Running the inference...");
      signal_t signal;
      ei_impulse_result_t result;
      int err = numpy::signal_from_buffer(features, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);
      if (err != 0) {
        ei_printf("Failed to create signal from buffer (%d)\n", err);
        return;
      }

      EI_IMPULSE_ERROR res = run_classifier(&signal, &result, true);

      if (res != 0) return;

//      ei_printf("Predictions ");
//      ei_printf("(DSP: %d ms., Classification: %d ms.)",
//                result.timing.dsp, result.timing.classification);
//      ei_printf(": \n");

      for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        ei_printf("    %s: %.5f\n", result.classification[ix].label, result.classification[ix].value);
        if (result.classification[ix].value > 0.6) {
          if (result.classification[ix].label == "front-back")
          {
//            digitalWrite(RED, HIGH);
//            digitalWrite(GREEN, LOW);
//            digitalWrite(BLUE, LOW);
              Serial.println(result.classification[ix].label);
//              M5.Lcd.clear(WHITE);
//              M5.Lcd.setCursor(20, 15);
//              M5.Lcd.print("FRONT-BACK");
              randNumber = random(1, 7);
              Serial.println(randNumber);
//              M5.Lcd.setCursor(20, 40);
//              M5.Lcd.print(randNumber);

                if(randNumber == 1)
                {
                  M5.Lcd.clear(BLACK);
                  M5.Lcd.setCursor(155, 20);
                  M5.Lcd.print("1");
                
                  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);
                
                  M5.Lcd.fillCircle(160, 150, 25, RED);
                }
                if(randNumber == 2)
                {
                  M5.Lcd.clear(BLACK);
                  M5.Lcd.setCursor(155, 20);
                  M5.Lcd.print("2");
                
                  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);
                
                  M5.Lcd.fillCircle(120, 150, 20, RED);
                  M5.Lcd.fillCircle(200, 150, 20, RED);
                }
                if(randNumber == 3)
                {
                  M5.Lcd.clear(BLACK);
                  M5.Lcd.setCursor(155, 20);
                  M5.Lcd.print("3");
                
                  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);
                
                  M5.Lcd.fillCircle(160, 120, 20, RED);
                  M5.Lcd.fillCircle(120, 180, 20, RED);
                  M5.Lcd.fillCircle(200, 180, 20, RED);
                }
                if(randNumber == 4)
                {
                  M5.Lcd.clear(BLACK);
                  M5.Lcd.setCursor(155, 20);
                  M5.Lcd.print("4");
                
                  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);
                
                  M5.Lcd.fillCircle(120, 190, 20, RED);
                  M5.Lcd.fillCircle(200, 190, 20, RED);
                  M5.Lcd.fillCircle(120, 120, 20, RED);
                  M5.Lcd.fillCircle(200, 120, 20, RED);
                }
                if(randNumber == 5)
                {
                  M5.Lcd.clear(BLACK);
                  M5.Lcd.setCursor(155, 20);
                  M5.Lcd.print("5");
                
                  M5.Lcd.fillRoundRect(85, 80, 150, 150, 10, YELLOW);
                
                  M5.Lcd.fillCircle(120, 110, 20, RED);
                  M5.Lcd.fillCircle(200, 110, 20, RED);
                  M5.Lcd.fillCircle(160, 150, 20, RED);
                  M5.Lcd.fillCircle(120, 190, 20, RED);
                  M5.Lcd.fillCircle(200, 190, 20, RED);
                }
                if(randNumber == 6)
                {
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
                }
          } else if (result.classification[ix].label == "left-right")
          {
//            digitalWrite(RED, LOW);
//            digitalWrite(GREEN, HIGH);
//            digitalWrite(BLUE, LOW);
              Serial.println(result.classification[ix].label);
//              M5.Lcd.clear(WHITE);
//              M5.Lcd.setCursor(20, 15);
//              M5.Lcd.print("LEFT-RIGHT");
          } else if (result.classification[ix].label == "idle")
          {
//            digitalWrite(RED, LOW);
//            digitalWrite(GREEN, LOW);
//            digitalWrite(BLUE, HIGH);
              Serial.println(result.classification[ix].label);
//              M5.Lcd.clear(WHITE);
//              M5.Lcd.setCursor(20, 15);
//              M5.Lcd.print("IDLE");
          } else
          {
//            digitalWrite(RED, LOW);
//            digitalWrite(GREEN, LOW);
//            digitalWrite(BLUE, LOW);
              Serial.println("NONE");
//              M5.Lcd.clear(WHITE);
//              M5.Lcd.setCursor(20, 15);
//              M5.Lcd.print("NONE");
          }
        }
      }
        feature_ix = 0;
    }

  }
}

void ei_printf(const char *format, ...) {
  static char print_buf[1024] = { 0 };

  va_list args;
  va_start(args, format);
  int r = vsnprintf(print_buf, sizeof(print_buf), format, args);
  va_end(args);

  if (r > 0) {
    Serial.write(print_buf);
  }
}
