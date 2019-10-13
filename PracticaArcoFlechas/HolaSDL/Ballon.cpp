#include "Ballon.h"
#include "Game.h"

Ballon::Ballon() {
	 position=Vector2D();
	 w=0;
	 h = 0;
     velocidadMovimiento = 10;
	vel=Vector2D();
	//game=nullptr;
	poped=false;
	timePoped = 0;;
	//balloonRow = 1+ (rand() % (6));
}

void Ballon::load() {
	texture->load("..\\images\\balloons.png");
}

void Ballon::render() {
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w ;
	dest.h = h ;
	//texture->render(dest);
	texture->renderFrame(dest, 2, 1);
}

bool Ballon::update() {
	position.setX(position.getX()+vel.getX());
	position.setY(position.getY() + vel.getY());	
	return(position.getY()<0);  // depende de si el globo se ha salido por arriba  
	//Lo de que devuelva el booleano no lo he tenido en cuenta aun. Solo he hecho que se muevan hacia arriba y ya
}