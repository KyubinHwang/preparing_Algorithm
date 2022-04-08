#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int result = 0;
vector <pair<int, int>> v;

void eggBreaking(int count){
    if(count == N){
        int brokenegg = 0;
        for(int i = 0;i < N;i++){
            if(v[i].first <= 0) brokenegg++;
        }
        
        result = max(result, brokenegg);
        return;
    }
    bool check = false;
    for(int i = 0;i < N;i++){
        if(count == i)
            continue;
        if(v[count].first > 0 && v[i].first > 0) {
            v[count].first -= v[i].second;
            v[i].first -= v[count].second;
            check = true;
            eggBreaking(count + 1);
            v[count].first += v[i].second;
            v[i].first += v[count].second;
        }
    }
    if (!check) eggBreaking(count + 1);
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    for(int i = 0;i < N;i++){
        int S, W;
        cin >> S >> W;
        v.push_back({S, W});
    }
    
    eggBreaking(0);
    
    cout << result << "\n";
    
    return 0;
}
