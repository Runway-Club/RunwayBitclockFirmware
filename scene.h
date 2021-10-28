#ifndef SCENE_H
#define SCENE_H

#include "screen_device.h"

class Scene
{
protected:
    ScreenDevice *screen;

public:
    explicit Scene(ScreenDevice *screen);
    void virtual render(int deltaT) = 0;
    void drawText(char *text, uint16_t color, int x, int y, int textSize);
};

#endif