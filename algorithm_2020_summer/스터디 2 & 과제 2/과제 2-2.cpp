#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int i = 1;
	int count = 1;
	int S = 1;
	cin >> n;

	while (n > S){
		S += 6 * i;
		count++;
		i++;
	}
	cout << count;

	return 0;
}