#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Insertion(vector <string>& v, string words) {
	unsigned int longitud = words.length();
		string palabra = "";

		for (int i = 0; i < longitud; i++) {
			if (words.at(i) != ' '				) {
				palabra += words[i];
			}
			else {
				v.push_back(palabra);
				palabra = "";
			}

		}
		v.push_back(palabra);


}

void Print(const vector <string>& v) {

	for (unsigned int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " Con " << v.at(i).length() << " letras"<<endl;

	}
}

int main() {
	string palabras = "";
	vector <string> words;
	//string word = "";

	//Metodo la frase de golpe
	cout << "Escribe una frase";
	getline(cin, palabras);
	Insertion(words,palabras);
	Print(words);
	


	//Metodo palabra a palaba 
	/*while (palabras != " ") {
		cin >> palabras;
	    cout<< "La longitud de la palabra es ="<< palabras.length()<<endl;
		
	}*/
	
}