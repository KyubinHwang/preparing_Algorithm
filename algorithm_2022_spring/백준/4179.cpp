#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char maze[1001][1001];
int visitedJ[1001][1001];
int visitedF[1001][1001];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, -1, 0, 1};
int R, C;
int jPlaceX, jPlaceY;
int result = -1;
bool check = false;
queue <pair <int, int>> fireQ;

void BFS(){
    
    queue <pair<int, int>> q;
    q.push({jPlaceY, jPlaceX});
    visitedJ[jPlaceY][jPlaceX] = 0;
    while(!q.empty()){
        int dx = q.front().second;
        int dy = q.front().first;
        q.pop();
        for(int i = 0;i < 4;i++){
            int tempX = dx + x[i];
            int tempY = dy + y[i];
            if(tempX < 0 || tempX >= C || tempY < 0 || tempY >= R)
                continue;
            if(maze[tempY][tempX] != '#' && visitedJ[tempY][tempX] == -1){
                visitedJ[tempY][tempX] = visitedJ[dy][dx] + 1;
                q.push({tempY, tempX});
            }
        }
    }
    
    while(!fireQ.empty()){
        int dx = fireQ.front().second;
        int dy = fireQ.front().first;
        fireQ.pop();
        for(int i = 0;i < 4;i++){
            int tempX = dx + x[i];
            int tempY = dy + y[i];
            if(tempX < 0 || tempX >= C || tempY < 0 || tempY >= R)
                continue;
            if(maze[tempY][tempX] != '#' && visitedF[tempY][tempX] == -1){
                visitedF[tempY][tempX] = visitedF[dy][dx] + 1;
                fireQ.push({tempY, tempX});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> R >> C;
    
    memset(visitedF, -1, sizeof(visitedF));
    memset(visitedJ, -1, sizeof(visitedJ));
    
    for(int i = 0;i < R;i++){
        string way;
        cin >> way;
        for(int j = 0;j < C;j++){
            maze[i][j] = way[j];
            if(maze[i][j] == 'J'){
                jPlaceX = j;
                jPlaceY = i;
            }
            else if(maze[i][j] == 'F'){
                visitedF[i][j] = 0;
                fireQ.push({i, j});
            }
        }
    }
   
    BFS();
    
    for(int i = 0;i < R;i++){
        if((visitedJ[i][0] != -1 && visitedJ[i][0] < visitedF[i][0]) || (visitedJ[i][0] != -1 && visitedF[i][0] == -1)){
            check = true;
            if(result == -1)
                result = visitedJ[i][0] + 1;
            else
                result = min(result, visitedJ[i][0] + 1);
        }
    }
    for(int i = 0;i < R;i++){
        if((visitedJ[i][C - 1] != -1 && visitedJ[i][C - 1] < visitedF[i][C - 1]) || (visitedJ[i][C - 1] != -1 && visitedF[i][C - 1] == -1)){
            check = true;
            if(result == -1)
                result = visitedJ[i][C - 1] + 1;
            else
                result = min(result, visitedJ[i][C - 1] + 1);
        }
    }
    for(int j = 0;j < C;j++){
        if((visitedJ[0][j] != -1 && visitedJ[0][j] < visitedF[0][j]) || (visitedJ[0][j] != -1 && visitedF[0][j] == -1)){
            check = true;
            if(result == -1)
                result = visitedJ[0][j] + 1;
            else
                result = min(result, visitedJ[0][j] + 1);
        }
    }
    for(int j = 0;j < C;j++){
        if((visitedJ[R - 1][j] != -1 && visitedJ[R - 1][j] < visitedF[R - 1][j]) || (visitedJ[R - 1][j] != -1 && visitedF[R - 1][j] == -1)){
            check = true;
            if(result == -1)
                result = visitedJ[R - 1][j] + 1;
            else
                result = min(result, visitedJ[R - 1][j] + 1);
        }
    }

//    for(int i = 0;i < R;i++){
//        for(int j = 0;j < C;j++){
//            cout << visitedJ[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//    for(int i = 0;i < R;i++){
//        for(int j = 0;j < C;j++){
//            cout << visitedF[i][j] << " ";
//        }
//        cout << "\n";
//    }
    
    if(R == 1 && C == 1 && maze[0][0] == 'J')
    {
        cout << 1 <<"\n";
        return 0;
    }
    
    if(check)
        cout << result << "\n";
    else
        cout << "IMPOSSIBLE" << "\n";
    
    return 0;
}
