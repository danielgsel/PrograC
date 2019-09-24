#include <fstream>
#include <iostream>
#include "Date.h"
//#include <string>

using namespace std;

struct Coche {
	string nombre;
	int codigo;
	int precioDia;

};

struct Alquiler {

	int codigo;
	int diasAlq;
	Date* fecha;
};

struct ListaCoches {
	Coche* lista;
	int tamanio;
	int elems;
};

struct ListaAlquileres{
	Alquiler* lista;
	int tamano;
	int elems;
};

bool cargarCoche(ListaCoches& miLista);
bool LeerAlquileres(ListaAlquileres& listaAlq);

int main() {

	ListaCoches miLista;
	ListaAlquileres listaAlq;
	cargarCoche(miLista);
	LeerAlquileres(listaAlq);
	

	
	return 1;
}


bool cargarCoche(ListaCoches& miLista) {
	int number;
	string linea;
	ifstream input;

	input.open("coches.txt");
	
	bool hola = input.is_open();
	if (hola){
	input >> number;
	miLista.tamanio = number;
		miLista.lista = new Coche[number];

		for (int i = 0; i < number; i++) {
			//linea = input.getline;
			input >> miLista.lista[i].codigo;
			input >> miLista.lista[i].precioDia;
			input >> miLista.lista[i].nombre;
			string segnom;
			input >> segnom;
			miLista.lista[i].nombre += segnom;
		}

		for (int i = 0; i < number; i++) {

			cout << miLista.lista[i].codigo << " " << miLista.lista[i].precioDia << " " << miLista.lista[i].nombre << endl;
		}

		input.close();


		return true;
	}

	else return false;


}

bool LeerAlquileres(ListaAlquileres& listaAlq) {

	int number;
	ifstream input;

	input.open("rent.txt");
	
	bool open = input.is_open();
	if (open){
		input >> number;
		listaAlq.lista = new Alquiler[number];

		for (int i = 0; i < number; i++) {
			input >> listaAlq.lista[i].codigo;

			int day, month, year;



			//listaAlq.lista[i].fecha = new Date(day, month, year);

			input >> listaAlq.lista[i].diasAlq;

		}




	return true;}
	else return false;
}
