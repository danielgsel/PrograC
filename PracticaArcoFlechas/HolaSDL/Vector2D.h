#pragma once

using namespace std;
class Vector2D
{

private:
	double x;
	double y;


public:
	Vector2D();
	Vector2D(int newX, int newY);
	Vector2D operator+(Vector2D other);
	Vector2D operator-(Vector2D other);
	Vector2D operator*(int other);
	int operator*(Vector2D other);

	double getX();
	void setX(double newX);
	double getY();
	void setY(double newY);
	void normalize();
};

using Point2D = Vector2D;

