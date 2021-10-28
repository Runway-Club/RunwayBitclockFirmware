#include "notification_scene.h"

NotificationScene::NotificationScene(ScreenDevice *screen) : Scene(screen)
{
}

void NotificationScene::render(int deltaT)
{
    // Draw text
    // this->drawText("Runway Bitclock", ST7735_ORANGE, 0, 0, 1);
    if (waitForClose < 5000)
    {
        rectWidth += 1 * deltaT * 0.03;
    }

    if (rectWidth > 50)
    {
        rectWidth = 50;
        waitForClose += deltaT;
    }

    if (waitForClose >= 5000)
    {
        this->screen->getDevice()->fillRect(0, -10, this->screen->getDevice()->width(), 50, ST7735_BLACK);
        rectWidth -= 1 * deltaT * 0.03;
        if (rectWidth < 0)
        {
            rectWidth = 0;
            waitForClose = 0;
        }
    }
    if (waitForClose > 5000 || waitForClose == 0)
    {
        //0x0503
        this->screen->getDevice()->fillRoundRect(0, -10, this->screen->getDevice()->width(), rectWidth, 10, ST7735_WHITE);
    }
    if (waitForClose < 5000)
    {
        this->drawText("Push notification: Runway Bitclock hello everybody from the world", ST7735_BLACK, 5, 5, 1);
    }
}