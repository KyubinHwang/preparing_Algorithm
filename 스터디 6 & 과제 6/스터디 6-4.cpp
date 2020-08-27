#include <iostream>
using namespace std;

int main(){

	int N;
	int A, B, C;
	int sum = 0;
	int count = 0;
	int i = 0;

	cin >> N;

	if (N < 100)
	{
		sum = N;
	}
	else
	{
		for (i = 100; i <= N; i++)
		{
			A = i / 100;
			B = (i % 100) / 10;
			C = (i % 100) % 10;

			if ((B - A) == (C - B))
			{
				count++;
			}
		}
		sum = 99 + count;
	}

	cout << sum;
	
	return 0;

}