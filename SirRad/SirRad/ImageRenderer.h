#ifndef IMAGERENDERER_H
#define IMAGERENDERER_H
#include "SDL.h"
#include <string>
#include "Character.h"

class ImageRenderer
{
public:
	ImageRenderer(SDL_Window* window, GameEngine* _engine);
	~ImageRenderer();
	bool Init();
	SDL_Surface* GetSurface() const { return gScreenSurface; };
	SDL_Renderer* GetRenderer() const { return renderer; };
	SDL_Window* GetWindow() const { return gWindow; };
	SDL_Surface* loadSurface(std::string path);
	void DrawCharacter(Character* draw, SDL_Rect* clip = NULL);
	int GetRendererHeight() const { return rendererHeight; }
	int GetRendererWidth() const { return rendererWidth; }
private:
	SDL_Renderer* renderer;
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
	GameEngine* engine;

	int rendererHeight;
	int rendererWidth;
};
#endif
//reference https://lazyfoo.net/tutorials/SDL/11_clip_rendering_and_sprite_sheets/index.php