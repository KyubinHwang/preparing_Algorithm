#include <iostream>
#include <queue>
using namespace std;
long long A[5000001];

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, L;
    cin >> N >> L;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i = 1;i <= N;i++){
        cin >> A[i];
        pq.push({A[i], i});
        while(pq.top().second < i - L + 1)
            pq.pop();
        cout << pq.top().first << " ";
    }
    
    return 0;
}
