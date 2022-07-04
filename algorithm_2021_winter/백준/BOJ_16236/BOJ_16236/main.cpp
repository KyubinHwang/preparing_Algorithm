#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int X[4] = {1, 0, -1, 0};
int Y[4] = {0, -1, 0, 1};
int space[21][21];
int check[21][21];
bool visited[21][21];
int babySharkX, babySharkY;
int N;
int sharkSize = 2;
int fishTaste = 0;
int second = 0;
int eatenFish = 0;

void BFS(int y, int x){
    
    int distance = 0;
    queue <pair <pair<int, int>, int>> q;
    q.push(make_pair(make_pair(y, x), distance));
    visited[y][x] = true;
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        if(space[y][x] > 0 && space[y][x] < sharkSize){
            eatenFish++;
            check[y][x] = dis;
        }
        for(int i = 0;i < 4;i++){
            int dy = y + Y[i];
            int dx = x + X[i];
            if(dy >= N || dy < 0 || dx >= N || dx < 0)
                continue;
            if(!visited[dy][dx] && space[dy][dx] <= sharkSize){
                visited[dy][dx] = true;
                q.push(make_pair(make_pair(dy, dx), dis + 1));
                
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> space[i][j];
            if(space[i][j] == 9)
            {
                babySharkY = i;
                babySharkX = j;
                space[i][j] = 0;
            }
        }
    }
    // 1단계 현재 상어가 먹을 수 있는 물고기들 있는지 탐색하고 위치랑 거리 기억하기
    // 2단계 먹을 수 있는 물고기들 중 가깝고 왼쪽 위에 있는 것을 우선으로 먹기 한턴에 한마리씩
    // 3단계 크기 변화 여부 확인하기
    // 4단계 턴 바꾸기 이 때 먹을 수 있는 물고기 없으면 탈출해서 걸린 시간 출력
    while(1){
        BFS(babySharkY, babySharkX);
        if(eatenFish == 0)
            break;
        int minDis = -1;
        int y = 0;
        int x = 0;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(check[i][j] != 0){
                    if(minDis == -1){
                        minDis = check[i][j];
                        y = i; x = j;
                    }
                    else if (check[i][j] < minDis){
                        minDis = check[i][j];
                        y = i; x = j;
                    }
                }
            }
        }
        second += minDis;
        space[y][x] = 0;
        babySharkY = y; babySharkX = x;
        eatenFish = 0;
        fishTaste++;
        if(fishTaste == sharkSize){
            sharkSize++;
            fishTaste = 0;
        }
        memset(visited, false, sizeof(visited));
        memset(check, 0, sizeof(check));
    }
    
    cout << second << "\n";
    
    return 0;
}
