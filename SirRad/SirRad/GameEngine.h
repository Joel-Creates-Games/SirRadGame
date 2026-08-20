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
	SDL_Surface* screenSurface;
	GameWindow GWindow;
	ImageRenderer ImageRender;
	SoundPlayer SoundPlayer;
	Player* SirRad;
	GameOfLife* splashLife;
	Collision Collider;
	vector<Character*> allcharacters;
	vector<EnemyContainer*> enemyContainers;
	Character* Background;
	float totalTime = 0;
	void Step();
	void ChangeScore(int change);
	//logging
	void PrintLog(string text);
	bool isLogging = true;
private:
	SZ_Timer aTimer;
	bool quit = false;
	bool leftMousePressed = false;
	bool isFullscreen = false;
	int count = 0;
	int GameScore = 0;
	//SDL_Renderer* renderer;
	SDL_Event event;
	//GameOfLife *Life;
	ColourGame *game;
	void GameLoop(); //the main game loop
	void Input();
	void Update(); //updates values of objects
	void Render(); //renders updated objects 
	//void DrawCharacter(Character* draw); //Draws all characters for the renderer

	////////////Movement Variables
	bool MoveLeft = false;
	bool MoveRight = false;

	//splash screen
	int splashFrames = 300;
	void Splash();
	void SplashUpdate();
	void SplashRender();

	//enemies
	void UpdateContainers();
	void RenderContainers();

	//Score
	TTF_Font* Sans;
	SDL_Color textColour;
	void DrawText();
	string textMessage;
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect Message_rect;
	// font from https://www.fontspace.com/category/open-source?p=2

};
#endif

