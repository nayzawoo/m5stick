#include <M5StickC.h>
#include "banana.h"

void setup() {
	M5.begin();
	M5.Lcd.setRotation(1);
    M5.Axp.ScreenBreath(10); // 7-12
}

void loop() {
    M5.Lcd.drawBitmap(random(M5.Lcd.width() - 1 ), random(M5.Lcd.height()-1), imgWidth, imgHeight, img);
    M5.Lcd.setCursor(10, 30);  
  	M5.Lcd.setTextSize(3);
  	M5.Lcd.print("Hello!");  
    delay(200);
}

