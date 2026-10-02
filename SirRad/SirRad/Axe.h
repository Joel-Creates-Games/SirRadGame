#ifndef AXE_H
#define AXE_H
#include "Enemy.h"

class EnemyContainer;

class Axe :
    public Enemy
{
public:
    Axe();
    ~Axe();
    bool Move() override;
    void Death() override;
    void Spawn() override;
    void Collide(Character* other) override;
private:
    EnemyContainer* OrcContainer;
    bool axeHit = false;
};
#endif
