#include "Marcador.h"


void Marcador::SetPoints(int newpoints) {
	points = newpoints;
}

int Marcador::digits(int number) {


	int i = 0;
	while (number != 0) {
		number = number/ 10;
		i++;
	}

	return i;
}

void Marcador::render(){
	int puntos = points;
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	if (points <= 9) {
		texture->renderFrame(dest, 0, points);

	}
	else {
		int ndigits = digits(points);
		for (int i = ndigits -1 ; i >= 0; i--) {
			dest.x = (position.getX() + i * (w));
			int columna = puntos % 10;
			texture->renderFrame(dest, 0, columna);
			puntos /= 10;
		}
	}
}