#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, M, N, x, y;

int main(int argc, const char * argv[]) {

    cin >> T;
    
    for(int i = 0;i < T;i++){
        bool check = false;
        cin >> M >> N >> x >> y;
        x = x - 1;
        y = y - 1;
        for(int j = x;j < (M * N); j+= M){
            if(j % N == y){
                check = true;
                cout << j + 1 << "\n";
                break;
            }
        }
        if(check == false) cout << "-1\n";
    }
    return 0;
}
