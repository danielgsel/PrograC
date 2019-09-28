#include <iostream>
#include <string>
#include <vector>
using namespace std;


void ShowVector(vector <int> v){

	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i);
	}
	cout << endl;
}
void FillVector(vector <int>& v){

	for (int i = 0; i < v.size(); i++)
	{
		cin >> v.at(i);
	}
}

int sumaPares(vector <int>& v){
	
	int sumatorio = 0;
	for (int i = 0; i < v.size(); i = i + 2){
		sumatorio = sumatorio + v.at(i);
	}

	return sumatorio;
}

int highestComponent(vector <int>& v){
	int higher = 0;
	for (int i = 0; i<v.size; i++){
		if (v.at(i)>higher){
			higher = v.at(i);
		}
	}

}

bool equal(vector <int>& v, vector <int>& w){
	bool igualdad = true;
	int i = 0;
	if (v.size != w.size){
		igualdad = false;
	}
	while (i < v.size && i < w.size && igualdad){
		i++;
	}

	return igualdad;
}

bool equalSumatory(vector <int>& v){
	bool sumatorio = false;
	int acumulacion = 0;
	int i = 0;
	while (!sumatorio && i < v.size){
		sumatorio = 0;
		for (int j = 0; j < v.size; j++){
			sumatorio = sumatorio + v.at(j);
		}
		if (acumulacion == v.at(i)){
			sumatorio = true;
		}
		i++;
	}
	return sumatorio;

}
void MoveVector(vector <int>& v){
	int aux = v.at(v.size() - 1);
	for (int i = v.size() - 1; i > 0; i--){
		v.at(i) = v.at(i - 1);
	}
	v.at(0) = aux;
}

bool repeated(vector<int>& v){
	bool repetido = false;
	int i = 0;
	int j = 0;
	int auxiliar;
	while (i < v.size && !repetido){
		auxiliar = v.at(i);
		j = i;
		while (j < v.size && !repetido){
			if (v.at(i) == v.at(j)){
				repetido = true;
			}
			j++;
		}
		
		i++;
	}
}

int main(){
	vector<int> v(5);
	FillVector(v);
	ShowVector(v);
	MoveVector(v);
	ShowVector(v);
	system("pause");
}

