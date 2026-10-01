#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <SDL_mixer.h>
#include <SDL_audio.h>
#include <vector>

class GameEngine;
class SoundPlayer
{
public:
	SoundPlayer(GameEngine* _engine);
	~SoundPlayer();
	Mix_Music* MixMusic(std::string location);
	std::vector<Mix_Music*> MusicVector = {};
	std::vector<std::string> MusicLocationVector = {};

private:
	void Init();
	GameEngine* engine;
};
#endif

