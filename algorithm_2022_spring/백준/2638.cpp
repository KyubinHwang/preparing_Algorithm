#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int cheese[101][101];
bool visited[101][101];
int check[101][101];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, -1, 0, 1};
bool melt = false;
queue <pair <int, int>> q;
int hour = 0;

void BFS(){
    hour++;
    q.push({0, 0});
    visited[0][0] = true;
    while(!q.empty()){
        int X = q.front().second;
        int Y = q.front().first;
        q.pop();
        
        for(int i = 0;i < 4;i++){
            int dx = X + x[i];
            int dy = Y + y[i];
            if(dy >= N || dy < 0 || dx >= M || dx < 0)
                continue;
            if(cheese[dy][dx] == 0 && !visited[dy][dx]){
                q.push({dy, dx});
                visited[dy][dx] = true;
            }
            if(cheese[dy][dx] == 1 && !visited[dy][dx]){
                check[dy][dx]++;
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++)
        {
            if(check[i][j] >= 2)
                cheese[i][j] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    
    cin >> N >> M;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> cheese[i][j];
        }
    }
    
    memset(check, 0, sizeof(check));
    
    while(!melt){
        melt = true;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                if(cheese[i][j] == 1)
                    melt = false;
            }
        }
        if(melt)
            break;
        BFS();
        memset(visited, false, sizeof(visited));
        memset(check, 0, sizeof(check));
    }
    
    cout << hour << "\n";
    
    return 0;
}
