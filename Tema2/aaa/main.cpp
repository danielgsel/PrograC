#include "fstream"




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

int main() {

	ListaCoches miLista;
	cargarCoche(miLista);

	return 1;
}


bool cargarCoche(ListaCoches& miLista) {
	int number;
	ifstream input;
	input.open("coches.txt");
	if (input.fail()) return false;
	else {
		input >> number;
		miLista.lista = new Coche[number];
		return true;
	}
	input.close();

	
}