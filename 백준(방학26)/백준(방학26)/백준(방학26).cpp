#include <iostream>
#include <algorithm>
#define SIZE 1000000000
using namespace std;
long long dp[101][10];

int main() {
	
	int N;
	int result = 0;
	cin >> N;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][9] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= SIZE;
		}
	}

	for (int i = 0; i <= 9; i++) {
		result += dp[N][i];
		result %= SIZE;
	}
	cout << result << "\n";
}