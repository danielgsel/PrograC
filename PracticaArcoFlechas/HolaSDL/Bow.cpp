#include "Bow.h"
#include "Game.h"




void Bow::render() {
	//Preparo el rect y o paso para su renderizado
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	texture->renderAngle(dest,rotation);
}

void Bow::update() {
	
	//Todo el rato le digo que se mueva con la velocidad que tenga, que puede ser 0
	position.setX(position.getX() + vel.getX());
	if (!(position.getY() + vel.getY() < 0) && !(position.getY() + vel.getY()+h > winHeight))   //Para que el arco no se salga de la pantalla
	position.setY(position.getY() + vel.getY());
	//Los pongo a 0 aqui porque el bucle de handle events se ejecuta muchas veces y en ese caso nada mas ponerla a 100 se volveria a poner  0
	vel.setX(0);
	vel.setY(0);
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
			charged = true;
			texture->load("..\\images\\bow1.png",1,1);   //Para cuando el bow pueda disparar
			timeCharged = SDL_GetTicks();
			break;
		case SDLK_d:
			if (charged) {
				charged = false;
				velocidadFlecha = ((SDL_GetTicks()) - timeCharged)/150; //y una operacion que calcule la velocidad segun el tiempo que haya sacado
				if (velocidadFlecha > 20)
					velocidadFlecha = 20;
				if (rotation != 0 && velocidadFlecha < 3)
					velocidadFlecha = 3;
				else if (rotation == 0 && velocidadFlecha < 1) {
					velocidadFlecha = 1;
				}
				game->newArrow(position.getX(), position.getY(),velocidadFlecha,rotation);
				texture->load("..\\images\\bow2.png",1,1); // Para cuando el bow pueda disparar
			}
			break;
		}

	}
}