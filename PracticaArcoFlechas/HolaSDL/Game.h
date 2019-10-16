#pragma once

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>
#include "Texture.h"
#include "Bow.h"
#include "Arrow.h"
#include "Ballon.h"
#include <vector>


using uint = unsigned int;

	const uint winWidth = 800;
	const uint winHeight = 600;
	const uint numTextures = 7;
	const uint numBalloons = 6;
	const uint FRAMERATE = 5;
	const uint velBow = 10;
	const int velBallon = 1;


class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Bow* bow =nullptr;
	vector<Ballon*> ballons;
	bool exit = false;
	Texture* textures[numTextures];
	vector<Arrow*> arrows;
	//int puntuacion;




public:
	Game();
	~Game();
	void run();
	void generateBalloons(vector<Ballon*> *ball, int i);
	void render() const;
	void handleEvents();
	void update();	
	void newArrow(double x, double y);


};



