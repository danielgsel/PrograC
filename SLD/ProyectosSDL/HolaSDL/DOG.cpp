#include "DOG.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>


using namespace std;


void DOG::load() {
	texture->load("..\\images\\dog.png", 1, 6);
}

void DOG::render()const {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	texture->renderFrame(dest,row,col);
}

void DOG::update() {
	
	x = x + velx;

	if (x > 750) x = 0;

	if (x < 0) x = 750;
}

void DOG::handleEvents(SDL_Event& event) {
		
	if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			
			case SDLK_d:
				velx = 0;
				break;
			
			case SDLK_f:
				velx += 10;
				break;
			case SDLK_s:
				velx -= 10;
				break;

			}

		}

	

}
