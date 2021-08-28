#include <iostream>
#include <algorithm>
using namespace std;
int Queen[15];
int N;
int result = 0;

bool check(int n) {

	for (int i = 0; i < n; i++) {
		if (Queen[n] == Queen[i] || (n - i) == abs(Queen[n] - Queen[i]))
			return false;
	}

	return true;
}

void backtrack(int n) {
	if (n == N)
	{
		result++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			Queen[n] = i;
			if (check(n))
				backtrack(n + 1);
		}
	}
}

int main() {

	cin >> N;
	backtrack(0);

	cout << result << "\n";

	return 0;
}
