#include <iostream>
#include <algorithm>
using namespace std;
int dp[301];
int arr[301];

int main() {
	int stairs;

	cin >> stairs;
	for (int i = 1; i <= stairs; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1], arr[2]) + arr[3];

	for (int i = 4; i <= stairs; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}

	cout << dp[stairs] << endl;

	return 0;
}