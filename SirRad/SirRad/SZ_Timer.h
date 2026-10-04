#ifndef aTimerFILE
#define aTimerFILE
#include <iostream>
#include <SDL.h>
// written by oszymanezyk@lincoln.ac.uk
// part of games programming module
class GameEngine;

class SZ_Timer
{
public:
	SZ_Timer();
	SZ_Timer(GameEngine* _engine);
	~SZ_Timer();
	//SDL timer stuff
	void resetTicksTimer(); // resets timer to zero
	int getTicks(); // returns how much time has passed since timer has been reset
private:
	GameEngine* engine;
	int startTicks; // SDL time when the timer started
};
#endif