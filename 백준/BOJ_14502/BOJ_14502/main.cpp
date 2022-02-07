#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <vector <int>> v(9, vector<int>(9));
int cnt = 0;
int N, M;
int result = 0;

void BFS(){
    
}

void wall(){
    if(cnt == 3){
        BFS();
    }
    for(int i  = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(v[i][j] == 0)
            {
                cnt++;
                v[i][j] = 0;
                wall();
                cnt--;
                v[i][j] = 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            int temp;
            cin >> temp;
            v[i][j] = temp;
        }
    }
    
    
    
    return 0;
}
