#include <iostream>
using namespace std;

int main(){

	int N;
	int score[1000];
	int max = 0;
	double result = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}

	for (int j = 0; j < N; j++)
	{
		if (max < score[j])
		{
		    max = score[j]; 
		}
	}

	for (int l = 0; l < N; l++)
	{
		result += ((double)score[l] / max) * 100;
	}
	cout << fixed;
	cout.precision(1);

	cout << result / N;

	return 0;

}