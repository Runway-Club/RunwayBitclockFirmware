
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <gfxfont.h>

#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_ST77xx.h>

#include "screen_device.h"
#include "speaker.h"
#include "notification_scene.h"
#include "finance_scene.h"

#define TFT_CS D0
#define TFT_RST D2
#define TFT_DC D1
#define SPEAKER D3

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define TFT_SCLK D5
#define TFT_MOSI D7

Speaker *speaker;
NotificationScene *notificationScene;
FinanceScene *financeScene;

int currentTime = 0;
int previousTime = 0;
int deltaT = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(SPEAKER, OUTPUT);
    digitalWrite(SPEAKER, 0);

    ScreenDevice *screen = new ScreenDevice(128, 160, &tft);
    screen->init();

    speaker = new Speaker(SPEAKER);

    notificationScene = new NotificationScene(screen);

    financeScene = new FinanceScene(screen);

    previousTime = millis();
}

void loop()
{
    currentTime = millis();
    deltaT = currentTime - previousTime;
    financeScene->render(0);
    // notificationScene->render(deltaT);

    previousTime = currentTime;
}
