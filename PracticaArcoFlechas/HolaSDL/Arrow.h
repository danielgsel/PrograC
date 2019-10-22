#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "SDL_image.h"
#include <string>

using namespace std;
class Arrow
{

private:
	Point2D position;
	int w;
	int h;
	
	Vector2D vel;
	int maxVel = 100;
	int angulo = 0;
	Texture* texture = nullptr;

public:
	Arrow(double x, double y, Texture* t, int angle);
	~Arrow(){}
	void render();
	void setVel(double x, double y);
	bool update();
	SDL_Rect* GetRect();
};

