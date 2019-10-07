#pragma once
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>


using namespace std;
class Textura
{
private:
	int heigh;
	int width;
	
	SDL_Texture* texture;
public:
	 Textura();
	 SDL_Rect src;
	 SDL_Rect dest;
	void Load(SDL_Renderer* render ,string file);
	void Print(SDL_Renderer* render);
	void Move(int velX,int velY);

	
};

