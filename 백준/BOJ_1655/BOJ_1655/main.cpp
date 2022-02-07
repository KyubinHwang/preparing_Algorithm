#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    cin >> N;
    
    for(int i = 0;i < N;i++){
        int temp;
        cin >> temp;
        if(maxHeap.empty())
            maxHeap.push(temp);
        else{
            if(maxHeap.size() > minHeap.size())
                minHeap.push(temp);
            else
                maxHeap.push(temp);
            
            if(maxHeap.top() > minHeap.top()){
                int x = maxHeap.top();
                int y = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(y);
                minHeap.push(x);
            }
        }
        cout << maxHeap.top() << "\n";
    }
    
    return 0;
}
