#ifndef COLOURGAME_H
#define COLOURGAME_H
#include <chrono>
#include "SDL.h"
#include "SZ_Timer.h"
#include "SplashRectangle.h"
class ColourGame
{
public:
	ColourGame();
	ColourGame(SDL_Renderer* _renderer);
	~ColourGame();
	ColourGame& Create(SDL_Renderer* _renderer);
	enum colour { Red, Orange, Yellow, Green, Blue, White, Count };
private:
	void StartGame();
	bool NextColour();
	void SetColour(colour colour);
	void RecieveInput(colour answer);
	colour GenerateNewColour();
	colour GetAnswer();
	colour GetQuestion();
private:
	SplashRectangle rect;
	SplashRectangle bar;
	SplashRectangle barFil;
	colour question;
	colour answer;
	SDL_Renderer* renderer;
	SZ_Timer aTimer;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	int score;
	int length = 0;
	int duration = 15;
};

#endif