#include <iostream>
#include <string>
using namespace std;

int main(){

	int N;
	string num;
	int sum = 0;

	cin >> N;
	cin >> num;

	for (int j = 0; j < N; j++)
	{
		char number = num[j];
		int nim = number - '0';
		sum += nim;
	}

	cout << sum;

}