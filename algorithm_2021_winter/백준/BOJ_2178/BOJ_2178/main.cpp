#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int X[4] = {1, 0, -1, 0};
int Y[4] = {0, -1, 0, 1};
queue <pair <int, int>> q;
vector <vector<int>> v(101, vector<int>(101));
vector <vector<int>> visited(101, vector<int>(101, 1));

void BFS(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0;i < 4;i++){
            int dy = y + Y[i];
            int dx = x + X[i];
            if(dy >= 0 && dy < N && dx >= 0 && dx < M && v[dy][dx] != 0 && visited[dy][dx] == 1){
                q.push({dy, dx});
                visited[dy][dx] = visited[y][x] + 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> N >> M;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        for(int j = 0;j < M;j++){
            v[i][j] = s[j] - '0';
        }
    }
    visited[0][0] = 1;
    q.push({0,0});
    
    BFS();
    
    cout << visited[N - 1][M - 1] << "\n";
    
    return 0;
}
