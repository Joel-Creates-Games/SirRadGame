#ifndef COLLISION_H
#define COLLISION_H
#include <vector>
#include "Character.h"

class GameEngine;

class Collision
{
public:
	Collision();
	~Collision();
	void Init(GameEngine* _engine);
	void CalculateHitZone(Character* thisChar);
	void CheckCollision(Character* thisChar);
	void UpdateGrid();
private:
	GameEngine* engine;
	std::vector<int> hitZonesX;
	std::vector<int> hitZonesY;
	std::vector<std::vector<Character*>> spatialGrid;
	int hitZoneDepth = 3;
	int zoneWidth;
	int zoneHeight;
};
#endif
