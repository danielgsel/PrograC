//Alumno1: David Czepiel
//Alumno2 : Daniel González Sellán
#include "ScoreBoard.h"


void ScoreBoard::SetPoints(int newpoints) {
	points = newpoints;
}

//Devuelve el numero de dígitos que tiene number
int ScoreBoard::digits(int number) {
	int i = 0;
	while (number != 0) {
		number = number/ 10;
		i++;
	}

	return i;
}

void ScoreBoard::arrowShot(int arr) {
	arrows = arr;
}

int ScoreBoard::getPoints() {
	return points;
}

void ScoreBoard::render(){

	//Renderizo los puntos
	int puntos = points;
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = w;
	dest.h = h;
	//Si es de solo un dígito
	if (points <= 9) {
		texture->renderFrame(dest, 0, points);

	}
	//Si es de más, hay que ir consiguiendo cada dígito del número
	else {
		int ndigits = digits(points);
		for (int i = ndigits - 1; i >= 0; i--) {
			dest.x = (position.getX() + i * (w));
			int columna = puntos % 10;
			texture->renderFrame(dest, 0, columna);
			puntos /= 10;
		}
	}

	//Por cada flecha que me quede renderizo una en la parte superior izquierda de la pantalla
	for (int i = 0; i < arrows; i++) {
		SDL_Rect destArrow;
		destArrow.x = position.getX()+100+(20*i);
		destArrow.y = position.getY();
		destArrow.w = w;
		destArrow.h = 2*h;
	    arrowTexture->render(destArrow);
	}
}