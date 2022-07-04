#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string word;
    string bomb;
    cin >> word >> bomb;
    string result = "";
    
    for(int i = 0;i < word.length();i++){
        result.push_back(word[i]);
        if(bomb[bomb.size() - 1] == result.back()){
            bool check = true;
            for(int j = 1;j <= bomb.size();j++){
                if(result[result.size()- j] != bomb[bomb.size()- j])
                    check = false;
            }
            if(check){
                for(int j = 0; j < bomb.size();j++){
                    result.pop_back();
                }
            }
        }
    }
    
    if(result == "")
        cout << "FRULA" << "\n";
    else
        cout << result << "\n";
    
    return 0;
}
