#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	int N, K;
	int result = 0;

	cin >> N >> K;
	vector <int> v(N);
	for (int i = N - 1; i >= 0; i--) {
		cin >> v[i];
	}

	for (int i = 0; i < N; i++) {
		while (K - v[i] >= 0) {
			result++;
			K -= v[i];
		}
	}
	cout << result << '\n';
}