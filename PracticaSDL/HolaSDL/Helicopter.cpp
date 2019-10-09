#include "Helicopter.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>


using namespace std;


void Helicopter::load() {

	texture->load("..\\images\\helicopter.png", 1, 5);

}

void Helicopter::render()const {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	texture->renderFrame(dest, row, col);
}

void Helicopter::update() {

	x = x + velx;

	if (x > 800) x = -100;

	if (x < -110) x = 750;

	updates++;


	if (updates >= updatesPerFrame) {
		if (velx == 0) col = 2;

		else {
			col++; updates = 0;
		}
	}

	if (col >= 5) col = 0;
}

void Helicopter::handleEvents(SDL_Event& event) {

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {

		case SDLK_h:
			velx = 0;
			break;

		case SDLK_j:
			velx += 10;
			break;
		case SDLK_g:
			velx -= 10;
			break;

		}

	}



}
