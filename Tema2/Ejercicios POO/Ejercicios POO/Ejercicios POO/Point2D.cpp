#include "Point2D.h"
#include "Circle.h"
using namespace std;



/*Estoy hasta la polla esta puta mierda dice que no existe u constructor predeterinado correcto
de qué coño va. Joder es exactamente igual al de Circle y ese no me da problemas*/
Point2D::Point2D(int x, int y) {
	posicionX = x;
	posicionY = y;
}
Point2D::Point2D() {
	posicionX = 0;
	posicionY = 0;
}