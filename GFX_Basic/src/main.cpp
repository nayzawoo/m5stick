#define LGFX_M5STICK_C true
#include <M5StickC.h>
#include <LovyanGFX.hpp>
#include "banana.h"

static LGFX lcd;

void setup() {
	M5.begin();
	M5.Axp.ScreenBreath(10); // 7-12

	lcd.init();
	lcd.setRotation(3);
	lcd.setSwapBytes(true);
	lcd.startWrite();
}

void loop() {
	int x = random(lcd.width());
	int y = random(lcd.height());
	lcd.pushImage(0, 0, imgWidth, imgHeight, img);
	delay(1000);
}