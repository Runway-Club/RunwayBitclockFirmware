#ifndef NOTIFICATION_SCENE_H
#define NOTIFICATION_SCENE_H

#include "scene.h"
#include "screen_device.h"

class NotificationScene : public Scene
{
protected:
    float rectWidth = 0;
    int waitForClose = 0;

public:
    NotificationScene(ScreenDevice *screen);
    void render(int deltaT);
};

#endif