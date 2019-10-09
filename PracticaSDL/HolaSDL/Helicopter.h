#pragma once

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include "Texture.h"


using namespace std;

class Helicopter
{
private:

	int dirX = 0;
	int dirY = 0;

	Texture* texture = nullptr;


	int x = 0, y = 0;
	uint w = 0, h = 0;

	int col = 0;
	int row = 0;

	bool isMoving = true;

	int velx = 0;
	int updates = 0, updatesPerFrame = 2;


public:
	Helicopter() {}
	Helicopter(uint w, uint h, uint x, uint y, Texture* t) : w(w), h(h), x(x), y(y), texture(t) {}
	~Helicopter() {}
	void render() const;
	void update();
	void load();
	void handleEvents(SDL_Event& event);
};

