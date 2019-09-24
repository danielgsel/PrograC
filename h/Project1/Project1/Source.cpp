#include <fstream>
#include <iostream>
//#include <string>

using namespace std;

struct Coche {
	string nombre;
	int codigo;
	int precioDia;

};

struct Alquiler {

};

struct ListaCoches {
	Coche* lista;
	int tamaño;
	int elems;
};

bool cargarCoche(ListaCoches& miLista);
bool LeerRenta();

int main() {

	ListaCoches miLista;
	cargarCoche(miLista);

	
	
	return 1;
}


bool cargarCoche(ListaCoches& miLista) {
	int number;
	string linea;
	ifstream input;

	input.open("coches.txt");
	
	bool hola = input.is_open();
	input >> number;
	miLista.tamaño = number;
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

bool LeerRenta() {


	return true;
}
