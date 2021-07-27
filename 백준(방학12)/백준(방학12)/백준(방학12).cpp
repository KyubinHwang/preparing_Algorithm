#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int M, N;
	cin >> M >> N;
	int *array = new int[N + 1];

	array[1] = 0;

	for (int i = 2; i <= N; i++) {
		array[i] = i;
	}

	for (int i = 2; i <= N; i++) {
		if (array[i] == 0)
			continue;
		int j = i + i;
		while (j <= N) {
			array[j] = 0;
			j += i;
		}
	}

	for (int i = M; i <= N; i++) {
		if (array[i] != 0)
			cout << array[i] << "\n";
	}

}