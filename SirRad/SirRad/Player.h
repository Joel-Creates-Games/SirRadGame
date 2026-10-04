#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Vector2D.h"
class Player :
    public Character
{
public:
    Player();//default Constructor
    Player(int _size [2], int _position[2], int* _speed, string _ImagePath);
    ~Player();
    bool Move() override;
    void Movement(bool moveLeft, bool moveRight);
    void ChangeDirection(int _direction) override;
    void Animate() override;
    void DoTrick(int type);
    bool GetPerformingtrick() const { return performingTrick; }
    void SetPerformingTrick(bool change) { performingTrick = change; }
private:
    void ChangeMoveZone(int newZone);
    void Collide(Character* other) override;
    void SetRotation();
private:
    Vector2D velocity;
    int trickType = 0;
    int MoveZone;
    int EntrySpeed;
    bool performingTrick = false;
};
#endif

