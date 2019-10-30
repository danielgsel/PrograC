#include "Ballon.h"
#include "Game.h"

Ballon::Ballon() {
	 position=Vector2D();
	 w=0;
	 h = 0;
	vel=Vector2D();
	poped=false;
		Game* game;
}

void Ballon::render() {
	//Preparo el rect y lo mando para su renderizado
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w ;
	dest.h = h;
	//Si no esta pinchado que se renderice el primer frame del globo que es el normal
	//Por el contrario si poped, voy pasando por cada uno de los frames de la animacion y al finalizarla destruyo el globo
	if(!poped)
	texture->renderFrame(dest, row, 0);
	
	else {
		if (col < 7) {
			updates++;
			if (updates > 10) {
				
				updates = 0; col++;
			}
			texture->renderFrame(dest, row, col);
		}
		else
			game->destroyBaloon(posV);		
	}	
}

//Le digo que se dibuje en su posicion, pregunto si alguna flecha me esta dando, hago que se mueva para el siguiente frame y devuelvo si se ha salido de la pantalla o no
bool Ballon::update() {
	SDL_Rect dest = SDL_Rect();
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	
	if (game->arrowHitsBaloon(dest)) {
		poped = true;		
	}
	position = position+vel;
	return(position.getY() + h < 0);
}

SDL_Rect Ballon::GetRect() {
	SDL_Rect dest = SDL_Rect();
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	return dest;
}