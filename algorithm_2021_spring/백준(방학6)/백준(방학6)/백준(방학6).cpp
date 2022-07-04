#include <iostream>
#include <algorithm>
using namespace std;
int countzero[41];
int countone[41];


int main() {

	int T;
	int t;
	cin >> T;
	countzero[0] = 1;
	countzero[1] = 0;
	countone[0] = 0;
	countone[1] = 1;
	for (int i = 0; i < T; i++) {
		cin >> t;
		for (int j = 2; j <= t; j++) {
			countzero[j] = countzero[j - 2] + countzero[j - 1];
			countone[j] = countone[j - 2] + countone[j - 1];
		}
		cout << countzero[t] << " " << countone[t] << endl;
	}
}