#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N, K;

	cin >> N >> K;
	int W[101];
	int V[101];
	int dp[100001] = {0 ,};

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (W[i] <= j) {
				dp[j] = max(dp[j],dp[j-W[i]] + V[i]);
			}
		}
	}

	cout << dp[K] << "\n";

}