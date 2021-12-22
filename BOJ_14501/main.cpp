#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> T(16);
vector <int> P(16);
vector <int> dp(16);

int main(int argc, const char * argv[]) {
    int N;
    int tmp1,tmp2;
    cin >> N;
    
    for(int i = 1;i <= N;i++){
        cin >> tmp1 >> tmp2;
        T[i] = tmp1;
        P[i] = tmp2;
    }
    for(int i = N; i >= 1; i--){
        if(i + T[i] - 1 > N){
            dp[i] = dp[i + 1];
            continue;
        }
        dp[i] = max(dp[i + T[i]] + P[i], dp[i+1]);
    }
    
    cout << dp[1] << "\n";
    
    return 0;
}
