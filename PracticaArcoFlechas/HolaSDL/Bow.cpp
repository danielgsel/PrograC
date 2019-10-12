#include "Bow.h"


Bow::Bow() {
	position=Vector2D();
	w = 0;;
	h = 0;;
	vel=Vector2D();
	texture;// = Texture();
    chargedArrow=nullptr;
	game=nullptr;
	charged=false;
}

void Bow::load() {
	texture->load("..\\images\\Bow2.png", 1, 1);
}

void Bow::render() {

}

void Bow::update() {
	position.setX(position.getX()+vel.getX());
	position.setY(position.getY()+vel.getY());
}

void Bow::handleEvents(SDL_Event& event) {

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {

		case SDLK_w:
			vel.setY(10);
			break;

		case SDLK_s:
			vel.setY(-10);
			break;
		case SDLK_a:
			charged = true;
			//texture->load("..\\images\\bow1.png",1,1);
			break;
		case SDLK_d:
			if (charged) {
				charged = false;
				//texture->load("..\\images\\bow2.png",1,1);
			}
			break;
		default:
			vel.setY(0);
			break;

		}

	}



}