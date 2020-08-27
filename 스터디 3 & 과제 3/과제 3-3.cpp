#include <iostream>
using namespace std;

int main(){ 

	int A,B;
	int M= 1;
	int max = 0;
	int min = 1;

	cin >> A >> B;
	
	if (A > B)
	{
		for (int i = 0; i < A; i++)
		{
			if ((A % M == 0) && (B % M == 0))
			{
				max = M;
			}
			M++;
		} 
	}
	else
	{
		for (int j = 0; j < B; j++)
		{
			if ((A%M == 0) && (B%M == 0))
			{
				max = M;
			}
			M++;
		}
	}

	min = A / max * B ;

	cout << max << "\n" << min;

	return 0;

}

