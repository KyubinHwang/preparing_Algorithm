#include <iostream>
#include <vector>
using namespace std;
vector <int> V[1001];
vector <bool> check(1001);
int N, M;

void dfs(int T){
    check[T] = true;
    for(int i = 0;i < V[T].size();i++){
        if(check[V[T][i]] == false){
            dfs(V[T][i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int u, v;
    int result = 0;
    cin >> N >> M;
    
    for(int i = 0;i < M;i++){
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    
    for(int i = 1;i <= N;i++){
        if(check[i] == false){
            dfs(i);
            result++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
