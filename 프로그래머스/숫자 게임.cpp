#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue <int, vector<int>, greater<int>> pq;
    sort(A.begin(), A.end());
    for(int i = 0;i < B.size();i++){
        pq.push(B[i]);
    }
    int index = 0;
    for(int i = 0;i < B.size();i++){
        int x = pq.top();
        pq.pop();
        if(A[index] < x){
            index++;
            answer++;
        }
    }
    return answer;
}
