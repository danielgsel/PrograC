#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;


const int fil = 2;
const int col = 2;


int summ(const int first[2][2], const int second[2][2], int result [2][2]){
	for (int i = 0; i < fil; i++) {

		for (int j = 0; j < col; j++) {
			result[i][j] = first[i][j] + second[i][j];
		}
	}
	
	return 0;
}

int subs(const int first[2][2], const int second[2][2], int result[2][2]){
	
	for (int i = 0; i < fil; i++) {

		for (int j = 0; j < col; j++) {
			result[i][j] = first[i][j] - second[i][j];
		}
	}
	return 0;
}

int mul(const int first[2][2], const int second[2][2], int result[2][2]) {
	
	int acumul = 0;
	for (int i = 0; i < fil; i++) {

		for (int j = 0; j < col; j++) {
			acumul = 0;
			for (int k = 0; k < col; k++) {
				acumul = acumul + (first[i][k] * second[k][j]);
			}
			result[i][j] = acumul;
		}
	}
	return 0;
}

int trans(const int first[2][2], int result[2][2]) {
	
	for (int i = 0; i < fil; i++) {

		for (int j = 0; j < col; j++) {
			result[j][i] = first[i][j];
		}
	}
	return 0;
}

void chair( int first[2][2], int result[2][2]) {

	bool leg = true;

	int p = 0;
	int q = 0;
	for (int i = 0; i < fil; i++) {

		for (int j = 0; j < col; j++) {
			p = 0;
			q = 0;
			leg = true;
			while (p < fil && leg) {
				if (first[p][j] > first[i][j]) {
					leg = false;
					result[i][j] = 0;
				}
				else {
					result[i][j] = first[i][j];
				}
				p++;
			}
				while (q<col && leg) {
					if (first[i][q] < first[i][j]) {
						leg = false;
						result[i][j] = 0;
					}
					else{
						result[i][j] = first[i][j];
					}
					q++;
				}
		}
	}
	
}

void print(int printed [2][2]){
	for (int i = 0; i < 2; i++){

		for (int j = 0; j < 2; j++){
			cout << printed[i][j];
		}
		cout << endl;
	}
	}


int main() {
	int first[2][2] = { { 1,-1 }, { 2, 0 } };
	int second[2][2] = { {3,3} ,{4,4} };
	int result[2][2] = { {0,0 }, {0, 0}};
   
	//summ(first, second, result);
	print(first);
	cout << endl;
	chair(first,result);
	print(result);
	system("pause");

	return 2;




}