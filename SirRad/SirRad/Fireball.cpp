#include "Fireball.h"
#include "GameEngine.h"

Fireball::Fireball() : Enemy(size, position, &speed, "Images/FireballSheet.png", 2)
{
	name = "Fireball";
	size[0] = 32;
	size[1] = 32;
}

Fireball::~Fireball()
{
	parent->PrintLog("Fireball Destroyed");
}

bool Fireball::Move()
{
	position[0] -= speed * direction[0];
	position[1] -= speed * direction[1];
	FindCollisionZone();
	CheckBoundaries();
	return false;
}

void Fireball::Death()
{
	isSpawned = false;
}

void Fireball::Spawn()
{
	speed = 5;
	int side = rand() % 2;
	position[0] = (parent->GWindow.GetWidth() * side) - (size[0] * side);
	position[1] = (rand() % parent->GWindow.GetHeight());
	direction[0] = (((float)position[0] - (float)parent->SirRad->GetPosX()) / (float)parent->GWindow.GetWidth());
	direction[1] = (((float)position[1] - (float)parent->SirRad->GetPosY()) / (float)parent->GWindow.GetHeight());
	currentAnimation = 1;
	currentFrame = 0;
	isSpawned = true;
	hit = false;
	parent->PrintLog("Fireball Spawned");
}

void Fireball::Animate()
{
	if ((parent->totalTime - lastFrame) > 100)
	{
		CurrentSpriteClip = (((currentAnimation - 1) * 4) + currentFrame);
		currentFrame++;
		if (currentFrame == 4) {
			currentFrame = 0;
			if (currentAnimation == 2)
			{
				Death();
			}
		}
		lastFrame = parent->totalTime;
	}
}

void Fireball::Attack()
{
}

void Fireball::Damage()
{
}

void Fireball::Collide(Character* other)
{
	if (other->name == "SirRad" && !hit) {
		hit = true;
		if (parent->SirRad->performingTrick)
		{
			parent->PrintLog("dodged with trick + 500 score!");
			parent->ChangeScore(500);
		}
		else
		{
			parent->PrintLog("Fireball Hit - 300 score!");
			parent->ChangeScore(-300);
			currentAnimation = 2;
			speed = 0;
		}
	}
}
