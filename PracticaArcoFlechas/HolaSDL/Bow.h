#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "SDL_image.h"
#include <string>
#include "Arrow.h"
#include "Game.h"

class Bow
{

private:
	Vector2D position;
	int w;
	int h;
	int velocidadMovimiento = 10;
	Vector2D vel;
	Texture* texture = nullptr;
	Arrow* chargedArrow;
	Game* game;
	bool charged;
public:
	Bow();
	Bow(uint w, uint h, uint x, uint y, Texture* t) : w(w), h(h), position(Vector2D(x,y)), texture(t) {}
	void load();
	void render();
	void update();
    void handleEvents(SDL_Event& event);

};

