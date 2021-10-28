#include "finance_scene.h"

#include <Fonts/FreeSans9pt7b.h>
#include <string>

using namespace std;

FinanceScene::FinanceScene(ScreenDevice *screen) : Scene(screen)
{
}

void FinanceScene::render(int deltaT)
{
    float centerX = screen->getDevice()->width() / 2.0;

    screen->getDevice()->fillRoundRect(centerX - 40, -5, 80, 10, 10, 0x0600);

    int16_t x, y;
    uint64_t w, h;
    String str = "CAKE/USDT";
    // screen->getDevice()->getTextBounds(str, 0, 0, &x, &y, &w, &h);
    drawText("CAKE/USDT", 0xfea3, centerX - (str.length() * 11) / 2.0, 15, 2);
    drawText("18.234", 0xfea3, centerX - (6 * 25) / 2.0, 45, 4);
}