#include "ImageRenderer.h"
#include "GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

ImageRenderer::ImageRenderer(SDL_Window* window, GameEngine* _parent)
{
    parent = _parent;
    parent->PrintLog("renderer created");
    gWindow = window;
    renderer = SDL_CreateRenderer(gWindow, -1, 0);

    Init();
}

ImageRenderer::~ImageRenderer()
{
    parent->PrintLog("renderer Unloaded");
}

bool ImageRenderer::Init()
{
    string error;

    //Initialize SDL changed later on to explicitly be created before the window initialisation in
    // main to avoid confict on other machines
    //if (SDL_Init(SDL_INIT_VIDEO) < 0)
    //{
    //    error = SDL_GetError();
    //    parent->PrintLog("SDL could not initialize Renderer! SDL Error: " + error);
    //    success = false;
    //}
    if (renderer == NULL) {
        error = SDL_GetError();
        parent->PrintLog("Renderer was not created! SDL Error: " + error);
        return false;
    }
    //check window created
    if (gWindow == NULL)
    {
        error = SDL_GetError();
        parent->PrintLog("Window was not created! SDL Error: " + error);
        return false;
    }
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        error = IMG_GetError();
        parent->PrintLog("SDL_image could not initialize! SDL_image Error: " + error);
        return false;
    }
    //Get window surface
    parent->PrintLog("SDL_image was initialized! \n");
    //gScreenSurface = SDL_GetWindowSurface(gWindow);
    parent->PrintLog("renderer initialisation was successful");
    SDL_GetRendererOutputSize(renderer, &rendererWidth, &rendererHeight);

    return true;
}


SDL_Surface* ImageRenderer::loadSurface(string path)
{
    //The final optimized image //post uni joel realised this function was acting strange
    // I was loading the SDL_Surface and converting it to SDL_ConvertSurface
    //SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    //when I submitted this in uni, I used blit surface which meant drawing twice, I removed it here
    // an example of returning to code an realising past mistakes
    //SDL_BlitSurface(loadedSurface, NULL, loadedSurface, NULL);
    if (loadedSurface == NULL)
    {
        parent->PrintLog("Unable to load image " + path + "! SDL_image Error: " + IMG_GetError());
        return NULL;
    }
    ////Convert surface to screen format
    // I realised I was using the SDL rendering pipeline and screen surface, I used the rendering pipeline instead
    // so that I didn't load the image twice but also to push the image loading to the gpu, this was done post university
    //optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
    //if (optimizedSurface == NULL)
    //{
    //    parent->PrintLog("Unable to optimize image " + path + "! SDL Error: " + SDL_GetError());
    //}
    parent->PrintLog("surface " + path + " was loaded");

    return loadedSurface;
}

void ImageRenderer::DrawCharacter(Character* draw, SDL_Rect* clip)
{
    SDL_Rect rect = { draw->GetPosX() - (draw->GetSizeW() / 2), draw->GetPosY() - (draw->GetSizeH() / 2), draw->GetSizeW(), draw->GetSizeH() };
    //SDL_RenderFillRect(renderer, &rect);
    //SDL_RenderDrawRect(renderer, &rect);
    if (draw->GetImagePath() == "None") { return; }
    if (clip != NULL) 
    {
        rect.w = clip->w;
        rect.h = clip->h;
    }
    //SDL_SetTextureBlendMode(draw->image_Texture, SDL_BLENDMODE_BLEND);
    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderCopyEx(renderer, draw->image_Texture, clip, &rect, draw->Rotation, NULL, draw->CharacterFlip);
}

