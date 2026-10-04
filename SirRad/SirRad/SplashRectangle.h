#ifndef SPLASHRECTANGLE_H
#define SPLASHRECTANGLE_H
#include "Character.h"
class GameEngine;

class SplashRectangle :
    public Character
{
public:
    SplashRectangle();
    SplashRectangle(int _size[2], int _position[2], int* _speed, string ImagePath);
    ~SplashRectangle();
    void SetPosition(int _position[2]);
    void SetSize(int _size[2]);
private:
    bool Move() override;
private:
    string name = "box";
};
#endif // !SPLASHRECTANGLE_H
