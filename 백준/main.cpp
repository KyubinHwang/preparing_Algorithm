#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
int N;

struct cmp{
bool operator()(pair<int, int>&a, pair<int, int>&b) {
    return b.second > a.second;
  }
};

int main(int argc, const char * argv[]) {

    priority_queue <pair<int,int>, vector<pair<int, int>>, cmp> pq;

    cin >> N;

    for(int i = 0;i < N;i++){
        int d, w;
        cin >> d >> w;
        pq.push({d, w});
    }

    deque <int> dq;
    int deadLine = pq.top().first;
    while(!pq.empty()){
        if(dq.empty())
        {
            dq.push_back(pq.top().second);
            deadLine = pq.top().first;
            pq.pop();
        }
        else{
            if(deadLine > dq.size()){
                if(deadLine > pq.top().first){
                    dq.push_front(pq.top().second);
                    pq.pop();
                }
                else{
                    dq.push_back(pq.top().second);
                    deadLine = pq.top().first;
                    pq.pop();
                }
            }
            else{
                if(pq.top().first > deadLine)
                {
                    deadLine = pq.top().first;
                    dq.push_back(pq.top().second);
                    pq.pop();
                }
                else{
                    pq.pop();
                }
            }
        }
    }
    int result = 0;

    while(!dq.empty()){
        result += dq.front();
        dq.pop_front();
    }

    cout << result << "\n";
    
    return 0;
}
