#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    vector<vector<int>> visited(maps.size(), vector <int>(maps[0].size(), 1));
    queue <pair<int, int>> q;

    q.push({0, 0});
    while(!q.empty()){
        int YY = q.front().first;
        int XX = q.front().second;
        q.pop();

        for(int i = 0;i < 4;i++){
            int y = YY + dy[i];
            int x = XX + dx[i];
            if(y >= maps.size() || y < 0 || x >= maps[0].size() || x < 0)
                continue;
            if(visited[y][x] == 1 && maps[y][x] == 1){
                visited[y][x] = visited[YY][XX] + 1;
                q.push({y, x});
            }
        }
    }

    if (visited[visited.size() - 1][visited[0].size() - 1] == 1)
        return -1;
    else
        return visited[visited.size() - 1][visited[0].size() - 1];
}