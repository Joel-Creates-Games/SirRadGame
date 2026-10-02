#include "Collision.h"
#include "GameEngine.h"

Collision::Collision()
{
}

Collision::~Collision()
{
	engine->PrintLog("Character Unloaded");
}

void Collision::Init(GameEngine* _engine)
{
	engine = _engine;
	engine->PrintLog("Collision initiated");
	spatialGrid.resize(hitZoneDepth * hitZoneDepth);
	zoneWidth = engine->GWindow.GetWidth() / hitZoneDepth;
	zoneHeight = engine->GWindow.GetHeight() / hitZoneDepth;
}

void Collision::CalculateHitZone(Character* thisChar)
{

	int gridX = thisChar->GetPosX() / zoneWidth;
	int gridY = thisChar->GetPosY() / zoneHeight;

	if (gridX < 0) gridX = 0;
	if (gridX >= hitZoneDepth) gridX = hitZoneDepth - 1;

	if (gridY < 0) gridY = 0;
	if (gridY >= hitZoneDepth) gridY = hitZoneDepth - 1;

	thisChar->collisionZone[0] = gridX;
	thisChar->collisionZone[1] = gridY;
}

void Collision::UpdateGrid()
{
	for (size_t i = 0; i < spatialGrid.size(); i++) {
		spatialGrid[i].clear();
	}

	for (size_t i = 0; i < engine->allcharacters.size(); i++) {
		Character* c = engine->allcharacters[i];
		if (!c->GetSpawned()) continue;

		CalculateHitZone(c);
		///flattening a 2d grid to a 1d array index for cache locality
		int bucketIndex = c->collisionZone[0] + (c->collisionZone[1] * hitZoneDepth);

		spatialGrid[bucketIndex].push_back(c);
	}
}

void Collision::CheckCollision(Character* thisChar)
{
	int bucketIndex = thisChar->collisionZone[0] + (thisChar->collisionZone[1] * hitZoneDepth);

	std::vector<Character*>& localZone = spatialGrid[bucketIndex];

	int thisLX = thisChar->GetPosX();
	int thisRX = thisChar->GetPosX() + thisChar->GetSizeW();
	int thisTY = thisChar->GetPosY();
	int thisBY = thisChar->GetPosY() + thisChar->GetSizeH();

	for (size_t i = 0; i < localZone.size(); i++)
	{
		Character* other = localZone[i];

		if (other == thisChar) continue;
		int listLX = other->GetPosX();
		int listRX = other->GetPosX() + other->GetSizeW();
		int listTY = other->GetPosY();
		int listBY = other->GetPosY() + other->GetSizeH();

		if (thisRX > listLX && thisLX < listRX && thisTY < listBY && thisBY > listTY)
		{
			thisChar->Collide(other);
		}
	}
}