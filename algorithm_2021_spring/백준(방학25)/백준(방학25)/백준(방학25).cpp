#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int dp[1001][1001];
string L[1001][1001];

int main() {
	
	string LCS1;
	string LCS2;

	cin >> LCS1 >> LCS2;

	int n1 = LCS1.length();
	int n2 = LCS2.length();

	for (int i = 0; i <= n1; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= n2; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (LCS1[i - 1] == LCS2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				L[i][j] = L[i][j] + L[i - 1][j - 1] + LCS1[i - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (L[i - 1][j].length() > L[i][j - 1].length()) {
					L[i][j] = L[i - 1][j];
				}
				else
					L[i][j] = L[i][j - 1];
			}
		}
	}
	cout << dp[n1][n2] << "\n";
	cout << L[n1][n2] << "\n";
}