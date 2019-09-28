#pragma once
#include "Point2D.h"
class Circle
{

private:

	int x;
	int y;
	int radius;
	const int PI=3.14;
	Point2D centro= Point2D(x,y);

public:
	int Area();
	void Move(int nuevoX, int nuevoY);
	Circle(int x, int y, int r);
	void Print();
};

