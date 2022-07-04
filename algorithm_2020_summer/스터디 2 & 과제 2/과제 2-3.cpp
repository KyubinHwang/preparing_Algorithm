#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int n[1000];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> n[i];

	sort(n, n + N);

	for (int t = 0; t < N; t++)
		cout << n[t] << endl;

	return 0;

}