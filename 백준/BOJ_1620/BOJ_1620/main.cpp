#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int N, M;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string poketmon;
    cin >> N >> M;
    
    vector<pair<string, int>> v(N + 1);
    map<string, int> m;
    
    for(int i = 1; i <= N;i++){
        cin >> poketmon;
        m.insert(make_pair(poketmon, i));
        v[i] = make_pair(poketmon, i);
    }
    
    for(int i = 1;i <= M;i++){
        string question;
        cin >> question;
        if(isdigit(question[0]) == true)
            cout << v[stoi(question)].first << "\n";
        else{
            cout << m[question] << "\n";
        }
    }
    
    return 0;
}
