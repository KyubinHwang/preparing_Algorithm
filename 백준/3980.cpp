#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T;
int squad[11][11];
bool check[11];
int result = 0;

void backtracking(int dept, int ability){
    
    if(dept == 11){
        if(ability >= result)
            result = ability;
        return;
    }
    
    vector <pair<int, int>> maxPosition;
    for(int i = 0;i < 11;i++){
        if(squad[dept][i] != 0)
            maxPosition.push_back({squad[dept][i], i});
    }
    
    sort(maxPosition.begin(), maxPosition.end());
    
    for(int i = 0;i < maxPosition.size();i++){
        if(!check[maxPosition[i].second]){
            check[maxPosition[i].second] = true;
            backtracking(dept + 1, ability + maxPosition[i].first);
            check[maxPosition[i].second] = false;
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> T;
    while(T--){
        for(int i = 0;i < 11;i++){
            for(int j = 0;j < 11;j++){
                cin >> squad[i][j];
            }
        }
        backtracking(0, 0);
        cout << result << "\n";
        result = 0;
        for(int i = 0;i < 11;i++){
            check[i] = false;
        }
    }
    return 0;
}
