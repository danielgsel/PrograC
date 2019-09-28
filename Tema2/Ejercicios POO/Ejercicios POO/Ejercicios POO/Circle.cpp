#include "Circle.h"
#include <iostream>
#include "Point2D.h"

using namespace std;


Circle::Circle(int X, int Y, int R) {
	x = X;
	y = Y;
	radius = R;


}
int Circle::Area (){
	 
	int area = radius * radius * PI;
	return area;
}
void Circle:: Move(int nuevoX, int nuevoY) {
	x += nuevoX;
	y += nuevoY;
}

void Circle::Print() {
	cout << "El centro esta en la posicion[" << centro.posicionX << "," << centro.posicionY << "] y su radio es "<<radius;
}