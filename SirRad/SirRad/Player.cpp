#include "Player.h"
#include "GameEngine.h"

Player::Player()
{
}

Player::Player(int _size[2], int _position[2], int* _speed, string _ImagePath) : Character(_size, _position, _speed, _ImagePath, 5)
{
	name = "SirRad";
	speedUp = 0;
	MoveZone = 1;
	velocity.X = 0;
	velocity.Y = 0;
	isSpawned = true;
}

Player::~Player()
{
	engine->PrintLog("SirRad Is Gone! (unloaded)");
}
/// <summary>
/// The player moves from left to right taking into account it's x value to determine it's direction and rotation
/// </summary>
/// <param name="moveRight">whether the characters input direction is right or not</param>
/// <returns>whether the character was able to move</returns>
bool Player::Move()
{
	position[0] += velocity.X;
	position[1] -= velocity.Y;
	FindCollisionZone();
	SetRotation();
	return false;
}

void Player::Movement(bool moveLeft, bool moveRight)
{
	//cout << position[1] << endl;
	if (position[1] <= engine->GWindow.GetRampTop()) {
		velocity.Y -= 0.5f;
		velocity.X = 0;
		return;
	}
	if (position[0] < engine->GWindow.GetMiddleW() + engine->GWindow.GetEighthW() && position[0] > engine->GWindow.GetMiddleW() - engine->GWindow.GetEighthW()) {///////////MIDDLE
		ChangeMoveZone(0);
		if (moveRight && velocity.X < 15) {
			velocity.X += 1;
		}
		else if (!moveLeft && velocity.X > 0 && rand() % 10 <= 1) {
			velocity.X -= 1;
		}
		if (moveLeft && velocity.X > -15) {
			velocity.X -= 1;
		}
		else if (!moveRight && velocity.X < 0 && rand() % 10 <= 1) {
			velocity.X += 1;
		}
		position[1] = engine->ImageRender.GetRendererHeight() - (engine->ImageRender.GetRendererHeight() / 8);
		velocity.Y = 0;
	}
	if (position[0] > engine->GWindow.GetMiddleW() + (engine->GWindow.GetEighthW()/2)) /////////Right Side
	{
		ChangeMoveZone(1);
		if (velocity.X > 0) {
			//cout << speedUp << endl;
			velocity.Y = velocity.Y + 1;
			velocity.X -= 1;
		}
		else if (velocity.Y >= 0) {
			velocity.Y = velocity.Y - 1;
		}
		if (velocity.Y < 0) {
			if (abs((velocity.Y + (velocity.Y * (velocity.Y - 1)))/2) >= abs(position[1] - engine->GWindow.GetFloor())) {
				velocity.Y = velocity.Y + 1;
				velocity.X = velocity.X - 1;
			}
			else {
				velocity.Y = velocity.Y - 1;
			}
		}
	}
	if (position[0] < engine->GWindow.GetMiddleW() - (engine->GWindow.GetEighthW()/2)) { /////////////////////LEFT SIDE
		ChangeMoveZone(1);
		if (velocity.X < 0) {
			//cout << speedUp << endl;
			velocity.Y = velocity.Y + 1;
			velocity.X += 1;
		}
		else if (velocity.Y >= 0) {
			velocity.Y = velocity.Y - 1;
		}
		if (velocity.Y < 0) {
			if (abs((velocity.Y + (velocity.Y * (velocity.Y - 1))) / 2) >= abs(position[1] - engine->GWindow.GetFloor())) {
				velocity.Y = velocity.Y + 1;
				velocity.X = velocity.X + 1;
			}
			else {
				velocity.Y = velocity.Y - 1;
			}
		}
	}
}

void Player::ChangeDirection(int _direction)
{
	if (velocity.X > 0)
	{
		CharacterFlip = SDL_FLIP_NONE;
	}
	else if (velocity.X < 0)
	{
		CharacterFlip = SDL_FLIP_HORIZONTAL;
	}
}

void Player::ChangeMoveZone(int newZone)
{
	if (newZone != MoveZone) {
		EntrySpeed = velocity.X;
		MoveZone = newZone;
	}
}

void Player::Collide(Character* other)
{
}

void Player::SetRotation()
{

	if (position[0] > engine->GWindow.GetMiddleW() + (engine->GWindow.GetEighthW() / 2)) /////////Right Side
	{
		Rotation = 0 - abs((15-abs(velocity.X))* 6);
	}
	else if (position[0] < engine->GWindow.GetMiddleW() - (engine->GWindow.GetEighthW() / 2))
	{
		Rotation = abs((15 - abs(velocity.X)) * 6);
	}
	else 
	{
		Rotation = 0;
	}
}

void Player::Animate()
{
	if ((engine->totalTime - lastFrame) > 100)
	{
		CurrentSpriteClip = (((currentAnimation - 1) * 4) + currentFrame);
		currentFrame++;
		if (currentFrame == 4) {
			currentFrame = 0;
			if (currentAnimation == 3 || currentAnimation == 4 || currentAnimation == 5 )
			{
				switch (currentAnimation)
				{
				case 3:
					engine->ChangeScore(200);
					engine->PrintLog("Ollie! + 200 score!");
					break;
				case 4:
					engine->ChangeScore(1000);
					engine->PrintLog("Christ! + 1000 Score!");
					break;
				case 5:
					engine->ChangeScore(1000);
					engine->PrintLog("Flip! + 1000 Score!");
					break;
				default:
					break;
				}
				currentAnimation = 1;
				performingTrick = false;
				trickType = 0;
			}
		}
		lastFrame = engine->totalTime;
	}
}

void Player::DoTrick(int trick)
{
	if (!performingTrick)
	{
		trickType = trick;
		if (position[1] > engine->GWindow.GetRampTop() && (trick == 4 || trick == 5))
		{
			return;
		}
		currentAnimation = trick;
		currentFrame = 0;
		performingTrick = true;
	}
}
