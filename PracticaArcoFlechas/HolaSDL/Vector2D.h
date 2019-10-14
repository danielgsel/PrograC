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
	void operator+(Vector2D other);
	void operator-(Vector2D other);
	void operator*(int other);
	int operator*(Vector2D other);

	double getX();
	void setX(double newX);
	double getY();
	void setY(double newY);
	void normalize();
};

using Point2D = Vector2D;
