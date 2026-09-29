#include "EnemyContainer.h"
#include "GameEngine.h"
#include "Fireball.h"
#include "Orc.h"
#include "Axe.h"

EnemyContainer::EnemyContainer(int _count, EnemyTypes enemyType, float _spawnDelay, float _spawnWait, GameEngine* _parent)
{
	parent = _parent;
	parent->PrintLog("Enemy Container created");
	//parent->enemyContainers.push_back(this);
	CreateEnemies(_count, enemyType);
	spawnDelay = _spawnDelay * 1000;
	spawnWait = _spawnWait * 1000;
}

EnemyContainer::~EnemyContainer()
{
	int length = containedEnemy.size();
	for (int i = 0; i < length; i++)
	{
		delete containedEnemy[i];
	}
	parent->PrintLog("EnemyContainer Unloaded");
}

void EnemyContainer::ControlContained()
{
	for (int i = 0; i < containedEnemy.size(); i++)
	{
		if (containedEnemy[i]->GetSpawned()) {
			containedEnemy[i]->Move();
		}
	}
}

void EnemyContainer::RenderContained()
{
	for (int i = 0; i < containedEnemy.size(); i++)
	{
		if (containedEnemy[i]->GetSpawned()) {
			parent->ImageRender.DrawCharacter(containedEnemy[i], &containedEnemy[i]->SpriteClips[containedEnemy[i]->CurrentSpriteClip]);
		}
	}
}

void EnemyContainer::AnimateContained()
{
	for (int i = 0; i < containedEnemy.size(); i++)
	{
		if (containedEnemy[i]->GetSpawned()) {
			containedEnemy[i]->Animate();
		}
	}
}

void EnemyContainer::Spawn()
{
	if ((parent->totalTime > spawnDelay) && ((parent->totalTime - lastSpawn) > spawnWait) || spawnWait == -1000) 
	{
		for (int i = 0; i < containedEnemy.size(); i++)
		{
			if (!containedEnemy[i]->GetSpawned())
			{
				containedEnemy[i]->Spawn();
				lastSpawn = parent->totalTime;
				break;
			}
		}
	}
}

// TODO: Refactor to use a Texture Cache (Flyweight pattern).
// Currently, every enemy instance loads its own duplicate SDL_Texture into VRAM.
// In the future, ImageRenderer should maintain a std::map<string, SDL_Texture*> 
// to load each image once and share the pointer across all objects in this pool.

void EnemyContainer::CreateEnemies(int _count, EnemyTypes enemyType)
{
	for (int i = 0; i < _count; i++)
	{
		Enemy* newEnemy{};
		switch (enemyType)
		{
		case fireball:
			newEnemy =  new Fireball();
			break;
		case orc:
			newEnemy = new Orc();
			break;
		case axe:
			newEnemy = new Axe();
			break;
		default:
			parent->PrintLog("ERROR: not an enemy type");
			break;
		}
		newEnemy->Init(parent);

		containedEnemy.push_back(newEnemy);
		parent->PrintLog(newEnemy->name + " is " + to_string(containedEnemy.size()) + " in container");
	}
}
