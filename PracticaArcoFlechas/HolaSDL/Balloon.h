//Alumno1: David Czepiel
//Alumno2 : Daniel González Sellán
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
class Balloon
{
private:
	//Point2D position = Vector2D(250 + ((rand() % 10) * 50), winHeight + (rand() % 10) * 50); Si quiero obtener el alto de la venana se queja de que no es un identificador válido

	
	
	int winW=800;
	int winH = 1000;
	uint w=100;   //Numero de pixels que tiene cada cosa
	uint h=100;
	int row = (rand() % 7);//7 tiene
	int col = 0;//6 tiene
	Texture* texture=nullptr;
	Game* game=nullptr;
	Point2D position = Vector2D(((rand()%(winW/2))-w+(winW/2)),winH+h+(rand()%10)*50); // las posiciones en las que aparecen son random
	Vector2D vel = Vector2D(0,-1);  //Velocidad random para cada globo
	bool poped=false;
	int posV;   //su posicion en el vector de globos
	int updates = 0;   // Para la animacion de explosion

public:
	Balloon();
	Balloon( Texture* t, Game* game, int posV,int wWidth,int wHeigth) : texture(t), game(game), posV(posV) ,winW(wWidth),winH(wHeigth){}
	void render();
	bool update();
	SDL_Rect GetRect();

	


};

