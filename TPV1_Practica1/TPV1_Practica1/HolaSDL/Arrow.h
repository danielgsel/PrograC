//Alumno1: David Czepiel
//Alumno2 : Daniel González Sellán
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
	int winwidth=800;
	int winHeigth = 1000;
	
	Vector2D vel;
	int maxVel = 100;
	int angulo = 0;
	Texture* texture = nullptr;

public:
	Arrow(double x, double y, Texture* t, int angle,int wWidth,int wHeigth);
	~Arrow(){}
	void render();
	void setVel(double x, double y);
	bool update();
	SDL_Rect GetRect();
};

