#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> v(51, vector<int>(51));
bool check[51][51];
int result = 0;
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int w, h;

void BFS(int W, int H){
    
    queue<pair<int, int>> q;
    q.push(make_pair(W, H));
    check[W][H] = true;
    result++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0;i < 8;i++){
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            if(tempX < 0 || tempX >= h || tempY < 0 || tempY >= w) continue;
            if(!check[tempX][tempY] && v[tempX][tempY] == 1){
                check[tempX][tempY] = true;
                q.push(make_pair(tempX, tempY));
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    while(1){
        cin >> w >> h;

        if(w == 0 && h == 0)
            break;

        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                int temp;
                cin >> temp;
                v[i][j] = temp;
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!check[i][j] && v[i][j] == 1){
                    BFS(i,j);
                }
            }
        }
        cout << result << "\n";
        
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                check[i][j] = false;
            }
        }

        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                v[i][j] = 0;
            }
        }
        result = 0;
    }

    return 0;
}
