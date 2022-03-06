#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int area[301][301];

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> area[i][j];
        }
    }
    
    int dp[301][301];
    
    for(int i = 0;i < N;i++){
        if(i == 0)
            dp[i][0] = area[0][0];
        else
            dp[i][0] = dp[i - 1][0] + area[i][0];
    }
    
    for(int i = 0;i < M;i++){
        if(i == 0)
            dp[0][i] = area[0][0];
        else
            dp[0][i] = dp[0][i - 1] + area[0][i];
    }
    
    for(int i = 1;i < N;i++){
        for(int j = 1;j < M;j++){
            dp[i][j] = max(dp[i][j - 1] + area[i][j], dp[i - 1][j] + area[i][j]);
        }
    }
    
    cout <<  dp[N - 1][M - 1] << "\n";
    
    return 0;
}
