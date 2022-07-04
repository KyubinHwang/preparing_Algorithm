#include <iostream>
#include <queue>
using namespace std;
int N, K;
int answer = 100000;
bool visited[100001];

void BFS(){
    queue<pair<int, int>> q;
    q.push({N , 0});
    visited[N] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == K){
            answer = cnt;
        }
        else{
            if(!visited[cur + 1] && cur + 1 >= 0 && cur + 1 <= 100000){
                q.push({cur + 1, cnt + 1});
                visited[cur + 1] = true;
            }
            if(!visited[cur - 1] && cur - 1 >= 0 && cur - 1 <= 100000){
                q.push({cur - 1, cnt + 1});
                visited[cur - 1] = true;
            }
            if(!visited[cur * 2] && cur * 2 >= 0 && cur * 2 <= 100000){
                q.push({cur * 2, cnt + 1});
                visited[cur * 2] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> K;
    BFS();
    
    cout << answer << "\n";
    
    return 0;
}
