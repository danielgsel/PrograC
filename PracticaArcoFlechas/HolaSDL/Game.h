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
#include "Marcador.h"


using uint = unsigned int;

	


class Game
{
private:
	const static uint winWidth = 1500;
	const static uint winHeight = 600;
	const static uint numTextures = 7;
	const uint numBalloons = 6;
	const uint FRAMERATE = 5;
	int numArrows = 10;
	int puntuacion = 0;
	bool exit = false;
	struct  mytextures
	{
		string file;
		uint row;
			uint col;
	};
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Texture* textures[numTextures];
	vector<Ballon*> ballons;
	vector<Arrow*> arrows;
	Marcador* marcador=nullptr;
	Bow* bow =nullptr;

	const mytextures mytextures[numTextures] = {{"..\\images\\bg1.png",1,1},{"..\\images\\Bow2.png",1,1},
	{"..\\images\\Bow1.png",1,1},{"..\\images\\Arrow1.png",1,1},{"..\\images\\Arrow2.png",1,1},
	{"..\\images\\balloons.png",7,6},{"..\\images\\digits1.png",1,10}
	};
	void generateBalloons(vector<Ballon*> *ball, int i);

public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();	
	void newArrow(double x, double y,int speed, int rotatio);
	int arrowsLeft();
	bool arrowHitsBaloon(SDL_Rect baloon);
	void destroyBaloon(int pos);

};



