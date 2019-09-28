//Grupo 4
//David Czepiel
//Daniel González Sellán
#include <fstream>
#include <iostream>
#include "Date.h"
#include <algorithm>


using namespace std;

struct Coche {
	string nombre;
	int codigo;
	int precioDia;

};

struct Alquiler {

	int codigo;
	int diasAlq;
	Date fecha;
	Coche* coche;
};

struct ListaCoches {
	Coche* lista;
	int tamanio;
	int cont;
};

struct ListaAlquileres {
	Alquiler* lista;
	int tamano;
	int cont;
};



bool comp(const Alquiler& lis1, const Alquiler& lis2);
bool cargarCoche(ListaCoches& miLista);
bool LeerAlquileres(ListaAlquileres& listaAlq, ListaCoches& coches);
Coche* buscarCoche(ListaCoches& lista, int cod);
void mostrarAlquiler(ListaAlquileres& lista);
void ordenarAlquiler(ListaAlquileres& miLista);

int main() {

	ListaCoches listaCoches;
	ListaAlquileres listaAlq;
	cargarCoche(listaCoches);
	LeerAlquileres(listaAlq, listaCoches);
	cout << endl << endl;
	mostrarAlquiler(listaAlq);
	cout << endl << endl;

	ordenarAlquiler(listaAlq);

	mostrarAlquiler(listaAlq);

	delete[] listaCoches.lista;
	delete[] listaAlq.lista;
	listaCoches.lista = nullptr;
	listaAlq.lista = nullptr;
	return 1;
}


bool cargarCoche(ListaCoches& miLista) {

	string linea;
	ifstream input;

	input.open("coches.txt");

	bool hola = input.is_open();
	if (hola) {
		input >> miLista.cont;
		miLista.tamanio = miLista.cont + 10;
		miLista.lista = new Coche[miLista.cont];

		for (int i = 0; i < miLista.cont; i++) {

			input >> miLista.lista[i].codigo;
			input >> miLista.lista[i].precioDia;
			input >> miLista.lista[i].nombre;
			string segnom;
			input >> segnom;
			miLista.lista[i].nombre += " " + segnom;
		}

		//Para poder visualizar lo que se ha tomado del archivo
		/*for (int i = 0; i < miLista.cont; i++) {

			cout << miLista.lista[i].codigo << " " << miLista.lista[i].precioDia << " " << miLista.lista[i].nombre << endl;
		}*/

		input.close();


		return true;
	}

	else return false;


}

bool LeerAlquileres(ListaAlquileres& listaAlq, ListaCoches& coches) {

	int number;
	ifstream input;

	input.open("rent.txt");


	if (input.is_open()) {
		input >> number;
		listaAlq.cont = number;
		listaAlq.tamano = number + 10;
		listaAlq.lista = new Alquiler[listaAlq.tamano];
		for (int i = 0; i < listaAlq.cont; i++) {

			input >> listaAlq.lista[i].codigo;
			listaAlq.lista[i].coche = buscarCoche(coches, listaAlq.lista[i].codigo);

			input >> listaAlq.lista[i].fecha;

			input >> listaAlq.lista[i].diasAlq;
		}
		input.close();
		return true;
	}

	else {
		input.close();
		return false;
	}
}

void ordenarAlquiler(ListaAlquileres& miLista) {

	sort(&miLista.lista[0], &miLista.lista[miLista.cont], comp);

}

bool comp(const Alquiler& lis1, const Alquiler& lis2) {

	return lis1.fecha < lis2.fecha;

}


Coche* buscarCoche(ListaCoches& lista, int cod) {


	int i = 0;
	while (i < lista.cont && cod != lista.lista[i].codigo) {
		i++;

	}
	if (i < lista.cont && lista.lista[i].codigo == cod)
		return &lista.lista[i];
	else
		return nullptr;

}

void mostrarAlquiler(ListaAlquileres& lista) {
	for (int i = 0; i < lista.cont; i++) {

		cout << lista.lista[i].fecha;

		if (lista.lista[i].coche != nullptr) {
			cout << " " << lista.lista[i].coche->nombre << " " << lista.lista[i].diasAlq << " dias por " << lista.lista[i].coche->precioDia * lista.lista[i].diasAlq << " euros" << endl;
		}
		else {
			cout << "  No hay ningun modelo asi" << endl;
		}


	}
}

