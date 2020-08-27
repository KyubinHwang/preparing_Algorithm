#include <iostream>
using namespace std;

int main(){

	int N[9];
	int M = 0;
	int m = 0;

	for (int i = 0; i < 9; i++){
		cin >> N[i];
	}
	
	for (int j = 1; j <= 9; j++){
		if (M < N[j - 1]){
			M = N[j - 1];
			m = j;
		}
	}

	cout << M << "\n" << m;

	return 0;

}