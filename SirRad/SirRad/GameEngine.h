#ifndef GameEngine_H
#define GameEngine_H

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <SDL_ttf.h>

#include "SDL.h"
#include "Player.h"
#include "ImageRenderer.h"
#include "SoundPlayer.h"
#include "SplashRectangle.h"
#include "SZ_Timer.h"
#include "GameOfLife.h"
#include "ColourGame.h"
#include <SDL_image.h>
#include <SDL_audio.h>
#include "GameWindow.h"
#include "Character.h"
#include "Collision.h"
#include "EnemyContainer.h"

class GameEngine
{
public:
	GameEngine(SDL_Window* window); ///constructor
	~GameEngine(); //destructor
	GameEngine(const GameEngine& copy) = delete;
	GameEngine& operator=(const GameEngine&) = delete;
	void ChangeScore(int change);
	void PrintLog(string text);
	void Splash();
	void GameLoop(); //the main game loop
public:
	vector<Character*> allcharacters;
	vector<EnemyContainer*> enemyContainers;
	SDL_Surface* screenSurface;
	GameWindow GWindow;
	ImageRenderer ImageRender;
	SoundPlayer SoundPlayer;
	Player* SirRad;
	Collision* Collider;
	float totalTime = 0;
private:
	void Step();
	void Input();
	void Update(); //updates values of objects
	void Render(); //renders updated objects 
	//splash screen
	void SplashUpdate();
	void SplashRender();
	//enemies
	void UpdateContainers();
	void RenderContainers();
	//Score
	void DrawText();
	// font from https://www.fontspace.com/category/open-source?p=2
private:
	Character* Background;
	GameOfLife* splashLife;
	TTF_Font* Sans;
	SDL_Color textColour;
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect Message_rect;
	SZ_Timer aTimer;
	SDL_Event event;
	ColourGame* game;
	string textMessage;
	int count = 0;
	int GameScore = 0;
	int splashFrames = 300;
	bool MoveLeft = false;
	bool MoveRight = false;
	bool quit = false;
	bool leftMousePressed = false;
	bool isFullscreen = false;
	bool isLogging = true;
};
#endif

