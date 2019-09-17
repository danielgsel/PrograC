#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool compare(char first[5], char second[5]){
	bool found = true;
	int i = 0;
	int j = 0;
	char compare;
	while (i<5 && found){
		compare = first[i];
		found = false;
		j = 0;
		while (j < 6 && !found){
			if (compare == second[j]){
				found = true;
			}
			j++;
		}
		i++;
	}


	return found;
}
int main(){
	char first[5] = { 'a', 'b', 'e', 'x', 'f' };
	char second[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	cout << ((sizeof(second) / (sizeof(*second)))) << endl;
	cout << compare(first, second) <<endl;
	system("pause");
}