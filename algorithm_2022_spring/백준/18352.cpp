#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define SIZE 300001
using namespace std;
int N, M, K, X;
vector<vector<int>> v(SIZE);
int result[SIZE];
bool visited[300001];

void BFS(){
    
    queue<int> q;
    q.push(X);
    
    while(!q.empty()){
        int way = q.front();
        q.pop();
        
        for(int i = 0;i < v[way].size();i++){
            int temp = v[way][i];
            if(!visited[temp]){
                visited[temp] = true;
                result[temp] = result[way] + 1;
                q.push(temp);
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    cin >> N >> M >> K >> X;
    
    for (int i = 0;i < M;i++){
        int city1, city2;
        cin >> city1 >> city2;
        v[city1].push_back(city2);
    }
    memset(result, 0, sizeof(result));
    visited[X] = true;
    BFS();
    
    bool check = false;
    for(int i = 1;i <= N;i++){
        if(result[i] == K){
            cout << i << "\n";
            check = true;
        }
    }
    
    if(!check)
        cout << -1 << "\n";
    
    return 0;
}
