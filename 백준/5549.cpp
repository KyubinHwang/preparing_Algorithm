#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int M, N;
int K;
char temp;
char searchSpace[1001][1001];
int planetCount[1001][1001][3];
int dp[1001][1001][3];

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(planetCount, 0, sizeof(planetCount));
    memset(dp, 0, sizeof(dp));
    
    cin >> M >> N >> K;
    for(int i = 1;i <= M;i++){
        for(int j = 1;j <= N;j++){
            cin >> temp;
            searchSpace[i][j] = temp;
            if(searchSpace[i][j] == 'J'){
                planetCount[i][j][0]++;
            }
            else if(searchSpace[i][j] == 'O'){
                planetCount[i][j][1]++;
            }
            else{
                planetCount[i][j][2]++;
            }
            for(int k = 0;k < 3;k++){
                dp[i][j][k] = planetCount[i][j][k] + dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
            }
        }
    }

    for(int i = 0;i < K;i++){
        int jungle = 0, sea = 0, ice = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        jungle = dp[c][d][0] - dp[a - 1][d][0] - dp[c][b - 1][0] + dp[a - 1][b - 1][0];
        sea = dp[c][d][1] - dp[a - 1][d][1] - dp[c][b - 1][1] + dp[a - 1][b - 1][1];
        ice = dp[c][d][2] - dp[a - 1][d][2] - dp[c][b - 1][2] + dp[a - 1][b - 1][2];
        cout << jungle << " " << sea << " " << ice << "\n";
    }

    return 0;
}
