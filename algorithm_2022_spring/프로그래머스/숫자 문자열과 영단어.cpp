#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    string word = "";

    for(int i = 0;i < s.length();i++){
        if(s[i] >= 48 && s[i] <= 57)
        {
            temp += s[i];
        }
        else{
            word += s[i];
            if(word == "zero"){
                temp += '0';
                word = "";
            }
            else if(word == "one"){
                temp += '1';
                word = "";
            }
            else if(word == "two"){
                temp += '2';
                word = "";
            }
            else if(word == "three"){
                temp += '3';
                word = "";
            }
            else if(word == "four"){
                temp += '4';
                word = "";
            }
            else if(word == "five"){
                temp += '5';
                word = "";
            }
            else if(word == "six"){
                temp += '6';
                word = "";
            }
            else if(word == "seven"){
                temp += '7';
                word = "";
            }
            else if(word == "eight"){
                temp += '8';
                word = "";
            }
            else if(word == "nine"){
                temp += '9';
                word = "";
            }
        }
    }
    answer = stoi(temp);
    return answer;
}
