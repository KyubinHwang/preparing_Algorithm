#include <iostream>
#include <vector>
using namespace std;
int N;
int v[2188][2188];
int answer[3];

void paper(int n, int a, int b){
    
    for(int i = a;i < a + n;i++){
        for(int j = b;j < b + n;j++){
            if(v[a][b] != v[i][j]){
                paper(n / 3, a, b);
                paper(n / 3, a, b + n / 3);
                paper(n / 3, a, b + 2 * n / 3);
                paper(n / 3, a + n / 3, b);
                paper(n / 3, a + n / 3, b + n / 3);
                paper(n / 3, a + n / 3, b + 2 * n / 3);
                paper(n / 3, a + 2 * n / 3, b);
                paper(n / 3, a + 2 * n / 3, b + n / 3);
                paper(n / 3, a + 2 * n / 3, b + 2 * n / 3);
                return;
            }
        }
    }
    answer[v[a][b] + 1]++;
    return;
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> v[i][j];
        }
    }
    
    paper(N, 0, 0);
    
    for(int i = 0;i < 3;i++)
        cout << answer[i] << "\n";
    
    return 0;
}
