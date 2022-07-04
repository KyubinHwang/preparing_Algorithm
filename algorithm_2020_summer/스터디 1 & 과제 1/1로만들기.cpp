#include <iostream>
using namespace std;
int n;
int dp[1000000];

void solution(){
	
	dp[1] = 0;

	for (int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + 1; //1�� �� ���
		if (i % 2 == 0 && dp[i] > dp[i/2] + 1){
			dp[i] = dp[i / 2] + 1;
		} //2�� ���� ���
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1){
			dp[i] = dp[i / 3] + 1;
		}//3���� ���� ���
	}

}


int main(){

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >> n;
	solution();
	cout << dp[n];

	return 0;

}