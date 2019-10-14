#include "Ballon.h"
#include "Game.h"

Ballon::Ballon() {
	 position=Vector2D();
	 w=0;
	 h = 0;
	vel=Vector2D();
	//game=nullptr;
	poped=false;
	timePoped = 0;;
}

void Ballon::render() {
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w ;
	dest.h = h;
	if(!poped)
	texture->renderFrame(dest, row, 0);
	
	
	//Para cuando el globo explote
	/*else
		texture->renderFrame(dest, row, 0);*/
}

bool Ballon::update() {
	position.setX(position.getX()+vel.getX());
	position.setY(position.getY() + vel.getY());	
	return(position.getY()<0);  // depende de si el globo se ha salido por arriba (hago 0- h para que el globo salga del todo 
	//Lo de que devuelva el booleano no lo he tenido en cuenta aun. Solo he hecho que se muevan hacia arriba y ya
}