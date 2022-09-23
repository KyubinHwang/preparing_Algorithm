#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack <char> st;

    for(int i = 0;i < s.size();i++){
        if(i == 0){
            if (s[i] == ')'){
                return false;
            }
            else{
                st.push(s[i]);
            }
        }
        else{
            if(s[i] == '(')
                st.push(s[i]);
            else{
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
    }

    if (!st.empty())
        return false;
    else
        return true;
}