#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}


int main(int argc, const char * argv[]) {
    
    int result = 0;
    int count = 0;
    
    cin >> N;
    vector <pair <int, int>> v(N);
    
    for(int i = 0;i < N;i++){
        int start, end;
        cin >> start >> end;
        v[i] = make_pair(start, end);
    }
    
    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), cmp);
    
    int end = v[0].second;
    
    while(count != N){
        if(count == 0)
            result++;
        else{
            if(end <= v[count].first){
                end = v[count].second;
                result++;
            }
        }
        count++;
    }
    
    cout << result << "\n";
    
    return 0;
}
