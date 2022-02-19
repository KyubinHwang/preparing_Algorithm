#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int box[101][101][101];
int visited[101][101][101];
int M, N, H;
int X[6] = {1, 0, -1, 0, 0, 0};
int Y[6] = {0, -1, 0, 1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};
queue <tuple <int,int,int>> q;

void BFS(){
    
    while(!q.empty()){
        int z = get<0>(q.front());
        int y = get<1>(q.front());
        int x = get<2>(q.front());
        q.pop();
        
        for(int i = 0;i < 6;i++){
            int dz = z + Z[i];
            int dy = y + Y[i];
            int dx = x + X[i];
            if(dx < M && dx >= 0 && dy < N && dy >=0 && dz >= 0 && dz < H && visited[dz][dy][dx] == -1 && box[dz][dy][dx] == 0){
                q.push(make_tuple(dz,dy,dx));
                visited[dz][dy][dx] = visited[z][y][x] + 1;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {

    int answer = 0;
    cin >> M >> N >> H;
    
    for(int i = 0;i < H;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < M;k++){
                cin >> box[i][j][k];
                visited[i][j][k] = -1;
                if(box[i][j][k] == 1){
                    q.push(make_tuple(i, j, k));
                    visited[i][j][k]++;
                }
            }
        }
    }
    
    BFS();
    
    for(int i = 0;i < H;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < M;k++){
                if(visited[i][j][k] == -1 && box[i][j][k] == 0){
                    answer = -1;
                    break;
                }
                if(visited[i][j][k] >= answer)
                    answer = visited[i][j][k];
            }
            if(answer == -1)
                break;
        }
        if(answer == -1)
            break;
    }
    
    cout << answer << "\n";
    
    return 0;
}
