#include <iostream>
using namespace std;

int main(){

	int T;
	int A, B;
	int min = 1;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		if (A >= B)
		{
			for (int j = 1; j <= B; j++)
			{
				if ((A % j == 0) && (B % j == 0))
				{
					min = j;
				}
			}
		}
		else
		{
			for (int j = 1; j <= A; j++)
			{
				if ((A % j == 0) && (B % j == 0))
				{
					min = j;
				}
			}
		}
		A = A / min; B = B / min;
		cout << A*B*min <<"\n";
		min = 1;
	}

	return 0;

}