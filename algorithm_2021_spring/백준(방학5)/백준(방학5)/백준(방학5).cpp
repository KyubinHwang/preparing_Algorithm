#include <iostream>
using namespace std;
	
int main() {
	
	int tmp[1001];
	int N, K;
	int count = 0;
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		tmp[i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; i*j <= N; j++) {
			if (tmp[i * j] == 1) {
				tmp[i * j] = 0;
				count++;
				if (count == K) {
					cout << i* j << endl;
					return 0;
				}
			}
		}
	}
}