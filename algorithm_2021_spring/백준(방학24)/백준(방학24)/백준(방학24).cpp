#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {

	int N, K;
	int count = 0;
	string num;
	vector <int> s;
	vector <int> result;

	cin >> N >> K;
	cin >> num;
	for (int i = 0; i < N; i++) {
		int numI = (int)num[i] - 48;
		s.push_back(numI);
	}
	if (N == K)
		return 0;
	int t = K;
	for (int i = 0; i < s.size(); i++) {
		while (t > 0 && !result.empty() && result.back() < s[i]) {
			result.pop_back();
			t--;
		}
		if (i == s.size() - 1 && result.size() == (N - K))
			break;
		else {
			result.push_back(s[i]);
		}
	}
	for (int i = 0; i < N - K; i++) {
		cout << result[i];
	}
	cout << "\n";
}