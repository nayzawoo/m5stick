#include <M5StickC.h>
#include "crack.h"

float accX = 0;
float accY = 0;
float accZ = 0;

void resetScreen() {
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setCursor(10, 30);  
  M5.Lcd.setTextSize(3);
  M5.Lcd.print("SHAKE ME");
}

void setup() 
{
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(1);
  M5.Axp.ScreenBreath(10); // 7-12

  resetScreen();
  delay(1000);
}

void drawCrack() {
    M5.Lcd.drawBitmap(0, 0, imgWidth, imgHeight, img);
}

void loop() 
{
  M5.update();

  M5.IMU.getAccelData(&accX,&accY,&accZ);

  if (accX > 1.5 ||  accY > 1.5 ) {
    drawCrack();
    delay(200); 
  }

  if (M5.BtnA.wasPressed() || M5.BtnB.wasPressed()) {
    M5.Lcd.fillScreen(TFT_BLACK);
    resetScreen();
    delay(1000);
  }
}
