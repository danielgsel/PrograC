#include "Arrow.h"

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>




Arrow::Arrow(double x, double y, Texture* t, int angle) {
	position = Vector2D();
	w = 100;
	h = 30;
	position.setX(x);
	position.setY(y+40);

	texture = t;
	
	vel = Vector2D();
	angulo = angle;

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
	texture->renderFrame(dest,0,0, angulo);
}

bool Arrow::update() {
	
	position.setY(position.getY() + vel.getY());
	position.setX(position.getX() + vel.getX());


	if (position.getX() >= 800) {
		return true;
	}
	else return false;
	
}

SDL_Rect* Arrow::GetRect() {
	SDL_Rect* dest = new SDL_Rect(); 
	dest->x = position.getX();
	dest->y = position.getY();
	dest->w = w;
	dest->h = h;
	return dest;
}