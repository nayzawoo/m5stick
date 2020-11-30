#include <M5StickC.h>
// https://github.com/crankyoldgit/IRremoteESP8266
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Daikin.h>

// m5stickc has build in IR transmitter
// https://github.com/m5stack/M5StickC#pinmap
// ESP8266 GPIO pin to use.
const uint16_t kIrLed = 9; // ESP8266 GPIO pin to use.
IRsend irsend(kIrLed);     // Set the GPIO to be used to sending the message.
IRDaikinESP ac(kIrLed);    // Set the GPIO to be used to sending the message

void setup()
{
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
    irsend.begin();
    ac.begin();
    Serial.begin(115200);
}

void loop()
{
    M5.update();

    if (M5.BtnA.wasPressed()) {
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(0, 10);
        M5.Lcd.println("Pressed A");
        ac.on();
    }

    if (M5.BtnB.wasPressed())
    {
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(0, 10);
        M5.Lcd.println("B");
    }

    delay(200);
}