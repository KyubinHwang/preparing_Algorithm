#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

	string W;
	int word[26];
	int s = 0;
	int max = 0;

	cin >> W;
	
	for (int i = 0; i < 26; i++)
		word[i] = 0;

	for (int i = 0; i < W.size(); i++){
		for (int j = 0; j < 26; j++)
		{
			if ((W[i] == (j + 65)) || (W[i] == (j + 97)))
			{
				word[j] += 1;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (word[i] > max)
		{
			max = word[i];
			s = i;
		}	
	}
	
	char T = s + 65;

	sort(word, word + 26);

	if (word[25] == word[24])
		cout << "?";
	else
		cout << T;


	return 0;
}