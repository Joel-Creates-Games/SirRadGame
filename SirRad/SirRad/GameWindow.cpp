#include "GameWindow.h"
#include "GameEngine.h"

GameWindow::GameWindow()
{
}

GameWindow::GameWindow(GameEngine* _engine, SDL_Window* _screen)
{
	Screen = _screen;
	engine = _engine;
	engine->PrintLog("Window stats calculated for functions");
	//gWindow = window;
	SDL_GetWindowSize(Screen, &width, &height);
	Screen_MiddleW = width / 2;
	Screen_MiddleH = height / 2;
	Screen_EighthW = width / 8;
	Screen_EighthH = height / 8;
	Game_Floor = height - Screen_EighthH;
	rampTop = Game_Floor - (height/3);
}

GameWindow::~GameWindow()
{
	engine->PrintLog("GameWindow Unloaded");
}
