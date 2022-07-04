#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue <pair<int, int>> q;
    q.push({numbers[0], 1});
    q.push({-numbers[0], 1});
    
    while(!q.empty()){
        int num = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if(count == numbers.size()){
            if(num == target)
                answer++;
        }
        else{
            q.push({num + numbers[count], count + 1});
            q.push({num - numbers[count], count + 1});
        }
    }
    
    return answer;
}