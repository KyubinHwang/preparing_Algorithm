#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int L, C;

void printing(vector <char> code) {

	int m = 0;

	for (int i = 0; i < L; i++) {
		if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u') {
			m++;
		}
	}
	if (m > 0 && (L - m) > 1) {
		for (int i = 0; i < L; i++) {
			cout << code[i];
		}
		cout << "\n";
	}
}

void makeCode(int r, int dept, vector <char> v, vector <char> code) {

	if (dept == L) {
		printing(code);
		return;
	}

	for (int i = r; i < C; i++) {
		code[dept] = v[i];
		makeCode(i + 1, dept + 1, v, code);
	}

}

int main() {
	
	char n;
	cin >> L >> C;
	vector <char> v(C);
	vector <char> code(L);

	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	makeCode(0, 0, v, code);

	return 0;
}