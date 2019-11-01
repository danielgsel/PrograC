#include "Arrow.h"

#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <string>




Arrow::Arrow(double x, double y, Texture* t, int angle,int wWidth,int wHeigth) {
	position = Vector2D();
	w = 100;
	h = 30;
	position.setX(x);
	position.setY(y+40);
	texture = t;
	winwidth = wWidth;
	winHeigth = wHeigth;
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
	position = position + vel;
	if (position.getX() >= winwidth || position.getX()+w<=0 || position.getY()+w<=0 || position.getY()-w>winHeigth) {  //Utilizamos el ancho debido a que es la medida más grande que tiene y asi aseguramos que se ha salido de pantalla
		return true;
	}
	else return false;
	
}

SDL_Rect Arrow::GetRect() {
	SDL_Rect dest = SDL_Rect(); 
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	return dest;
}