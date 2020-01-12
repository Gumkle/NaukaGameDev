#include "game.h"

#include <time.h>
#include <conio.h>
#include <iostream>

// It's equal 1000 / FPS, for 30 FPS it's 33.33
#define GAME_SPEED 33.33333

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

    if(currentTime < GAME_SPEED)
    {
        return;
    }

    frameCount++;

    lastTime = clock();
}
