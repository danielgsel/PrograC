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

	const uint winWidth = 1500;
	const uint winHeight = 600;
	const uint numTextures = 7;
	const uint numBalloons = 6;
	const uint FRAMERATE = 5;
	const uint velBow = 5;
	const int velBallon = 1;
	const int numArrows = 7;


class Game
{
private:
	struct  mytextures
	{
		string file;
		uint row;
			uint col;
	};
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Bow* bow =nullptr;
	vector<Ballon*> ballons;
	bool exit = false;
	Texture* textures[numTextures];
	vector<Arrow*> arrows;
	int puntuacion = 0;
	Marcador* marcador;

	const mytextures mytextures[numTextures] = {{"..\\images\\bg1.png",1,1},{"..\\images\\Bow2.png",1,1},
	{"..\\images\\Bow1.png",1,1},{"..\\images\\Arrow1.png",1,1},{"..\\images\\Arrow2.png",1,1},
	{"..\\images\\balloons.png",7,6},{"..\\images\\digits1.png",1,10}
	};

public:
	Game();
	~Game();
	void run();
	void generateBalloons(vector<Ballon*> *ball, int i);
	void render() const;
	void handleEvents();
	void update();	
	void SaveScore();
	void newArrow(double x, double y,int speed, int rotatio);
	int arrowsLeft();
	bool arrowHitsBaloon(SDL_Rect baloon);
	void destroyBaloon(int pos);

};



