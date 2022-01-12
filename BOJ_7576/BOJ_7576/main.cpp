#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int M, N;
int visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector <vector<int>> v(1001, vector<int>(1001));
queue<pair<int, int>> q;

void BFS(){
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0;i < 4;i++){
            int tempY = y + dy[i];
            int tempX = x + dx[i];
            if(tempX >=0 && tempY >= 0 && tempX < M && tempY < N && visited[tempY][tempX] == -1 && v[tempY][tempX] == 0){
                q.push({tempY, tempX});
                visited[tempY][tempX] = visited[y][x] + 1;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {

    int result = 0;
    cin >> M >> N;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> v[i][j];
            visited[i][j] = -1;
            if(v[i][j] == 1){
                q.push({i, j});
                visited[i][j]++;
            }
        }
    }
    BFS();
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(v[i][j] == 0 && visited[i][j] == -1){
                result = -1;
                break;
            }
            if(visited[i][j] >= result)
                result = visited[i][j];
        }
        if(result == -1)
            break;
    }
    
    cout << result << "\n";
    
    return 0;
}
