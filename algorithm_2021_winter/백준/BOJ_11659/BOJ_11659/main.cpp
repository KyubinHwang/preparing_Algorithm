#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector <int> v(100001);
int N, M;

int main(int argc, const char * argv[]) {

    int result = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    v[0] = 0;
    for(int i = 1;i <= N;i++){
        int temp;
        cin >> temp;
        result += temp;
        v[i] = result;
    }
        
    for(int i = 0;i < M;i++){
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a - 1];
        cout << "\n";
    }
    
    return 0;
}
