#include "Textura.h"
#include "SDL.h"


Textura::Textura() {
	width = 0;
	heigh = 0;
	dest.x = 0;
	dest.y = 0;
	src.x = 0;
	src.y = 0;
	texture = nullptr;
}
void Textura::Print(SDL_Renderer* render) {

	SDL_RenderCopy(render, texture, &src, &dest);
}
void Textura::Load(SDL_Renderer* render,string file) {
	SDL_Surface* surface = IMG_Load(file.c_str());
	texture = SDL_CreateTextureFromSurface(render,surface);
	SDL_FreeSurface(surface);
	
}
void Textura::actFrame(SDL_Renderer* render, int frame) {
	src.x = 128 * int(((SDL_GetTicks() / frame) % 6));
}

void Textura::Move(int velX,int velY) {
	dest.x += velX;
	dest.y += velY;
}