#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int N, n;
	int sum = 1;
	int A[50] = { 0 };

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		A[i] = n;
	}
	
	if (N % 2 == 0)
	{
		sort(A, A + N);
		sum = A[(N / 2) - 1] * A[(N / 2)];
	}
	else if (N % 2 == 1)
	{
		sort(A, A + N);
		sum = A[(N / 2)] * A[(N / 2)];
	}

	cout << sum;

	return 0;

}