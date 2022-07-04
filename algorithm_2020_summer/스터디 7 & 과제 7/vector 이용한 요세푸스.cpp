#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, k;
	vector <int> v;
	vector <int> v2;
	vector<int>::iterator it;
	
	cin >> N >> k;
	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}

	cout << "<";
	while (!v.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			v.push_back(v[0]);
			it = v.begin();
			v.erase(it);
		}
		v2.push_back(v[0]);
		it = v.begin();
		v.erase(it);
	}
	for (int i = 0; i < N; i++)
	{
		if (i == N-1)
			cout << v2[i];
		else
			cout << v2[i] << ", ";
	}
	cout << ">";
	return 0;

}