#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;


struct letra {
	int veces;
	char letra;
};

bool comprobacion(string primera, string segunda);

int main() {

	cout << "Escribe una palabra"<<endl;
	string primera;
	cin >> primera;
	cout << "Escribe otra palabra" << endl;
	string segunda;
	cin >> segunda;

	cout << comprobacion(primera, segunda);
	system("pause");
}

bool comprobacion(string primera, string segunda) {

	/*letra letras[primera.size];
*/
	bool encontrada = true;
	int i = 0;
	int j = 0;
	int pri = primera.size;
	int sec = segunda.size;


	while (i < pri && encontrada) {

		encontrada = false;
		j = 0;
		while (j < sec && !encontrada) {
			if (primera[i] == segunda[j]) {
				encontrada = true;
			}
			j++;
		}
		i++;
	}

	return encontrada;
}

