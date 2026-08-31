#include "Collision.h"
#include "GameEngine.h"

Collision::Collision()
{
}

Collision::~Collision()
{
	parent->PrintLog("Character Unloaded");
}

void Collision::Init(GameEngine* _parent)
{
	parent = _parent;
	parent->PrintLog("Collision initiated");
	for (int i = 0; i < hitZoneDepth; i++)
	{
		hitZonesX.push_back((parent->GWindow.GetWindow()->w / hitZoneDepth) * i);
	}
	for (int i = 0; i < hitZoneDepth; i++)
	{
		hitZonesY.push_back((parent->GWindow.GetWindow()->h / hitZoneDepth) * i);
	}
}

void Collision::CalculateHitZone(Character* thisChar)
{
	for (int i = 0; i < hitZoneDepth; i++)
	{
		if (thisChar->GetPosX() > hitZonesX[i])
		{
			thisChar->collisionZone[0] = i;
		}
	}
	for (int i = 0; i < hitZoneDepth; i++)
	{
		if (thisChar->GetPosY() > hitZonesY[i])
		{
			thisChar->collisionZone[1] = i;
		}
	}
}

void Collision::CheckCollision(Character* thisChar)
{
	int thisLX = thisChar->GetPosX();
	int thisRX = thisChar->GetPosX() + thisChar->GetSizeW();
	int thisTY = thisChar->GetPosY();
	int thisBY = thisChar->GetPosY() + thisChar->GetSizeH();

	for (size_t i = 0; i < parent->allcharacters.size(); i++)
	{
		Character* other = parent->allcharacters[i];

		// Guard clauses to prevent deep nesting
		if (other == thisChar || !other->GetSpawned()) continue;
		if (other->collisionZone[0] != thisChar->collisionZone[0] ||
			other->collisionZone[1] != thisChar->collisionZone[1]) continue;

		int listLX = other->GetPosX() - other->GetSizeW() / 2;
		int listRX = other->GetPosX() + other->GetSizeW() / 2;
		int listTY = other->GetPosY() - other->GetSizeH() / 2;
		int listBY = other->GetPosY() + other->GetSizeH() / 2;

		// AABB Collision check
		if (thisRX > listLX && thisLX < listRX && thisTY < listBY && thisBY > listTY)
		{
			thisChar->Collide(other);
		}
	}
}
