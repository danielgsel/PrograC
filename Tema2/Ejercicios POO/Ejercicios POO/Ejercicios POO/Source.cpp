#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
	cout << "Tengo un circulo"<<endl<<endl;
	Circle circulo =  Circle(3,4,5);
	circulo.Print();

	return 0;
}