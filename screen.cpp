#include "screen.h"

Screen::Screen()
{
}

Screen::Screen(int width, int height, Adafruit_ST7735 *tft)
{
    this->width = width;
    this->height = height;
    this->tft = tft;
}

void Screen::init()
{
    tft->initR(INITR_BLACKTAB);
    tft->fillScreen(ST7735_BLACK);
    tft->setRotation(1);
}

void Screen::render()
{
}