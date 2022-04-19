#include <string>
#include <vector>
using namespace std;
char place_temp[5][5];
bool visited[5][5];
int X[4] = {1, 0, -1, 0};
int Y[4] = {0, -1, 0, 1};
bool check = true;

void DFS(int dept, int x, int y){
    if(dept == 2)
    {
        if(place_temp[y][x] == 'P'){
            check = false;
        }
        return;
    }
    for(int i = 0;i < 4;i++){
        int dy = y + Y[i];
        int dx = x + X[i];
        if(dy > 4 || dy < 0 || dx > 4 || dx < 0)
            continue;
        if(!visited[dy][dx] && place_temp[dy][dx] == 'O'){
            visited[dy][dx] = true;
            DFS(dept + 1, dx, dy);
            visited[dy][dx] = false;
        }
        if(!visited[dy][dx] && place_temp[dy][dx] == 'P'){
            check = false;
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            string seat = places[i][j];
            for(int l = 0;l < 5;l++){
                place_temp[j][l] = seat[l];
            }
        }
        for(int j = 0;j < 5;j++){
            for(int l = 0;l < 5;l++){
                if(place_temp[j][l] == 'P')
                {
                    visited[j][l] = true;
                    DFS(0, l, j);
                    visited[j][l] = false;
                }
            }
        }

        if(check)
            answer.push_back(1);
        else
            answer.push_back(0);

        check = true;
    }

    return answer;
}
