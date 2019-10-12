#pragma once

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include "Texture.h"
#include "DOG.h"
#include "Bow.h"
#include "Arrow.h"
#include "Ballon.h"
#include <vector>



	const uint winWidth = 800;
	const uint winHeight = 600;
	const uint numTextures = 7;
	const uint frameRate = 100;
	const uint velBow = 10;
	const uint velBallon = 20;


class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Bow* bow = nullptr;
	vector<Arrow> arrows;
	vector<Ballon> ballons;
	DOG* dog = nullptr;
	
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



