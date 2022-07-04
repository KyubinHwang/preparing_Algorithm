#include <iostream>
#include <vector>
using namespace std;
int N;
double dir[4];
bool visited[30][30];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, -1, 1};
double result = 0.0;

void DFS(int dept, int x, int y, double per){

    if(dept == N){
        result += per;
        return;
    }
    for(int i = 0;i < 4;i++){
        int dx = x + X[i];
        int dy = y + Y[i];
        if (visited[dy][dx] || dir[i] == 0)
            continue;
        visited[y][x] = true;
        DFS(dept + 1, dx, dy, per * dir[i]);
        visited[y][x] = false;
    }
}

int main(int argc, const char * argv[]) {

    cin >> N;
    for(int i = 0;i < 4;i++){
        cin >> dir[i];
        dir[i] = dir[i] / 100;
    }

    cout.precision(10);
    cout << fixed;

    visited[N][N] = true;
    DFS(0, N , N, 1.0);

    if(result == 1)
        cout << "1.0" << "\n";
    else
        cout << result << "\n";

    return 0;
}
