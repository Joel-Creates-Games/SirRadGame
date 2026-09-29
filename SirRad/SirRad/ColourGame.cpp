#include "ColourGame.h"
#include <iostream>

ColourGame::ColourGame()
{
	//StartGame();
}

ColourGame::ColourGame(SDL_Renderer* _renderer)
{
	renderer = _renderer;
	int speed = 0;
	int size[2] = { (100), 100 }; int pos[2] = { 100, 100 };
	rect = *(new SplashRectangle(size, pos, &speed, "None"));
	size[0] = 450; size[1] = 30;
	pos[0] = 0; pos[1] = 0;
	bar = *(new SplashRectangle(size, pos, &speed, "None"));
	size[0] = 0; size[1] = 30;
	pos[0] = 0; pos[1] = 0;
	barFil = *(new SplashRectangle(size, pos, &speed, "None"));
	StartGame();
}

ColourGame::~ColourGame()
{

}

ColourGame& ColourGame::Create(SDL_Renderer* _renderer)
{
	return *(new ColourGame(_renderer));
}

void ColourGame::StartGame()
{
	start = std::chrono::system_clock::now();
	colour newColour = GenerateNewColour();
	SetColour(newColour);
	question = newColour;
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
}

void ColourGame::RecieveInput(colour _answer)
{
	answer = _answer;
	if (answer == question) {
		score++;
	}
}

bool ColourGame::NextColour()
{
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	if (elapsed_seconds.count() <= 2) { return false; }
	if (length == duration) {
		std::cout << "your score is: " << score << endl;
		SDL_Quit();
		return true;
	}
	length++;
	int size[2] = {length * 30, 30};
	barFil.SetSize(size);
	StartGame();
}

void ColourGame::SetColour(colour colour)
{
	switch (colour)
	{
	case ColourGame::Red:
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		break;
	case ColourGame::Orange:
		SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
		break;
	case ColourGame::Yellow:
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		break;
	case ColourGame::Green:
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		break;
	case ColourGame::Blue:
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		break;
	case ColourGame::White:
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		break;
	case ColourGame::Count:
		break;
	default:
		break;
	}
}

ColourGame::colour ColourGame::GenerateNewColour()
{
	int choice = rand() % ColourGame::Count;
	if (colour(choice) == question) {
		return GenerateNewColour();
	}
	return colour(choice);
}

ColourGame::colour ColourGame::GetAnswer()
{
	return answer;
}

ColourGame::colour ColourGame::GetQuestion()
{
	return question;
}
