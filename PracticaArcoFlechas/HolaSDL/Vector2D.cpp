#include "Vector2D.h"
#include <math.h> // incluye la libreria matematica (para la raiz cuadrada)


using namespace std;
Vector2D::Vector2D() {
	x = 0;
	y = 0;
}
Vector2D::Vector2D(unsigned int newX, unsigned int newY) {
	x = newX;
	y = newY;
}
void Vector2D::operator+(Vector2D other) {
	x = x + other.getX();
	y = y + other.getY();
}
void Vector2D::operator-(Vector2D other) {
	x = x - other.getX();
	y = y - other.getY();
}
void Vector2D::operator*(int other) {    
	x = x *other;
	y = y *other;
}
//Producto escalar
int Vector2D::operator*(Vector2D other) {                    
	return((x*other.getX())+(y*other.getY()));
}

double Vector2D::getX() {
	return x;
}

void Vector2D::setX(double newX) {
	x = newX;
}

double Vector2D::getY() {
	return y;
}
void Vector2D::setY(double newY) {
	y = newY;
}

void Vector2D::normalize() {
	double normalizador = sqrt(pow(x,2)+pow(y,2));

	x = x / normalizador;
	y = y / normalizador;  
	//No pongo la expresion de normalizador en vez de la variable porque para 
	//cuando llegue a normalizar la y la x habra cambiado y no me saldra 
	//el resultado correcto
     
}
