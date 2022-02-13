#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int N;

int main(int argc, const char * argv[]) {
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cin >> N;
    for(int i = 0;i < N;i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(maxHeap.empty() && minHeap.empty()){
                cout << 0 << "\n";
            }
            else{
                if(maxHeap.empty()){
                    cout << minHeap.top() << "\n";
                    minHeap.pop();
                }
                else if(minHeap.empty())
                {
                    cout << maxHeap.top() << "\n";
                    maxHeap.pop();
                }
                else if(abs(maxHeap.top()) > abs(minHeap.top()))
                {
                    cout << minHeap.top() << "\n";
                    minHeap.pop();
                }
                else{
                    cout << maxHeap.top() << "\n";
                    maxHeap.pop();
                }
            }
        }
        else{
            if(temp > 0)
                minHeap.push(temp);
            else
                maxHeap.push(temp);
        }
    }
    return 0;
}
