#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int dp[501][501];
vector <vector <int>> v(500, vector<int>(500));


int main(int argc, const char * argv[]) {

    int temp;
    cin >> n;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++)
        {
            cin >> temp;
            v[i][j] = temp;
        }
    }
    
    for(int i = n - 1;i >= 0;i--){
        for(int j = i;j >= 0;j--){
            if(i == n - 1)
                dp[i][j] = v[i][j];
            else{
                dp[i][j] = max(dp[i + 1][j],dp[i + 1][j + 1]) + v[i][j];
            }
        }
    }
    
    cout << dp[0][0] << "\n";

    return 0;
}
