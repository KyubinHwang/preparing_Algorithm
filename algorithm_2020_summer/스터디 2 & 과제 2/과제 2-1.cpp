#include <iostream>
#include <string>
using namespace std;

int main(){

	int count = 0;
	string word;

	getline(cin,word);
	for (size_t i = 0; i < word.size(); i++){
		if ((i != 0 && word[i] == ' ')||(i != 0 && i == word.size()-1))
		{
			count++;
		}
	}
	cout << count;

	return 0;
}