#include <iostream>
#include <vector>
using namespace std;
int N;
vector <vector <int>> v(128,vector<int>(128));
int blueCount = 0;
int whiteCount = 0;

void divide(int n, int x, int y){
    
    for(int i = x;i < x + n;i++){
        for(int j = y;j < y + n;j++){
            if(v[x][y] != v[i][j]){
                divide(n / 2, x, y);
                divide(n / 2, x + n / 2, y);
                divide(n / 2, x, y + n / 2);
                divide(n / 2, x + n / 2, y + n / 2);
                
                return;
            }
        }
    }
    if(v[x][y] == 1)
        blueCount++;
    else
        whiteCount++;
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    for(int i = 0;i < N; i++){
        for(int j = 0;j < N; j++){
            cin >> v[i][j];
        }
    }
    
    divide(N, 0, 0);
    
    cout << whiteCount << "\n" << blueCount << "\n";
    
    return 0;
}
