#include <iostream>
using namespace std;

int main(){

	int burger[3];
	int drink[2];
	int cheapbur = 2001, cheapdrink = 2001;
	int sum;

	for (int i = 0; i < 3; i++){
		cin >> burger[i];
		if(cheapbur > burger[i])
			cheapbur = burger[i];
	}
	for (int j = 0; j < 2; j++){
		cin >> drink[j];
		if (cheapdrink > drink[j])
			cheapdrink = drink[j];
	}
	sum = cheapbur + cheapdrink;
	cout << sum - 50;

	return 0;

}