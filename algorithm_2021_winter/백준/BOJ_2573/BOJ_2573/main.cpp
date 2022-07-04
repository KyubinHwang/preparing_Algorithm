#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int ice[301][301];
bool visited[301][301];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, -1, 0, 1};
int answer = 0;

void BFS(queue<pair <int, int>> q){
    
    while(!q.empty()){
        int count = 0;
        int tempY = q.front().first;
        int tempX = q.front().second;
        q.pop();
        for(int i = 0;i < 4;i++){
            int dy = tempY + y[i];
            int dx = tempX + x[i];
            if(ice[dy][dx] == 0 && !visited[dy][dx]){
                count++;
            }
            if(ice[dy][dx] != 0 && !visited[dy][dx]){
                q.push({dy, dx});
                visited[dy][dx] = true;
            }
        }
        if(count >= ice[tempY][tempX]){
            ice[tempY][tempX] = 0;
        }
        else
            ice[tempY][tempX] -= count;
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> ice[i][j];
        }
    }
    
    int island = 0;
    
    while(island == 0){
        queue <pair <int, int>> q;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                if(ice[i][j] != 0 && !visited[i][j]){
                    q.push({i, j});
                    visited[i][j] = true;
                    BFS(q);
                    island++;
                }
            }
        }
        if(island != 1)
        {
            if(island >= 2)
                break;
            else
            {
                answer = 0;
                break;
            }
        }
        else{
            island = 0;
            answer++;
        }
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                visited[i][j] = false;
            }
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
