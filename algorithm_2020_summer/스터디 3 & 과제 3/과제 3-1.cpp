#include <iostream>
using namespace std;

int main(){

	int num[10];
	int count = 0;
	int a[42] = {};
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
		num [i] = num[i] % 42;
	}

	for (int j = 0; j < 10; j++)
	{
		for (int l = 0; l < 42; l++)
		{
			if (num[j] == l){ a[l] = 1; }
		}
	}
	for (int t = 0; t < 42; t++)
	{
		if (a[t] > 0){ count++; }
	}
	cout << count;

	return 0;

}