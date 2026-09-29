#include "Axe.h"
#include "GameEngine.h"
#include "EnemyContainer.h"

Axe::Axe() : Enemy(size, position, &speed, "Images/AxeSheet.png", 1)
{
	name = "Axe";
	size[0] = 32;
	size[1] = 32;
}

Axe::~Axe()
{
	parent->PrintLog("Axe Destroyed");
}

bool Axe::Move()
{
	position[0] -= direction[0] * speed;
	position[1] -= direction[1] * speed;
	direction[1] -= 0.05f;
	FindCollisionZone();
	CheckBoundaries();
	return false;
}

void Axe::Death()
{
	isSpawned = false;
}

void Axe::Spawn()
{
	speed = 1;
	OrcContainer = parent->enemyContainers[1];
	for (int i = 0; i < OrcContainer->GetContainedEnemy().size(); i++)
	{
		if (OrcContainer->GetContainedEnemy()[i]->GetThrowing())
		{
			position[0] = OrcContainer->GetContainedEnemy()[i]->GetPosX();
			position[1] = OrcContainer->GetContainedEnemy()[i]->GetPosY();
			if (OrcContainer->GetContainedEnemy()[i]->GetPosX() < parent->GWindow.GetMiddleW())
			{
				direction[0] = -1;
			}
			else 
			{
				direction[0] = 1;
			}
			direction[1] = 3;
			axeHit = false;
			isSpawned = true;
			parent->PrintLog("Axe Spawned");
			break;
		}
	}
}

void Axe::Collide(Character* other)
{
	if (!axeHit) 
	{
		if (other->name == "SirRad")
		{
			axeHit = true;
			if (parent->SirRad->performingTrick) 
			{
				parent->PrintLog("dodged with trick! + 500 score!");
				parent->ChangeScore(500);
			}
			else 
			{
				parent->PrintLog("Axe Hit! - 300 score!");
				parent->ChangeScore(-300);
				Death();
			}
		}
	}
}
