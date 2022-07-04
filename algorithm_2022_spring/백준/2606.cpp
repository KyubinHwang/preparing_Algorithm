#include <iostream>
#include <vector>
using namespace std;
vector <vector<int>> computer(101);
bool visited[101];
int N, T;
int result = 0;

void DFS (int n){
    visited[n] = true;
    
    for(int i = 0;i < computer[n].size();i++){
        if(!visited[computer[n][i]]){
            DFS(computer[n][i]);
            result++;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> T;
    
    for(int i = 0;i < T;i++){
        int com1, com2;
        cin >> com1 >> com2;
        computer[com1].push_back(com2);
        computer[com2].push_back(com1);
    }
    
    DFS(1);
    
    cout << result << "\n";
    
    return 0;
}
