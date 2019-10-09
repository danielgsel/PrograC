#pragma once

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include "Texture.h"
#include "DOG.h"
#include "Helicopter.h"


	const uint winWidth = 800;
	const uint winHeight = 600;
	const uint numTextures = 3;


class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	DOG* dog = nullptr;
	Helicopter* heli = nullptr;
	bool exit = false;
	Texture* textures[numTextures];


public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();	


};



