#include <iostream>
using namespace std;

int main(){

	int N;
	int A[50], B[50];
	int S = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int j = 0; j < N; j++)
	{
		cin >> B[j];
	}

	for (int l = 0; l < N; l++)
	{
		S += A[l] * B[l];
	}

	cout << S;

	return 0;

}