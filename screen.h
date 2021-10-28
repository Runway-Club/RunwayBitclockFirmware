#ifndef SCREEN_H
#define SCREEN_H

#include <Adafruit_ST7735.h>

class Screen
{
protected:
    int width;
    int height;
    Adafruit_ST7735 *tft;

public:
    Screen();
    Screen(int width, int height, Adafruit_ST7735 *tft);
    void init();
    void render();
};

#endif