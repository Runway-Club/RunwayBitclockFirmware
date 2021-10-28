#ifndef FINANCE_SCENE_H
#define FINANCE_SCENE_H

#include "scene.h"

class FinanceScene : public Scene
{
public:
    FinanceScene(ScreenDevice *screen);
    void render(int deltaT);
};

#endif