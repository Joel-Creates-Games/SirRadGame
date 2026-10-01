#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
class Enemy :
    public Character
{
public:
    Enemy(int _size[2], int _position[2], int* _speed, string _ImagePath, int _spriteRows);
    //changed destructor to virtual to avoid memory leak
    virtual ~Enemy();
    virtual void Death();
    virtual void Spawn();
    virtual void Attack();
    virtual void Damage();
    virtual bool DetectCollision();
    bool GetThrowing() const { return throwing; };
    const vector<float>& GetDirection() const { return direction; };
protected:
    void CheckBoundaries();
    vector<float> direction = { 0, 0 };
    bool throwing = false;
};
#endif

