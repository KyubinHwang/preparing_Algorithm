#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, k;
    char c;
    int n;
    
    cin >> T;
    
    for(int i = 0;i < T;i++){
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        map <int, int> m;
        
        cin >> k;
        for(int j = 0;j < k;j++){
            cin >> c >> n;
            if(c == 'I')
            {
                minHeap.push(n);
                maxHeap.push(n);
                
                if(m.count(n) == 0)
                    m[n] = 1;
                else
                    m[n]++;
            }
            else
            {
                if(n == 1){
                    while(!maxHeap.empty() && m[maxHeap.top()] == 0)
                        maxHeap.pop();
                    if(!maxHeap.empty()){
                        m[maxHeap.top()]--;
                        maxHeap.pop();
                    }
                }
                else{
                    while(!minHeap.empty() && m[minHeap.top()] == 0)
                        minHeap.pop();
                    if(!minHeap.empty()){
                        m[minHeap.top()]--;
                        minHeap.pop();
                    }
                }
            }
        }
        
        while(!maxHeap.empty() && m[maxHeap.top()] == 0)
            maxHeap.pop();
        while(!minHeap.empty() && m[minHeap.top()] == 0)
            minHeap.pop();
        
        if(maxHeap.empty() || minHeap.empty())
            cout << "EMPTY" << "\n";
        else
            cout << maxHeap.top() << " " << minHeap.top() << "\n";
        
    }
    
    return 0;
}
