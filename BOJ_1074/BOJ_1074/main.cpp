#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int> v(15);
int result = 0;
int N, r, c;

void divide(int x, int R, int C){
    
    if(x == 0)
        return;
    
    if(r <= R && c <= C){
        v[x - 1] = 0;
        divide(x - 1, R - pow(2, x - 2), C - pow(2, x - 2));
    }
    else if(r <= R && c > C){
        v[x - 1] = 1;
        divide(x - 1, R - pow(2, x - 2), C + pow(2, x - 2));
    }
    else if(r > R && c <= C){
        v[x - 1] = 2;
        divide(x - 1, R + pow(2, x - 2), C - pow(2, x - 2));
    }
    else{
        v[x - 1] = 3;
        divide(x - 1, R + pow(2, x - 2), C + pow(2, x - 2));
    }
        
}

void conquer(){
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < v[i];j++){
            result += (pow(2,i) * pow(2,i));
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> N >> r >> c;
    int R = pow(2, N - 1) - 1;
    int C = pow(2, N - 1) - 1;
    divide(N, R, C);
    conquer();
    
    cout << result << "\n";
    
    return 0;
}
