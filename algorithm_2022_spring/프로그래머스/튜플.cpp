#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool asc(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    vector<int> v2;
    bool visited[1000001] = {false, };

    for(int i = 1;i < s.length() - 1;i++){
        if(s[i] == '{'){
            int temp = i + 1;
            string num = "";
            while(s[temp] != '}'){
                if(s[temp] == ',')
                {
                    v2.push_back(stoi(num));
                    temp++;
                    num = "";
                    continue;
                }
                num += s[temp];
                temp++;
            }
            v2.push_back(stoi(num));
            v.push_back(v2);
            v2.clear();
            i = temp + 1;
        }
    }
    sort(v.begin(),v.end(), asc);

    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v[i].size();j++){
            if(!visited[v[i][j]]){
                answer.push_back(v[i][j]);
                visited[v[i][j]] = true;
            }
        }
    }

    return answer;
}
