#include "game.h"

#include <time.h>
#include <conio.h>
#include <iostream>

Game::Game()
{

}

bool Game::run()
{
    char key = ' ';

    startTime = clock();
    lastTime = 0;

    while(key != 'q')
    {
        while(!getInput(&key))
        {
            timerUpdate();
        }

        std::cout << "Wcisnieto: " << key <<"\n";
    }

    std::cout << frameCount / ((clock() - startTime) / 1000) << " FPS\n";
    std::cout << "Game Over\n";

    return true;
}

bool Game::getInput(char *c)
{
    if(kbhit())
    {
        *c = getch();
        return true;
    }

    return false;
}

void Game::timerUpdate()
{
    double currentTime = clock() - lastTime;

    if(currentTime < 33)
    {
        return;
    }

    frameCount++;

    lastTime = clock();
}
