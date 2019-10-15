#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "SDL_image.h"
#include <string>
#include "Arrow.h"
//#include "Game.h"
class Game;
using uint = unsigned int;
class Bow
{

private:
	Point2D position=Vector2D(50,0);
	Vector2D vel=  Vector2D();        //En el cpp estoy cambiando su valor constatemente, habr�a que busca otra forma de imlementarlo para que no cambie su valor
	
	uint w=200;
	uint h = 200;
	int velocidadMovimiento = 10;
	Texture* texture = nullptr;
	//Game* game;
	bool charged=false;
public:
	Bow() {};
	Bow(uint w, uint h, Texture* t, int velMov) : w(w), h(h), texture(t),velocidadMovimiento(velMov) {}
	void render() ;
	void update();
    void handleEvents(SDL_Event& event);

};

