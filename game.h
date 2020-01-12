#ifndef GAME_H
#define GAME_H

#include "drawengine.h"

class Game
{
public:
    Game();
    bool run(void);

protected:
    bool getInput(char* c);
    void timerUpdate(void);

private:
    double frameCount;
    double startTime;
    double lastTime;

    DrawEngine drawArea;
};

#endif // GAME_H
