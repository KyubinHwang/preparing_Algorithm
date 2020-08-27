#include <iostream>
using namespace std;

int Findsosu(int NUM){

	int S = 0;
	for (int i = 1; i <= NUM; i++){
		if (NUM % i == 0){
			S++;
		}
	}
	if (S == 2)
		return true;
	else
		return false;

}


int main(){

	int N;
	int arr[100];
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for (int j = 0; j < N; j++){
		if (Findsosu(arr[j]) == 1)
		{
			sum++;
		}
	}

	cout << sum;

	return 0;

}