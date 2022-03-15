#include <iostream>
#include <stack>
using namespace std;
int N;
int tower[500001];

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    stack <pair<int, int>> s;
    
    for(int i = 1;i <= N;i++){
        cin >> tower[i];
        while(!s.empty()){
            int signal = s.top().first;
            int visit = s.top().second;
            if(signal >= tower[i])
            {
                cout << visit << " ";
                break;
            }
            s.pop();
        }
        if(s.empty())
            cout << 0 << " ";
        
        s.push({tower[i], i});
    }
    
    return 0;
}
