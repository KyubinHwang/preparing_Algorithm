#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


void hanoi(int n, int first, int mid, int last) {
	if (n == 1)
		printf("%d %d\n", first, last); 
	else {
		hanoi(n - 1, first, last, mid);
		printf("%d %d\n", first, last);
		hanoi(n - 1, mid, first, last);
	}
}

int main() {
	
	int N;
	cin >> N;
	int count = pow(2, N) - 1;
	printf("%d\n", count);
	hanoi(N, 1, 2, 3);
}