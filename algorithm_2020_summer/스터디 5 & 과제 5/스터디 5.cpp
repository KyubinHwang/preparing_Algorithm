#include <iostream>
#include <math.h>
using namespace std;


int main(){

	int T;
	int x1, x2, y1, y2;
	int r1, r2;
	int S = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if ((x1 == x2) && (y1 == y2))
		{

			if (r1 == r2)
			{
				S = -1;
			}
			else
			{
				S = 0;
			}
		}
		else
		{
			int D = pow(x1 - x2, 2) + pow(y1 - y2, 2);
			if (D > pow((r1 + r2), 2))
			{
				S = 0;
			}
			else if (D == pow((r1 + r2), 2))
				S = 1;
			else if (D < pow((r1 + r2), 2) && pow((r1 - r2),2) < D)
				S = 2;
			else if (D < pow((r1 + r2), 2) && pow((r1 - r2), 2) == D)
				S = 1;
			else
				S = 0;
		}
		cout << S << "\n";
	}
	
	return 0;

}