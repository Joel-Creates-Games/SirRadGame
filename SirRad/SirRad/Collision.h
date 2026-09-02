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
	void Init(GameEngine* _parent);
	GameEngine* parent;
	void CalculateHitZone(Character* thisChar);
	void CheckCollision(Character* thisChar);
	void UpdateGrid();
private:
	int hitZoneDepth = 3;
	std::vector<int> hitZonesX;
	std::vector<int> hitZonesY;
	std::vector<std::vector<Character*>> spatialGrid;
};
#endif
