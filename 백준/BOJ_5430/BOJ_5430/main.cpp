#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
using namespace std;
int T, n;

int main(int argc, const char * argv[]) {
    
    cin >> T;
    
    while(T){
        string p;
        string testArray;
        bool check = true;
        bool reverse = false;
        cin >> p >> n >> testArray;
        deque <int> dq;
        vector <char> v(p.length());
        for(int i = 0;i < p.length();i++){
            v[i] = p[i];
        }
        for(int i = 0;i < testArray.length();i++){
            string num = "";
            if(testArray[i] != ',' && testArray[i] != '[' && testArray[i] != ']'){
                while(testArray[i] != ',' && testArray[i] != '[' && testArray[i] != ']'){
                    num += testArray[i];
                    i++;
                }
            }
            if(num != "")
                dq.push_back(stoi(num));
        }
        
        for (int i = 0; i < v.size(); i++) {
            if(v[i] == 'R'){
                if(reverse == true)
                    reverse = false;
                else
                    reverse = true;
            }
            else if(v[i] == 'D'){
                if(dq.empty())
                {
                    check = false;
                    break;
                }
                else{
                    if(reverse == true)
                        dq.pop_back();
                    else
                        dq.pop_front();
                }
            }
        }
        
        if(check == false)
            cout << "error" << "\n";
        else{
            cout << "[";
            if(reverse){
                for(int i = (dq.size() - 1);i >= 0;i--){
                    if(i != 0)
                        cout << dq[i] << ",";
                    else
                        cout << dq[i];
                }
            }
            else{
                for(int i = 0;i < dq.size();i++){
                    if(i != dq.size() - 1)
                        cout << dq[i] << ",";
                    else
                        cout << dq[i];
                }
            }
            cout << "]\n";
        }
        T--;
    }
    
    return 0;
}
