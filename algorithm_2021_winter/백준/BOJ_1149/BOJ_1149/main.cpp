#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector <int>> v(1001, vector<int>(3));
int dp[1001][3];
int N;

int main(int argc, const char * argv[]) {

    int temp;
    cin >> N;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < 3;j++){
            cin >> temp;
            v[i][j] = temp;
        }
    }
    
    for(int i = 0;i < N;i++){
        if(i == 0){
            dp[i][0] = v[i][0];
            dp[i][1] = v[i][1];
            dp[i][2] = v[i][2];
        }
        else{
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
        }
    }

    cout << min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << "\n";
    return 0;
}
