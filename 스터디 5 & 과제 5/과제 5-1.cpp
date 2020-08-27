#include <iostream>
using namespace std;

int main(){
	
	int n;
	int a = 2;
	
	cin >> n;
	while (true){	
		if (n % a == 0)
		{
			n = n / a;
			cout << a << "\n";
			a = 2;
		}
		else
		{
			a++;
		}
		if (a > n)
		{
			break;
		}
	}

	return 0;

}
/*		else if (n == 1)
		{
			cout << n << "\n";
			break;
			}*/