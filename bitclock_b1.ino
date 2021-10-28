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

#include "screen.h"
#include "speaker.h"

#define TFT_CS D0
#define TFT_RST D2
#define TFT_DC D1
#define SPEAKER D3

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define TFT_SCLK D5
#define TFT_MOSI D7

Speaker *speaker = new Speaker(SPEAKER);

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(SPEAKER, OUTPUT);
    digitalWrite(SPEAKER, 0);

    Screen *screen = new Screen(128, 160, &tft);
    screen->init();
}

void loop()
{
    // int beats[] = {1, 2, 1, 1, 1, 1, 2};
    // speaker->playRingtone(new Ringtone{
    //     .notes = "bEGFEBA ",
    //     .beats = beats,
    //     .tempo = 200,
    //     .length = 7});
    // delay(2000);
}
