#include <iostream>
#include <string>
using namespace std;

int main(){

	int x, y;
	int day = 0;
	string S[7];

	S[0] = "MON"; S[1] = "TUE"; S[2] = "WED"; S[3] = "THU"; S[4] = "FRI"; S[5] = "SAT"; S[6] = "SUN";

	cin >> x >> y;

	for (int i = 1; i < x; i++){
		if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 12))
		{
			day += 31;
		}
		else if ((i == 4) || (i == 6) || (i == 9) || (i == 11))
		{
			day += 30;
		}
		else if (i == 2)
			day += 28;
	}

	if (x == 1)
		cout << S[(y - 1) % 7];
	else
		cout << S[(day + y - 1) % 7];

	return 0;

}