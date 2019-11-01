//Alumno1: David Czepiel
//Alumno2 : Daniel González Sellán
#include "Bow.h"
#include "Game.h"




void Bow::render() {
	//Preparo el rect y o paso para su renderizado
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	//Le digo que renderice texture, que puede tener cargada la imagen del arco cargado o sin cargar
	texture->renderFrame(dest,0,0,rotation);
}

void Bow::update() {
	
	if ((position.getY()+vel.getY() > 0) && (position.getY()+vel.getY() + h < winHeight)) {
		position = position + vel;
	}
}

void Bow::handleEvents(SDL_Event& event) {


	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			//Movimiento vertical y carga
		case SDLK_w:
			vel.setY(-velocidadMovimiento);
			break;

		case SDLK_s:
			vel.setY(velocidadMovimiento);
			break;
		case SDLK_q:
			rotation -= 10;
			break;
		case SDLK_e:
			rotation += 10;
			break;
		case SDLK_a:
			//Pregunto si quedanflechas, si quedan empiezo a cargar si no, nada
			if (game->arrowsLeft() > 0) {
				charged = true;
				texture = textureCharged;
				timeCharged = SDL_GetTicks();
			}
			break;
		case SDLK_d:
			if (charged) {
				charged = false;
				velocidadFlecha = ((SDL_GetTicks()) - timeCharged)/150; //y una operacion que calcule la velocidad segun el tiempo que haya sacado
				if (velocidadFlecha > 20)
					velocidadFlecha = 20;
				if (rotation != 0 && velocidadFlecha < 3)
					velocidadFlecha = 3;
				else if (rotation == 0 && velocidadFlecha < 3) {
					velocidadFlecha = 3;
				}
				game->newArrow(position.getX(), position.getY(),velocidadFlecha,rotation);
				texture = textureIddle;
			}
			break;
			
		}

	}
	else if(event.type == SDL_KEYUP)
		switch (event.key.keysym.sym) {
			//Movimiento vertical y carga
		case SDLK_w:
			vel.setY(0);
			break;

		case SDLK_s:
			vel.setY(0);
			break;
		}
}