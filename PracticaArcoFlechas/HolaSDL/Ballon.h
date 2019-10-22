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
	int row = (rand() % 7);//7 tiene
	int col = 0;//6 tiene
	Vector2D vel = Vector2D();  //Velocidad random para cada globo
	Texture* texture=nullptr;
	bool poped=false;
	//int timePoped=0;
	//Game* game;   para mas adelante
	int balloonRow;
	Game* game;
	int posV;
	int updates = 0;

public:
	Ballon();
	Ballon(uint w, uint h, Texture* t, int velBallon, Game* game, int posV) : w(w), h(h), texture(t),vel(0,-velBallon), game(game), posV(posV) {}
	void render();
	bool update();
	SDL_Rect* GetRect();

	


};

