#include <iostream>
#include <string>
using namespace std;

int main(){

	string S;
	cin >> S;
	int count[26];

	for (int i = 0; i < 26; i++)
		count[i] = -1;

	for (int i = 0; i < S.size(); i++)
	{
		if (count[S[i] - 'a'] == -1)
		{
			count[S[i] - 'a'] = i;
		}
	}

	for (int l = 0; l < 26; l++)
		cout << count[l] << " ";

	return 0;

}
