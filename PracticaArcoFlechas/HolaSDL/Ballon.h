#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "SDL_image.h"
#include <string>
#include "Arrow.h"
#include <cstdlib>  //Generar random
//#include "Game.h"
class Game;

using uint = unsigned int;
class Ballon
{
private:

	Vector2D position = Vector2D(250+((rand()%10)*50),300); // la posicion en x es random
	uint w=3072;   //Numero de pixels que tiene cada cosa
	uint h=3584;
	uint row = 1;//7 tiene
	uint col = 1;//6 tiene
	int velocidadMovimiento = 10;
	Vector2D vel=Vector2D(0,-5);
	Texture* texture=nullptr;
	//Game* game;   para mas adelante
	bool poped=false;
	int timePoped=0;
public:
	Ballon();
	Ballon(uint w, uint h, Texture* t) : w(w), h(h), texture(t) {}
	void load();
	void render();
	bool update();
	


};

