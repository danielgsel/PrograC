#include "Arrow.h"

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>




Arrow::Arrow() {
	position = Vector2D();
	w = 0;
	h = 0;
	
	vel = Vector2D();

}

void Arrow::load() {
	//texture->load("..\\images\\Arrow1.png",1,1);
}

void Arrow::setVel(double x, double y) {
	vel.setX(x);
	vel.setY(y);
}

void Arrow::render() {
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	//texture->render();
}

void Arrow::update() {
	position.setX(position.getX() + vel.getX());
	position.setY(position.getY() + vel.getY());


	//Si se sale de la derecha lo pongo a 0 POR AHORA	
	if (position.getX() > 800) {  
		position.setX(0);
		position.setY(0);
	}
	
}