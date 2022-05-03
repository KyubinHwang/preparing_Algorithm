#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map <string, set<string>> m1;
    map <string, int> m2;

    for(int i = 0;i < report.size();i++){
        string shingo = report[i];
        int n = shingo.find(' ');
        string from(shingo, 0, n);
        string to(shingo, n , shingo.length());

        if(m1[from].find(to) == m1[from].end()){
            m2[to] += 1;
            m1[from].insert(to);
        }
    }

    for(int i = 0;i < id_list.size();i++){
        int cnt = 0;
        for(string str: m1[id_list[i]]){
            if(m2[str] >= k) 
                cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}t
