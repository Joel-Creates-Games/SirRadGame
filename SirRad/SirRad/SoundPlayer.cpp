#include "SoundPlayer.h"
#include "GameEngine.h"

SoundPlayer::SoundPlayer(GameEngine* _parent) 
{
    parent = _parent;
    parent->PrintLog("Sound Player Created");
	Init();
}

SoundPlayer::~SoundPlayer()
{
    parent->PrintLog("Sound Player Unloaded");
}

Mix_Music* SoundPlayer::MixMusic(std::string location)
{
    string error;
    Mix_Music* loadSound = Mix_LoadMUS(location.c_str());
    if (loadSound == NULL)
    {
        error = Mix_GetError();
        parent->PrintLog("Failed to load beat music! SDL_mixer Error: " + error);
    }
    return loadSound;
}

void SoundPlayer::Init()
{
    string error;
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        error = SDL_GetError();
        parent->PrintLog("SDL could not initialize SoundPlayer! SDL Error: " + error);
        return;
    }
    //Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        error = Mix_GetError();
        parent->PrintLog("SDL_mixer could not initialize! SDL_mixer Error: " + error);
        return;
    }
    parent->PrintLog("Sound player initialisation was successful");
}
//reference https://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php#:~:text=To%20initialize%20SDL_mixer%20we%20need,we're%20using%20the%20default.
