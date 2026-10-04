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
	void AddMusic(std::string location);
	const std::vector<Mix_Music*> GetMusicVector() const { return MusicVector; }

private:
	void Init();
	void SetMusicVector(std::string mix) { MusicVector.push_back(MixMusic(mix)); }
private:
	std::vector<Mix_Music*> MusicVector = {};
	GameEngine* engine;
};
#endif

