#include <string>
using namespace std;
bool visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    int y = 5; int x = 5;

    for(int i = 0;i < dirs.length();i++){
        if (dirs[i] == 'U'){
            if(y - 1 < 0)
                continue;
            if(!visited[y][x][y - 1][x]){
                visited[y][x][y - 1][x] = true;
                visited[y - 1][x][y][x] = true;
                y = y - 1;
                answer++;
            }
            else{
                y = y - 1;
            }
        }
        else if (dirs[i] == 'D'){
            if(y + 1 > 10)
                continue;
            if(!visited[y][x][y + 1][x]){
                visited[y][x][y + 1][x] = true;
                visited[y + 1][x][y][x] = true;
                y = y + 1;
                answer++;
            }
            else{
                y = y + 1;
            }
        }
        else if (dirs[i] == 'R'){
            if(x + 1 > 10)
                continue;
            if(!visited[y][x][y][x + 1]){
                visited[y][x][y][x + 1] = true;
                visited[y][x + 1][y][x] = true;
                x = x + 1;
                answer++;
            }
            else{
                x = x + 1;
            }
        }
        else {
            if(x - 1 < 0)
                continue;
            if(!visited[y][x][y][x - 1]){
                visited[y][x][y][x - 1] = true;
                visited[y][x - 1][y][x] = true;
                x = x - 1;
                answer++;
            }
            else{
                x = x - 1;
            }  
        }
    }
    return answer;
}
