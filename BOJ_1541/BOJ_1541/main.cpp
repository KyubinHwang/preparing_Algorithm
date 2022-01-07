#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    string s;
    string resultString = "";
    int result = 0;
    bool check = false;
    cin >> s;

    for(int i = 0;i <= s.size();i++){
        if(s[i] == '-' || s[i] == '+' || s[i] == '\0'){
            if(check == true){
                result -= stoi(resultString);
            }
            else
                result += stoi(resultString);

            resultString = "";

            if(s[i] == '-')
                check = true;

            continue;
        }
        resultString.push_back(s[i]);
    }

    cout << result << "\n";


}

