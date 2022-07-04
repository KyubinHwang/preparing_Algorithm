#include <iostream>
#include <vector>
using namespace std;
int n, m;
int result = 0;
vector <vector <int>> v(501);
bool visited[501];

void DFS(int friends, int dept){
    
    if(dept == 2)
        return;
    
    for(int i = 0;i < v[friends].size();i++){
        visited[v[friends][i]] = true;
        DFS(v[friends][i], dept + 1);
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int friend1, friend2;
        cin >> friend1 >> friend2;
        v[friend1].push_back(friend2);
        v[friend2].push_back(friend1);
    }
    
    visited[1] = true;
    DFS(1, 0);
    
    for(int i = 1;i <= n;i++){
        if(visited[i])
            result++;
    }
    
    cout << result - 1<< "\n";
    
    return 0;
}
