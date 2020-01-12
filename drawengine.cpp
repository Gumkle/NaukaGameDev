#include "drawengine.h"

#include <windows.h>
#include <iostream>


DrawEngine::DrawEngine(int xSize, int ySize)
{
    screenWidth = xSize;
    screenHeight = ySize;

    cursorVisibility(false);
}

DrawEngine::~DrawEngine()
{
    cursorVisibility(true);
}

int DrawEngine::createSprite(int index, char c)
{
    if(index < 16 && index >= 0)
    {
        spriteImage[index] = c;
        return index;
    }

    return -1;
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
    //go to the correct position
    gotoxy(posx, posy);

    //draw a sprite by cout
    std::cout << spriteImage[index];
}

void DrawEngine::eraseSprite(int posx, int posy)
{
    gotoxy(posx , posy);
    std::cout << " ";
}

void DrawEngine::gotoxy(int x, int y)
{
    HANDLE output_handle;
    COORD pos;

    pos.X = x;
    pos.Y = y;

    output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(output_handle, pos);

}

void DrawEngine::cursorVisibility(bool visibility)
{
    HANDLE output_handle;
    CONSOLE_CURSOR_INFO cci_info;

    cci_info.dwSize = 1;
    cci_info.bVisible = visibility;

    output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorInfo(output_handle, &cci_info);
}
