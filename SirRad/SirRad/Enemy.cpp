#include "Enemy.h"
#include "GameEngine.h"

Enemy::Enemy(int _size[2], int _position[2], int* _speed, string _ImagePath, int _spriteRows) : Character(_size, _position, _speed, _ImagePath, _spriteRows)
{

}

Enemy::~Enemy()
{
	parent->PrintLog("Enemy Unloaded");
}

void Enemy::Death()
{
}

void Enemy::Spawn()
{
}

void Enemy::Attack()
{
}

void Enemy::Damage()
{
}

bool Enemy::DetectCollision()
{

	return false;
}

void Enemy::CheckBoundaries()
{
	if ((position[0] < 0 - size[0]) || (position[0] > (parent->GWindow.GetWidth()) + size[0])) 
	{
		Death();
	}
	if ((position[1] <= 0) || (position[1] > (parent->GWindow.GetHeight() + size[1])))
	{
		Death();
	}
}
