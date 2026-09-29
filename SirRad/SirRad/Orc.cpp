#include "Orc.h"
#include "GameEngine.h"
#include "EnemyContainer.h"

class EnemyContainer;

Orc::Orc() : Enemy(size, position, &speed, "Images/OrcSheet.png", 3)
{
	name = "Orc";
}

Orc::~Orc()
{
	parent->PrintLog("Orc destroyed");
}

bool Orc::Move()
{
	if (position[1] > parent->GWindow.GetRampTop() - parent->GWindow.GetEighthH()) 
	{
		position[0] -= speed * direction[0];
		position[1] -= speed * direction[1];
	}
	else 
	{
		currentAnimation = 2;
		ThrowAxe();
	}
	FindCollisionZone();
	CheckBoundaries();
	return false;
}

void Orc::Death()
{
	isSpawned = false;
}

void Orc::Spawn()
{
	speed = 1;
	AxeContainer = parent->enemyContainers[2];
	int side = rand() % 2;
	size[0] = 64;
	size[1] = 64;
	//position[0] = (parent->GWindow.GetWindow()->w * side) + (parent->GWindow.GetEighthW());
	position[1] = (parent->GWindow.GetHeight());
	if (side == 0) 
	{
		position[0] = (parent->GWindow.GetWidth() * side) + (parent->GWindow.GetEighthW() * 0.9);
		direction[0] = 0;
	}
	else 
	{
		position[0] = (parent->GWindow.GetWidth() * side) - (parent->GWindow.GetEighthW() * 0.9);
		direction[0] = 0;
	}
	ChangeDirection(0);
	direction[1] = 1;
	currentAnimation = 1;
	currentFrame = 0;
	isSpawned = true;
	parent->PrintLog("Orc Spawned");
}

void Orc::Collide(Character* other)
{
	if (other->name == "SirRad")
	{
		Death();
	}
}

void Orc::ChangeDirection(int direction)
{
	if (position[0] > parent->GWindow.GetMiddleW()) 
	{
		CharacterFlip = SDL_FLIP_NONE;
	}
	else 
	{
		CharacterFlip = SDL_FLIP_HORIZONTAL;
	}
}

void Orc::ThrowAxe()
{
	if (parent->totalTime - lastThrown > throwSpeed) 
	{
		throwing = true;
		parent->PrintLog("passed this");
		lastThrown = parent->totalTime;
		AxeContainer->Spawn();
		throwing = false;
	}
}
