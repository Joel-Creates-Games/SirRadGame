#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "SDL.h"
#include <string>
class GameEngine;

class GameWindow
{
public:
	GameWindow();
	GameWindow(GameEngine* _engine, SDL_Window* _screen);
	~GameWindow();
	SDL_Window* GetScreen() const { return Screen; };
	SDL_Surface* GetWindow() const { return gWindow; };
	int GetMiddleW() const { return Screen_MiddleW; };
	int GetMiddleH() const { return Screen_MiddleH; };
	int GetEighthW() const { return Screen_EighthW; };
	int GetEighthH() const { return Screen_EighthH; };
	int GetHeight() const { return height; }
	int GetWidth() const { return width; }
	int GetFloor() const { return Game_Floor; };
	int GetRampTop() const { return rampTop; };
private:
	SDL_Window* Screen;
	SDL_Surface* gWindow;
	GameEngine* engine;
	int Screen_MiddleW;
	int Screen_MiddleH;
	int Screen_EighthW;
	int Screen_EighthH;
	int Game_Floor;
	int rampTop;
	int height;
	int width;
};
#endif
