#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, k;
	cin >> N >> k;
	queue<int> survivors;

	for (int i = 0; i < N; i++)
	{
		survivors.push(i+1);
	}

	cout << "<";
	
	while (!survivors.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			survivors.push(survivors.front());
			survivors.pop();
		}
		if (survivors.size() != 1)
			cout << survivors.front() << ", ";
		else
			cout << survivors.front();
		survivors.pop();
	}
	cout << ">";

	return 0;

}