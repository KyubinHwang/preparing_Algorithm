#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main() {

	char str1[4001];
	char str2[4001];
	int result = 0;

	cin >> str1 >> str2;
	
	int n = strlen(str1);
	int m = strlen(str2);
	vector <vector <int>> v(n + 1, vector <int> (m + 1));

	for (int i = 0; i <= n; i++) {
		v[i][0] = 0;
	}
	for (int j = 0; j <= m; j++) {
		v[0][j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
				result = max(result, v[i][j]);
			}
			else
				v[i][j] = 0;
		}
	}

	cout << result << "\n";
}