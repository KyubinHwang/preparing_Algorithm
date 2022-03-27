#include <iostream>
#include <queue>
using namespace std;
long long A, B;

long long BFS(){
    queue <pair <long long, long long>> q;
    q.push({A, 1});
    
    while(!q.empty()){
        long long a = q.front().first;
        long long b = q.front().second;
        q.pop();
        if(a == B)
            return b;
        if(a * 2 <= B){
            q.push({a * 2, b + 1});
        }
        if((a * 10) + 1 <= B){
            q.push({a * 10 + 1, b + 1});
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {

    cin >> A >> B;
    
    cout << BFS() << "\n";
    
    return 0;
}
