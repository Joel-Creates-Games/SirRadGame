#include "Character.h"
#include "GameEngine.h"

Character::Character()
{
	size[0] = 10; size[1] = 10;
	position[0] = 10; position[1] = 10;
	speed = 2;
}
/// <summary>
/// this constructor sets character statistics
/// </summary>
Character::Character(int _size[2], int _position[2], int* _speed, const string& _ImagePath, int _spriteRows)
{
	size[0] = _size[0]; size[1] = _size[1];
	position[0] = _position[0]; position[1] = _position[1];
	speed = *_speed;
	ImagePath = _ImagePath;
	//character_Surface = SDL_CreateRGBSurface(0, GetSizeW(), GetSizeH(), 32, 0, 0, 0, 0xff);
	spriteRows = _spriteRows;

}
/// <summary>
/// this virtual constructor for the virtual class Character
/// </summary>
Character::~Character()
{
	engine->PrintLog("Character Destroyed");
}
/// <summary>
/// This virual Function is the basis of all movement of all characters in the game
/// </summary>
/// <returns></returns>
bool Character::Move()
{
	return false;
}

void Character::Collide(Character* other)
{
}

void Character::FindCollisionZone()
{
	engine->Collider->CalculateHitZone(this);
}

void Character::Init(GameEngine* _engine)
{
	engine = _engine;
	engine->PrintLog(name + " initiated");
	if (ImagePath != "None") {
		//Uint32 colorkey = SDL_MapRGB(character_Surface->format, 0, 0, 0xff);
		//SDL_SetColorKey(character_Surface, SDL_TRUE, colorkey);
		character_Surface = engine->ImageRender.loadSurface(ImagePath);
		Uint32 colorkey = SDL_MapRGB(character_Surface->format, 0, 0, 0);
		SDL_SetColorKey(character_Surface, SDL_TRUE, colorkey);
		image_Texture = SDL_CreateTextureFromSurface(engine->ImageRender.GetRenderer(), character_Surface);
		if (image_Texture != NULL && spriteRows != 0) 
		{
			LoadSprites();
		}
		SDL_FreeSurface(character_Surface);
	}
	engine->allcharacters.push_back(this);
}

void Character::ChangeDirection(int _direction)
{
}

void Character::Animate()
{
	if ((engine->totalTime - lastFrame) <= 250) { return; }
	CurrentSpriteClip = (((currentAnimation - 1) * 4) + currentFrame);
	currentFrame++;
	if (currentFrame == 4) {
		currentFrame = 0;
	}
	lastFrame = engine->totalTime;
}

void Character::LoadSprites()
{
	if (image_Texture == NULL) { engine->PrintLog("ERROR: no texture for spritesheet creation"); return;}
		//int width = engine->ImageRender.loadSurface(ImagePath)->w / 4;
		//int height = engine->ImageRender.loadSurface(ImagePath)->h/spriteRows;
	SDL_Rect printRect;
	for (int i = 0; i < spriteRows; i++)
	{
		for (int o = 0; o < 4; o++)
		{
			printRect.x = GetSizeW() * o;
			printRect.y = GetSizeH() * i;
			printRect.w = GetSizeW();
			printRect.h = GetSizeH();
			SpriteClips.push_back(printRect);
		}
	}
	engine->PrintLog("sprites for " + ImagePath + " loaded");
}
