#include "Enemy.h"
#include "GameEngine.h"

Enemy::Enemy(int _size[2], int _position[2], int* _speed, string _ImagePath, int _spriteRows) : Character(_size, _position, _speed, _ImagePath, _spriteRows)
{

}
/// <summary>
/// this function wasn't virtual when I submitted it at uni
/// this destructor actually needs to be virtual because when deleting the child objects the coliper must check
/// to destroy something larger
/// </summary>
Enemy::~Enemy()
{
	engine->PrintLog("Enemy Unloaded");
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
	if ((position[0] < 0 - size[0]) || (position[0] > (engine->GWindow.GetWidth()) + size[0]))
	{
		Death();
	}
	if ((position[1] <= 0) || (position[1] > (engine->GWindow.GetHeight() + size[1])))
	{
		Death();
	}
}
