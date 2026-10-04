#ifndef ORC_H
#define ORC_H
#include "Enemy.h"

class EnemyContainer;

class Orc :
    public Enemy
{
public:
    Orc();
    ~Orc();
private:
    bool Move() override;
    void Death() override;
    void Spawn() override;
    void Collide(Character* other) override;
    void ChangeDirection(int direction) override;
    void ThrowAxe();
private:
    float lastThrown = 0;
    float throwSpeed = 1800;
    EnemyContainer* AxeContainer;
};
#endif