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
    Character();
    Character(int _size[2], int _position[2], int* _speed, const string& _ImagePath, int _spriteRows = NULL);
    virtual ~Character();

    virtual void Init(GameEngine* _engine);
    virtual bool Move();
    virtual void Collide(Character* other);
    virtual void ChangeDirection(int _direction);
    virtual void Animate();

    void FindCollisionZone();
    void LoadSprites();

    int GetSizeW() const { return size[0]; }
    int GetSizeH() const { return size[1]; }
    int GetPosX() const { return position[0]; }
    int GetPosY() const { return position[1]; }
    bool GetSpawned() const { return isSpawned; }
    SDL_Surface* GetSurface() const { return character_Surface; }
    const string& GetImagePath() const { return ImagePath; }

public:
    string name;                     
    vector<SDL_Rect> SpriteClips;    

    GameEngine* engine;              
    SDL_Surface* character_Surface;  
    SDL_Texture* image_Texture;      
    double Rotation = 0;             
    int collisionZone[2];            

    SDL_RendererFlip CharacterFlip = SDL_FLIP_NONE; 
    int spriteRows = 1;               
    int CurrentSpriteClip = 0;        
    int currentAnimation = 1;         
    int currentFrame = 0;             
    float lastFrame = 0;              

protected:
   
    string ImagePath;                  
    vector<float> direction;           

    int size[2];                       
    int position[2];                   

    int speed;                         
    int health;                        
    float speedUp;                     

    bool isSpawned = false;            
};
#endif
