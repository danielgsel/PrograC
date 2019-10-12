#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "SDL_image.h"
#include <string>
#include "Arrow.h"
#include "Game.h"
class Ballon
{
private:
	Vector2D position;
	int w;
	int h;
	int velocidadMovimiento = 10;
	Vector2D vel;
	SDL_Texture* texture;// = Texture();
	Game* game;
	bool poped;
	int timePoped;
public:
	Ballon();
	void render();
	bool update();
	void handleEvents(SDL_Event& event);


};

