#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXIN = 100000;
vector < vector <int> > v;
int dp[2][MAXIN + 1];
int temp[2][MAXIN + 1];

int sticker(int T) {

	dp[0][0] = temp[0][0];
	dp[1][0] = temp[1][0];
	dp[0][1] = temp[0][1] + temp[1][0];
	dp[1][1] = temp[1][1] + temp[0][0];
	for (int i = 2; i < T; i++) {
		dp[0][i] = temp[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = temp[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	return max(dp[0][T - 1], dp[1][T - 1]);
}

int main() {
	int N;
	int T;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T;
		for (int l = 0; l < 2; l++) {
			for (int j = 0; j < T; j++) {
				cin >> temp[l][j];
			}
		}
		cout << sticker(T) << "\n";
	}
}