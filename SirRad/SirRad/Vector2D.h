#ifndef VECTOR2D_H
#define VECTOR2d_H
#include <cmath>
class Vector2D
{
public:
	Vector2D();
	Vector2D(int eX, int eY);
	float GetX() const { return X; }
	void SetX(float change) { X = change; }
	void AddX(float change) { X += change; }
	float GetY() const { return Y; }
	void SetY(float change) { Y = change; }
	void AddY(float change) { Y += change; }
private:
	float magnitude();
private:
	float X, Y;
};
#endif

