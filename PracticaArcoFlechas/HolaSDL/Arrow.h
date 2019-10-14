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
	SDL_Texture* texture;// = Texture();

public:
	Arrow();
	void render();
	void setVel(double x, double y);
	void update();
};

