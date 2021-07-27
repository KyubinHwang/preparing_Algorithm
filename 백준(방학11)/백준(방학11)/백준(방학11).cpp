#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool checkDFS[1001];
bool checkBFS[1001];

void DFS(int node, vector < vector <int> > v) {
	if (checkDFS[node])
		return;
	checkDFS[node] = true;
	cout << node << " ";
	for (int i = 0; i < v[node].size(); i++) {
		DFS(v[node][i], v);
	}
}

void BFS(int node, vector < vector <int> > v) {
	queue<int> q;
	q.push(node);
	checkBFS[node] = true;
	while (!q.empty()) {
		int x = q.front();
		cout << x << " ";
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (!checkBFS[v[x][i]]) {
				q.push(v[x][i]);
				checkBFS[v[x][i]] = true;
			}
		}
	}
}

int main() {

	int N, M, V;
	int point1, point2;
	cin >> N >> M >> V;
	vector < vector <int> > v(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> point1 >> point2;
		v[point1].push_back(point2);
		v[point2].push_back(point1);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	DFS(V, v);
	cout << "\n";
	BFS(V, v);
	cout << "\n";
}