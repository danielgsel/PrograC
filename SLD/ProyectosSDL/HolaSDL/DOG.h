#pragma once

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include "Textura.h"


using namespace std;
class DOG
{
private:
	int velX;
	int velY;

public:
	DOG();
	Textura* texture;
	void print(SDL_Renderer* render);
	void actPos(SDL_Renderer* render);
	void actAnim(SDL_Renderer* render,int frame);
	void newTexture(SDL_Renderer* render,string file);
};

