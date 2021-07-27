#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	
	int N;
	int result = 0;
	cin >> N;
	vector <int> A(N);
	vector <int> dp(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}

	cout << result << "\n";
}