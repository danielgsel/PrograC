#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;




int main() {
	int first[2][2] = { { 1,1 }, { 2, 2 } };

#include <iostream>
#include <string>
#include <vector>
#include <array>
	using namespace std;



	int summ(int first[2][2], int second[2][2]);
	int subs();
	int mul();
	int trans();
	void print(int printed[2][2]);
	int main();

	
	int main(); {
		int first[2][2];// = { { 1,1 }, { 2, 2 } };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				first[i][j] = i;
			}
		}
		//int second[2][2] = {3,3 ,4,4};

		//array <int, 5> puto;
		//array <int, 3>;
		//cout << sizeof(*first);
		print(first);
		system("pause");
	}
	//int second[2][2] = {3,3 ,4,4};

	//array <int, 5> puto;
	//array <int, 3>;
	//cout << sizeof(*first);
	print(first);
	system("pause");
}


int summ(int first[2][2], int second[2][2]) {
	return 0;
}

int subs() {
	return 0;
}

int mul() {

}

int trans() {

}
void print(int printed[2][2]) {
	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 2; j++) {
			cout << printed[i][j];
		}
		cout << endl;
	}
}