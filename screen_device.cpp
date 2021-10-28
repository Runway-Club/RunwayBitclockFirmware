#include "screen_device.h"
// #include <Fonts/FreeMono18pt7b.h>

ScreenDevice::ScreenDevice()
{
}

ScreenDevice::ScreenDevice(int width, int height, Adafruit_ST7735 *tft)
{
    this->width = width;
    this->height = height;
    this->tft = tft;
    this->tft->setRotation(1);
    // this->tft->setFont(&FreeMono18pt7b);
}

void ScreenDevice::init()
{
    tft->initR(INITR_BLACKTAB);
    tft->fillScreen(ST7735_BLACK);
    tft->setRotation(1);
}

Adafruit_ST7735 *ScreenDevice::getDevice()
{
    return tft;
}

int ScreenDevice::getWidth()
{
    return width;
}

int ScreenDevice::getHeight()
{
    return height;
}
