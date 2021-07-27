#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int k;
vector <int> lottonum(6);

void printing() {
	for (int i = 0; i < 6; i++) {
		cout << lottonum[i] << " ";
	}
	cout << "\n";
}

void lotto(int n, int dept, vector <int> S) {
	
	if (dept == 6) {
		printing();
		return;
	}

	for (int i = n; i < k; i++) {
		lottonum[dept] = S[i];
		lotto(i + 1, dept + 1, S);
	}
}


int main() {

	
	while (1)
	{
		cin >> k;
		vector <int> S(k);

		if (k == 0) {
			break;
		}
		else {
			for (int i = 0; i < k; i++) {
				cin >> S[i];
			}
			lotto(0, 0, S);
		}

		cout << "\n";
	}
	return 0;

}