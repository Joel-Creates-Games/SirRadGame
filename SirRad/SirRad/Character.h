#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

#include <vector>
#include <string>
#include <SDL_image.h>

class GameEngine;

class Character
{
public:
	Character();//default Constructor
	Character(int _size[2], int _position[2], int* _speed, string _ImagePath, int _spriteRows = NULL);
	virtual ~Character();
	virtual bool Move();
	int GetSizeW() const { return size[0]; }
	int GetSizeH() const { return size[1]; }
	int GetPosX() const { return position[0]; }
	int GetPosY() const { return position[1]; }
	int collisionZone[2];
	virtual void Collide(Character* other);
	void FindCollisionZone();
	SDL_Surface* GetSurface() const { return character_Surface; }
	virtual void Init(GameEngine* _engine);
	const string GetImagePath() const { return ImagePath; }
	GameEngine* engine;
	SDL_Surface* character_Surface;
	SDL_Texture* image_Texture;
	virtual void ChangeDirection(int _direction);
	bool GetSpawned() const { return isSpawned; };

	///FOR SPRITES
	int spriteRows = 1;
	int CurrentSpriteClip = 0;
	vector<SDL_Rect> SpriteClips;
	void LoadSprites();
	SDL_RendererFlip CharacterFlip = SDL_FLIP_NONE;
	double Rotation = 0;

	//For Animations
	virtual void Animate();
	int currentAnimation = 1;
	int currentFrame = 0;
	float lastFrame = 0;


	///DETAILS
	string name;

protected:
	int size [2]; //two numbers relating to the size w,h
	int position [2]; //two numbers relating to position x,y
	int speed; //player movement
	int health;
	float speedUp;
	vector<float> direction;
	string ImagePath;
	bool isSpawned = false;
};
#endif
