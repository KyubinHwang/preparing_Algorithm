#include <iostream>
#include <vector>
using namespace std;
vector<vector <pair<int, int>>> town(51);
int visited[51] = {0, };

void DFS(int n, int dept, int K){
    for(int i = 0;i < town[n].size();i++){
        int x = town[n][i].first;
        int w = town[n][i].second;
        if(dept + w > K)
            continue;
        if (visited[x] != 0 && visited[x] <= dept + w) 
            continue;
        if(x != 1){
            if(visited[x] == 0)
                visited[x] = dept + w;
            else
                visited[x] = min(visited[x], dept + w);
            DFS(x, dept + w, K);
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i = 0;i < road.size();i++){
        town[road[i][0]].push_back({road[i][1], road[i][2]});
        town[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    visited[1] = 0;
    DFS(1, 0, K);

    for(int i = 1; i <= N;i++){
        if(visited[i] <= K && visited[i] != 0)
            answer++;
    }

    return answer + 1;
}
