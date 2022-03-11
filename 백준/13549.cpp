#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N, K;
int visited[100001];

void BFS(){
    queue <pair<int, int>> q;
    q.push({N, 0});
    visited[N] = 0;
    while(!q.empty()){
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        if(pos * 2 >= 0 && pos * 2 <= 100001 && visited[pos * 2] == -1){
            visited[pos * 2] = time;
            q.push({pos * 2, time});
        }
        if(pos - 1 >= 0 && pos - 1 <= 100001 && visited[pos - 1] == -1){
            visited[pos - 1] = time + 1;
            q.push({pos - 1, time + 1});
        }
        if(pos + 1 >= 0 && pos + 1 <= 100001 && visited[pos + 1] == -1){
            visited[pos + 1] = time + 1;
            q.push({pos + 1, time + 1});
        }
    }
}

int main(int argc, const char * argv[]) {
    
    memset(visited, -1, sizeof(visited));
    cin >> N >> K;
    
    BFS();
    
    cout << visited[K] << "\n";
    
    return 0;
}
