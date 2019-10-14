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
	//Point2D position = Vector2D(250 + ((rand() % 10) * 50), winHeight + (rand() % 10) * 50); Si quiero obtener el alto de la venana se queja de que no es un identificador válido

	Point2D position = Vector2D(250+((rand()%10)*50),600+(rand() % 10) * 50); // las posiciones en las que aparecen son random
	uint w=70;   //Numero de pixels que tiene cada cosa
	uint h=100;
	uint row = (rand() % 7);//7 tiene
	uint col = 0;//6 tiene
	Vector2D vel = Vector2D(0,-(rand() % 10));  //Velocidad random para cada globo
	Texture* texture=nullptr;
	//Game* game;   para mas adelante
	bool poped=false;
	int timePoped=0;
	int balloonRow;

public:
	Ballon();
	Ballon(uint w, uint h, Texture* t) : w(w), h(h), texture(t) {}
	void render();
	bool update();
	


};

