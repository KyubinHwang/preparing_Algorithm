#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
string v[65];

void pressed(int n, int a, int b){

    for(int i = a; i < a + n;i++){
        for(int j = b;j < b + n;j++){
            if(v[a][b] != v[i][j]){
                cout << "(";
                pressed(n / 2, a, b);
                pressed(n / 2, a, b + n / 2);
                pressed(n / 2, a + n / 2, b);
                pressed(n / 2, a + n /2, b + n / 2);
                cout << ")";

                return;
            }
        }
    }
    cout << v[a][b];
}

int main(int argc, const char * argv[]) {

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> v[i];
    }

    pressed(N, 0, 0);
    cout << "\n";
    return 0;
}
