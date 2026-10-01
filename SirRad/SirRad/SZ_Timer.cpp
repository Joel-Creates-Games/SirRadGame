#include "SZ_Timer.h"
#include "GameEngine.h"
SZ_Timer::SZ_Timer()
{
}
SZ_Timer::SZ_Timer(GameEngine* _engine)
{
	engine = _engine;
	engine->PrintLog("SZ_Timer was created, thanks Olivier!");
	startTicks = 0;
}
SZ_Timer::~SZ_Timer()
{
	engine->PrintLog("SZ_Timer Unloaded");
}
;
void SZ_Timer::resetTicksTimer()
{
	startTicks = SDL_GetTicks(); // numbers of milliseconds since start of SDL program
	//printf("timer started! %i \n", startTicks);
}
int SZ_Timer::getTicks()
{
	//printf("getTicks! %i \n", SDL_GetTicks() - startTicks);
	return (SDL_GetTicks() - startTicks); //Return the current time minus the start time
}