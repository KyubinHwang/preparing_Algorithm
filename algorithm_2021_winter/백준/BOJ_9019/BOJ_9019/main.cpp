#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
bool visited[10000];
int A, B;

void BFS(){
    queue<pair<int, string>> q;
    q.push(make_pair(A, ""));
    visited[A] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        string opr = q.front().second;
        q.pop();
        if(cur == B){
            cout << opr << "\n";
            return;
        }
        
        int D = (cur * 2) % 10000;
        if(!visited[D]){
            visited[D] = true;
            q.push({D, opr + 'D'});
        }
        
        int S = cur - 1;
        if(S < 0)
            S = 9999;
        if(!visited[S]){
            visited[S] = true;
            q.push({S, opr + 'S'});
        }
        
        int L = (cur % 1000) * 10 + cur / 1000;
        if(!visited[L]){
            visited[L] = true;
            q.push({L, opr + 'L'});
        }
        
        int R = (cur / 10) + (cur % 10) * 1000;
        if(!visited[R]){
            visited[R] = true;
            q.push({R, opr + 'R'});
        }
        
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    
    while(T){
        cin >> A >> B;
        BFS();
        memset(visited, false, sizeof(visited));
        T--;
    }
    
    return 0;
}
