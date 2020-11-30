#include <M5StickC.h>
#include "banana.h"

void setup() {
	M5.begin();
	M5.Lcd.setRotation(1);
    M5.Axp.ScreenBreath(10); // 7-12
}

void loop() {
    M5.Lcd.drawBitmap(0, 0, imgWidth, imgHeight, img);
    delay(1);
}

