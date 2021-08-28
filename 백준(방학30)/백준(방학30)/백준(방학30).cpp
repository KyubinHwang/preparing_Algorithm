#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int square[1001][1001];
int dp[1001][1001];

int main() {

	int n, m;
	int result = 0;

	cin >> n >> m;
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &square[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
		dp[i][0] = square[i][0];

	for (int j = 0; j < m; j++)
		dp[0][j] = square[0][j];

	result = dp[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (square[i][j] == 1)
			{
				dp[i][j] = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + 1;
				result = max(result, dp[i][j]);
			}
		}
	}

	cout << result * result << "\n";

	return 0;
}
