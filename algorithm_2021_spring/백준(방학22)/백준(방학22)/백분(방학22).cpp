#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
char v[21][21];

int R, C;
int result = 1;
bool check[26];

void board(int x, int y, int dept) {
	
	check[v[x][y] - 65] = true;
	result = max(result, dept);
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i];
		int y2 = y + dy[i];

		if (x2 >= 0 && x2 < R && y2 >= 0 && y2 < C && !check[v[x2][y2] - 65]) {
			board(x2, y2, dept + 1);
			check[v[x2][y2] - 65] = false;
		}
	}
	
}

int main() {
	
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v[i][j] = s[j];
		}
	}
	
	board(0, 0, 1);
	cout << result << "\n";
	
}