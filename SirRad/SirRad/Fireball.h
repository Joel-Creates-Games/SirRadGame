#ifndef FIREBALL_H
#define FIREBALL_H
#include "Enemy.h"
class Fireball :
    public Enemy
{
public:
    Fireball();
    ~Fireball();
private:
    bool Move() override;
    void Death() override;
    void Spawn() override;
    void Attack() override;
    void Damage() override;
    void Collide(Character* other) override;
    void Animate() override;
private:
    bool hit = false;
};
#endif

