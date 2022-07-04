#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
bool check = true;
vector <char> result;
stack<int> s;

int main() {
	int n;
	int x;
	int temp = 0;
	cin >> n;

	while (n > 0) {
		cin >> x;
		if (x > temp) {
			for (int i = temp + 1; i <= x; i++) {
				s.push(i);
				result.push_back('+');
			}
			temp = x;
		}
		else {
			if (s.top() != x) {
				check = false;
			}
		}
		s.pop();
		result.push_back('-');
		n--;
		temp = max(x, temp);
	}
	if (check) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
	else
		cout << "NO\n";
	
}