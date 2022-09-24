#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int i = 0;
    while (people.size() > i){
        int back = people.back();
        people.pop_back();

        if(people[i] + back <= limit){
            answer += 1;
            i++;
        }
        else {
            answer += 1;
        }
    }

    return answer;
}