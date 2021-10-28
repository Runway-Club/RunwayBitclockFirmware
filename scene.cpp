#include "scene.h"

Scene::Scene(ScreenDevice *screenDevice)
{
    this->screen = screenDevice;
}

void Scene::drawText(char *text, uint16_t color, int x, int y, int textSize)
{
    this->screen->getDevice()->setCursor(x, y);
    this->screen->getDevice()->setTextColor(color);
    this->screen->getDevice()->setTextSize(textSize);
    this->screen->getDevice()->setTextWrap(true);
    this->screen->getDevice()->print(text);
}