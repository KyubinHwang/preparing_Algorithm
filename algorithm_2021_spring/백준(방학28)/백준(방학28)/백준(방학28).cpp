#include <iostream>
using namespace std;
long long A, B, C;
int result = 0;

long long power(long long x) {

	long long temp;

	if (x == 0)
		return 1;
	if (x % 2 == 1) {
		return A * power(x - 1) % C;
	}
	else {
		temp = power(x / 2);
		return temp * temp % C;
	}
}

int main() {

	cin >> A >> B >> C;

	cout << power(B) << "\n";

	return 0;
}