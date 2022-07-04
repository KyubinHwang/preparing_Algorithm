#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T, M, N, K;
int X[4] = {0, 1, 0, -1};
int Y[4] = {-1, 0, 1, 0};
bool visited[50][50];

void BFS(int v[50][50], int Ty, int Tx){
    
    queue<pair<int, int>> q;
    q.push({Tx, Ty});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visited[Ty][Tx] = true;
        q.pop();
        for(int i = 0;i < 4;i++){
            int tempX = x + X[i];
            int tempY = y + Y[i];
            if(tempX >= 0 && tempY >= 0 && tempX < M && tempY < N && visited[tempY][tempX] == false && v[tempY][tempX] == 1){
                q.push({tempX, tempY});
                visited[tempY][tempX] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result = 0;
    cin >> T;
    
    for(int i = 0;i < T;i++){
        cin >> M >> N >> K;
        int v[50][50] = { 0 };
        
        for(int i = 0;i < 50;i++){
            for(int j = 0;j < 50;j++){
                visited[i][j] = false;
            }
        }
        for(int i = 0;i < K;i++){
            int x, y;
            cin >> x >> y;
            v[y][x] = 1;
        }
        
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                if(v[i][j] == 1 && visited[i][j] == false){
                    BFS(v, i, j);
                    result++;
                }
            }
        }
        
        cout << result << "\n";
        result = 0;
    }
    
    return 0;
}
