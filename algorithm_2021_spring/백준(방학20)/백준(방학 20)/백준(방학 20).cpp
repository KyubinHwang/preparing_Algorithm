#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;

int main() {

	int N;
	
	int result = 0;
	cin >> N;
	vector <vector <int>> lecture(N + 1, vector<int>(2));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> lecture[i][j];
		}
	}
	sort(lecture.begin(), lecture.end());
	pq.push(-lecture[0][1]);
	for (int i = 1; i < N; i++) {
		if (-pq.top() <= lecture[i][0]) {
			pq.pop();
		}
		pq.push(-lecture[i][1]);
	}

	cout << pq.size() << "\n";
}