#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int n;
	int result;
	cin >> n;
	int *array = new int[n];
	int *dp = new int[n];


	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	dp[0] = array[0];
	result = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + array[i], array[i]);
		result = max(dp[i], result);
	}

	cout << result <<"\n";
}