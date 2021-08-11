#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long dp[101];

int main() {

	int T, N;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 4; j <= N; j++) {
			dp[j] = dp[j - 3] + dp[j - 2];
		}
		cout << dp[N] << "\n";
	}
}