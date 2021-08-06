#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	string A;
	string B;
	
	cin >> A >> B;
	int n = A.size();
	int m = B.size();
	vector <vector<int>> LCS(n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				LCS[i][j] = 0;
			}
			else if (A[i - 1] == B[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}

	cout << LCS[n][m] << "\n";

}