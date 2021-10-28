#ifndef SCREEN_DEVICE_H
#define SCREEN_DEVICE_H

#include <Adafruit_ST7735.h>

class ScreenDevice
{
protected:
    int width;
    int height;
    Adafruit_ST7735 *tft;

public:
    ScreenDevice();
    ScreenDevice(int width, int height, Adafruit_ST7735 *tft);
    void init();
    Adafruit_ST7735 *getDevice();
    int getWidth();
    int getHeight();
};

#endif