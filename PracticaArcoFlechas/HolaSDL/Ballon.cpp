#include "Ballon.h"


Ballon::Ballon() {
	 position=Vector2D();
	 w=0;
	 h = 0;
     velocidadMovimiento = 10;
	vel=Vector2D();
	texture;// = Texture();
	game=nullptr;
	poped=false;
	timePoped = 0;;
}

void Ballon::render() {

}

bool Ballon::update() {
	position.setX(position.getX()+vel.getX());
	position.setY(position.getY() + vel.getY());

	return(position.getY()<0);  // depende de si el globo se ha salido por arriba
}