#include <fstream>
#include <iostream>
#include "Date.h"
#include <algorithm>
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
	Coche* coche;
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


bool comp(Alquiler lis1, Alquiler lis2);
bool cargarCoche(ListaCoches& miLista);
bool LeerAlquileres(ListaAlquileres& listaAlq,ListaCoches& coches);
Coche* buscarCoche(ListaCoches& lista, int cod);
void mostrarAlquiler(ListaAlquileres& lista,ListaCoches& coches);
void ordenarAlquiler(ListaAlquileres& miLista);

int main() {

	ListaCoches listaCoches;
	ListaAlquileres listaAlq;
	cargarCoche(listaCoches);
	LeerAlquileres(listaAlq,listaCoches);
	ordenarAlquiler(listaAlq);

	cout << endl<<endl;
	
	mostrarAlquiler(listaAlq,listaCoches);
	
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
	miLista.elems = number;
		miLista.lista = new Coche[number];

		for (int i = 0; i < number; i++) {
			//linea = input.getline;
			input >> miLista.lista[i].codigo;
			input >> miLista.lista[i].precioDia;
			input >> miLista.lista[i].nombre;
			string segnom;
			input >> segnom;
			miLista.lista[i].nombre += " "+segnom;
		}

		for (int i = 0; i < number; i++) {

			cout << miLista.lista[i].codigo << " " << miLista.lista[i].precioDia << " " << miLista.lista[i].nombre << endl;
		}

		input.close();


		return true;
	}

	else return false;


}

bool LeerAlquileres(ListaAlquileres& listaAlq, ListaCoches& coches) {

	int number;
	ifstream input;
	string basura;// este string esta para sudar de los / del archivo al leer la fecha

	input.open("rent.txt");
	
	bool open = input.is_open();
	if (open){
		input >> number;
		listaAlq.lista = new Alquiler[number];
		listaAlq.elems = number;
		for (int i = 0; i < number; i++) {
			input >> listaAlq.lista[i].codigo;
			listaAlq.lista[i].coche = buscarCoche(coches,listaAlq.lista[i].codigo);

			int day, month, year;
			input >> day;
			input.get();
			input >> month;
			input.get();
			input >> year;

			listaAlq.lista[i].fecha = new Date(day, month, year);

			input >> listaAlq.lista[i].diasAlq;

		}




	return true;}
	else return false;
}

void ordenarAlquiler(ListaAlquileres& miLista) {

	sort(&miLista.lista[0],&miLista.lista[miLista.elems],comp);

}

bool comp(Alquiler lis1, Alquiler lis2) {

	return(Date::operator<( &lis1.fecha,&lis2.fecha));

}


Coche* buscarCoche(ListaCoches& lista ,int cod) {

	//Coche* buscado = nullptr;
	int i = 0;
	while (i < lista.elems && cod != lista.lista[i].codigo) {
		i++;
		//buscado = &lista.lista[i];
	}
	if (i<=lista.elems && lista.lista[i].codigo == cod)
		return &lista.lista[i];
	else
		return nullptr;

}

void mostrarAlquiler(ListaAlquileres& lista, ListaCoches& coches) {
		Coche* actual = nullptr;
	for (int i = 0; i < lista.elems; i++) {
		actual = buscarCoche(coches,lista.lista[i].codigo);
		
		if (actual != nullptr) {
			lista.lista[i].fecha->print();
			cout << " " << actual->nombre << " " << lista.lista[i].diasAlq << "dias por " << actual->precioDia << " euros" << endl;
		}
		
		
	}
}


