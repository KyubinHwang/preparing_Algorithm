#include <iostream>
using namespace std;
bool gold[10001];

void primetest() {

	fill_n(gold, 10000, true);
	gold[0] = gold[1] = false;
	for (int i = 2; i < 5000; i++) {
		if (!gold[i]) continue;
		int temp = 2;
		while (i * temp < 10000) {
			gold[i * temp] = false;
			temp++;
		}
	}
}

void find(int n) {
	int n2 = n / 2;
	for (int i = n2; i > 1; i--) {
		if (!(gold[i] && gold[n - i])) continue;
		cout << i << " " << n - i << "\n";
		break;
	}
}

int main() {

	int T;
	int N;
	primetest();
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		find(N);
	}

	return 0;
}