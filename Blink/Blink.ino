#include <M5StickC.h>

// https://github.com/nayzawoo/esp-tests/blob/main/NOTE.md#pinmap
int LED_BUILTIN = 10; // m5stickc use GPIO10

void setup(void) {
  M5.begin();
  M5.Axp.ScreenBreath(10); // 7-12
  M5.Lcd.setRotation(3);
  
  pinMode(LED_BUILTIN, OUTPUT);
  reset();
}

void reset() {
  M5.Lcd.fillScreen(GREEN);
  digitalWrite(LED_BUILTIN, HIGH);
}

void blink() {
  M5.Lcd.fillScreen(RED);
  digitalWrite(LED_BUILTIN, LOW);

  // reset
  delay(200);
  reset();
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    blink();
  }
}
