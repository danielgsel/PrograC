#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "SDL_image.h"
#include <string>
#include "Arrow.h"
//#include "Game.h"
class Game;

class Bow
{

private:
	Point2D position=Vector2D(50,0);
	Vector2D vel=  Vector2D();        //En el cpp estoy cambiando su valor constatemente, habría que busca otra forma de imlementarlo para que no cambie su valor
	
	uint w=100;
	uint h = 100;
	int velocidadMovimiento = 5;
	int timeCharged = 0;
	int velocidadFlecha = 0;
	int winHeight = 1000;
	Texture* texture = nullptr;
	Texture* textureIddle = nullptr;
	Texture* textureCharged = nullptr;
	Game* game;
	bool charged=false;
	int rotation = 0;
public:
	Bow() {}
	Bow( Texture* t,Texture* c, Game* game,int wH) : texture(t), textureIddle(t),textureCharged(c), game(game),winHeight(wH) {}
	void render() ;
	void update();
    void handleEvents(SDL_Event& event);

};

