//Alumno1: David Czepiel
//Alumno2 : Daniel González Sellán
#include "Vector2D.h"
#include <math.h> // incluye la libreria matematica (para la raiz cuadrada)


using namespace std;
using uint = unsigned int;
Vector2D::Vector2D() {
	x = 0;
	y = 0;
}
Vector2D::Vector2D(int newX, int newY) {
	x = newX;
	y = newY;
}
//SUMA 
Vector2D Vector2D::operator+(Vector2D other) {
	x = x + other.getX();
	y = y + other.getY();
	return Vector2D(x,y);
}
//RESTA
Vector2D Vector2D::operator-(Vector2D other) {
	x = x - other.getX();
	y = y - other.getY();
	return Vector2D(x, y);
}
//ESCALAR * VECTOR
Vector2D Vector2D::operator*(int other) {    
	x = x *other;
	y = y *other;
	return Vector2D(x, y);
}
//PRODUCTO ESCALAR
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
     
}
