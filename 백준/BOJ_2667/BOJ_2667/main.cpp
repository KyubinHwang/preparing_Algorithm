#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
int X[4] = {1, 0, -1, 0};
int Y[4] = {0, -1, 0, 1};
int house[26][26];
bool visited[26][26];
int N;
using namespace std;
vector <int> answer;
queue<pair <int, int>> q;

void BFS(){
    
    int count = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0;i < 4;i++){
            int dx = x + X[i];
            int dy = y + Y[i];
            if(dy >= 0 && dy < N && dx >= 0 && dx < N && !visited[dy][dx] && house[dy][dx] == 1){
                q.push({dy, dx});
                visited[dy][dx] = true;
                count++;
            }
        }
    }
    answer.push_back(count);
}

int main(int argc, const char * argv[]) {
    
    int countHouse = 0;
    cin >> N;
    for(int i = 0;i < N;i++){
        string temp;
        cin >> temp;
        for(int j = 0;j < N;j++){
            house[i][j] = (int)temp[j] - 48;
        }
    }
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(house[i][j] == 1 && !visited[i][j]){
                q.push({i, j});
                visited[i][j] = true;
                BFS();
                countHouse++;
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << countHouse << "\n";
    for(int i = 0;i < countHouse;i++){
        cout << answer[i] << "\n";
    }
    
    return 0;
}
