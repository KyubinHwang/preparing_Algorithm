#include <iostream>
#include <string>
using namespace std;

int main(){

	string wordth;
	int count = 0;
	cin >> wordth;

	for (int i = 0; i < wordth.size(); i++)
	{
		if (wordth[i] == 'c' && wordth[i + 1] == '=')
		{
			count++;
			i++;
		}
		else if (wordth[i] == 'c' && wordth[i + 1] == '-')
		{
			count++;
			i++;
		}
		else if (wordth[i] == 'd' && wordth[i + 1] == 'z' && wordth[i + 2] == '=')
		{
			count++;
			i = i + 2;
		}
		else if (wordth[i] == 'd' && wordth[i + 1] == '-')
		{
			count++;
			i++;
		}
		else if (wordth[i] == 'l' && wordth[i + 1] == 'j')
		{
			count++;
			i++;
		}
		else if (wordth[i] == 'n' && wordth[i + 1] == 'j')
		{
			count++;
			i++;
		}
		else if (wordth[i] == 's' && wordth[i + 1] == '=')
		{
			count++;
			i++;
		}
		else if (wordth[i] == 'z' && wordth[i + 1] == '=')
		{
			count++;
			i++;
		}
		else
		{
			count++;
		}
	}

	cout << count;

	return 0;

}