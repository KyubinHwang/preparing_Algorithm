#include <iostream>
#include <algorithm>
using namespace std;
int sortshortguy[9];

int main(){
	
	int sum = 0;
	int shortguy[9];
	int check = 0;
	int q, w;
	
	
	cin >> shortguy[0] >> shortguy[1] >> shortguy[2] >> shortguy[3] >> shortguy[4] 
		>> shortguy[5] >> shortguy[6] >> shortguy[7] >> shortguy[8];
	
	for (int i = 0; i < 9; i++){
		sum += shortguy[i];
	}
	sum = sum - 100;
	for (int j = 0; j < 8; j++){
		for (int l = j + 1; l < 9; l++)
		{
			if (sum == shortguy[j] + shortguy[l]){
				q = j; w = l;
				check = 1;
				break;
			}
			
		}
		if (check == 1)
			break;
	}
	for (int R = 0; R < 9; R++){
		if (R == q || R == w){	; }
		else
			sortshortguy[R] = shortguy[R];
	}
	sort(sortshortguy, sortshortguy + 9);

	for (int C = 2; C < 9; C++){ 
		cout << sortshortguy[C] << "\n"; 
	}
	return 0;

}
