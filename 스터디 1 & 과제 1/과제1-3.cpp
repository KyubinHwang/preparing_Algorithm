#include <iostream>
#include <string>
using namespace std;

int main(){

	int A, B, C;
	int sum;
	int time[10] = { 0, };

	cin >> A >> B >> C;
	sum = A * B * C;
	string num = to_string(sum);
	int n = num.length();

	for (int i = 0; i < n; i++){
		for (int j = 0; j < 10; j++){			
			if (num[i] == (48+j))
			{
				time[j] += 1;
			}
		}
	}
		
	for (int j = 0; j < 10; j++)
		cout << time[j] << "\n";


	return 0;
}