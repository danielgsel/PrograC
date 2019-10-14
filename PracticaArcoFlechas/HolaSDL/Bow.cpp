#include "Bow.h"
#include "Game.h"




void Bow::render() {
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	texture->render(dest);
}

void Bow::update() {
	
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
		case SDLK_w:
			vel.setY(-velocidadMovimiento);
			break;
		case SDLK_s:
			vel.setY(velocidadMovimiento);
			break;
		case SDLK_a:
			charged = true;
			//texture->load("..\\images\\bow1.png",1,1);   //Para cuando el bow pueda disparar
			break;
		case SDLK_d:
			if (charged) {
				charged = false;
				//texture->load("..\\images\\bow2.png",1,1); // Para cuando el bow pueda disparar
			}
			break;
		}

	}
}