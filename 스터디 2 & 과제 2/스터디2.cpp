#include <iostream>
using namespace std;

int main(){

	int N;
	int k, l, T;
	int M = 101;
	int sum = 0;
	cin >> N;
	int S = N;

	while (S != M){
		k = N / 10;
		l = N % 10;
		T = k + l;
		if (T >= 10)
		{
			T = T - 10;
			N = (l * 10) + T;
			sum++;
		}
		else if ((T < 10) && (T > 0))
		{
			N = (l * 10) + T;
			sum++;
		}
		else if (T == 0)
			sum++;
		M = N;
	}
	cout << sum;

	return 0;
}