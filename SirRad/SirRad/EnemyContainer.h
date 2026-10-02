#ifndef ENEMYCONTAINER_H
#define ENEMYCONTAINER_H
#include "Axe.h"
#include "Orc.h"
#include "Fireball.h"
#include <typeinfo>

class GameEngine;
class EnemyContainer
{
public:
	enum EnemyTypes { fireball, orc, axe };
	EnemyContainer(int _count, EnemyTypes enemyType, float _spawnDelay, float _spawnWait, GameEngine* _engine);
	~EnemyContainer();
	EnemyContainer(const EnemyContainer& copy) = delete;
	EnemyContainer& operator=(const EnemyContainer&) = delete;
	void ControlContained();
	void RenderContained();
	void AnimateContained();
	void Spawn();
	const std::vector<Enemy*> GetContainedEnemy() const { return containedEnemy; };
	float GetSpawnWait() const { return spawnWait; };
private:
	void CreateEnemies(int _count, EnemyTypes enemyType);
	GameEngine* engine;
private:
	std::vector<Enemy*> containedEnemy;
	float lastSpawn = 0;
	float spawnDelay;
	float spawnWait;
};
#endif
