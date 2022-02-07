#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int N, M;

int main(int argc, const char * argv[]) {

    map<string, int> m;
    cin >> N >> M;
    vector <string> v;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        m.insert({s, i});
    }
    for(int i = 0;i < M;i++){
        string s;
        cin >> s;
        if(m.find(s) != m.end())
            v.push_back(s);
        else
            continue;
        
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i = 0;i < v.size();i++){
        cout << v[i] << "\n";
    }
    return 0;
}
