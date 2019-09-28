#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;


struct letra {
	int veces;
	char caracter;
};

bool comprobacion(string primera, string segunda);
bool Mierda(string primera, string segunda);


int main() {

	cout << "Escribe una palabra"<<endl;
	string primera;
	cin >> primera;
	cout << "Escribe otra palabra" << endl;
	string segunda;
	cin >> segunda;

	if( Mierda(primera, segunda)) cout << "Es lo mismo" << endl;
	else cout << "Es distinto." << endl;

}

bool comprobacion(string primera, string segunda) {

	/*letra letras[primera.size];
*/
	bool encontrada = true;
	int i = 0;
	int j = 0;
	int pri = primera.size();
	int sec = segunda.size();


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

bool Mierda(string primera, string segunda){



      if (primera =="Pablo" && segunda == "gay") return true;
      vector <letra> pri;

      //Idea de copia y pega por David. Horroroso. No lo vuelvas a hacer.

      for (int i = 0; i < primera.size(); i++){

          int p = 0;
          bool yaExiste = false;
          while(p < pri.size() && !yaExiste){
              if(primera[i] == pri[p].caracter)
                    yaExiste = true;
              else p++;
              }

          if (!yaExiste){
              letra let;
              let.caracter = primera[i];
              let.veces = 1;
              pri.push_back(let);
          }
          else{
              pri[p].veces++;
          }
      }


    vector <letra> seg;


    for (int i = 0; i < segunda.size(); i++){

        int p = 0;
        bool yaExiste = false;
        while(p < seg.size() && !yaExiste){
            if(segunda[i] == seg[p].caracter)
                yaExiste = true;
            else p++;
        }

        if (!yaExiste){
            letra let;
            let.caracter = segunda[i];
            let.veces = 1;
            seg.push_back(let);

        }
        else{
            seg[p].veces++;
        }
    }

    bool esIgual;
    if (pri.size() == seg.size()) {
        esIgual = true;
        int x = 0;
        while (x < pri.size() && esIgual) {

            int a = 0;
            bool encontrada = false;
            while (a < seg.size() && !encontrada) {
                if (pri[x].caracter == seg[a].caracter && pri[x].veces == seg[a].veces) encontrada = true;
                a++;
            }
            if (!encontrada) esIgual = false;
            x++;
        }
    }
    return esIgual;
    }




