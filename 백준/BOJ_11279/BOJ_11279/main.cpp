#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    priority_queue<int> q;
    cin >> N;
    for(int i = 0;i < N;i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(q.empty())
                cout << 0 << "\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else{
            q.push(temp);
        }
    }
    return 0;
}
