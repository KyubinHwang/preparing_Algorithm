#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
vector<pair<int, int> > graph[20001];
int V, E, K;
int shortestPath[20001];

void dijkstra(int start){
    priority_queue <pair<int, int>> pq;
    
    pq.push({0, start});
    shortestPath[start] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(shortestPath[now] < cost)
            continue;
        for(int i = 0;i < graph[now].size();i++){
            int distance = cost + graph[now][i].second;
            if(distance < shortestPath[graph[now][i].first]){
                shortestPath[graph[now][i].first] = distance;
                pq.push(make_pair(-shortestPath[graph[now][i].first], graph[now][i].first));
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E;
    cin >> K;
    
    for(int i = 1;i <= E;i++){
        int temp1, temp2;
        int w;
        cin >> temp1 >> temp2 >> w;
        graph[temp1].push_back({temp2, w});
    }
    
    fill(shortestPath, shortestPath + 20001, INF);
    dijkstra(K);
    
    for(int i = 1;i <= V;i++){
        if(shortestPath[i] == INF)
            cout << "INF\n";
        else
            cout << shortestPath[i] << "\n";
    }
    
    return 0;
}
