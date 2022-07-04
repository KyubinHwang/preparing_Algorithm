
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool binary_search(vector <int> stones, int mid, int k){
    int count = 0;

    for(int i = 0;i < stones.size();i++){
        if(stones[i] - mid <= 0)
            count++;
        else
            count = 0;

        if(count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int first = 1;
    int last = *max_element(stones.begin(), stones.end());

    while(first <= last){
        int mid = (first + last) / 2;

        if(binary_search(stones, mid, k))
            last = mid - 1;
        else
            first = mid + 1;
    }

    return first;
}
