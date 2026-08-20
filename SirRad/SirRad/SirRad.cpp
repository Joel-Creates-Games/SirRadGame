// SirRad!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "SDL.h"
#include "GameEngine.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

GameEngine* globalGame = nullptr;

void MainLoop()
{
    if (globalGame) {
        globalGame->Step();
    }
}
#endif

int main(int argc, char* argv[])
{
    SDL_Window* window = SDL_CreateWindow("Sir Rad!", 100, 100, 800, 450, SDL_WINDOW_SHOWN);

#ifdef __EMSCRIPTEN__
    globalGame = new GameEngine(window);
    // fps = 0 delegates to browser's requestAnimationFrame
    // 1 simulates infinite loop and prevents main() from unwinding
    emscripten_set_main_loop(MainLoop, 60, 1);
#else
    GameEngine theGame(window);
    // Desktop loop here...
    SDL_Quit();
#endif

    return 0;
}