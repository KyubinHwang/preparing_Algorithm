#include <iostream>
#include <vector>
using namespace std;
int N;

int main(int argc, const char * argv[]) {
  
    cin >> N;
    vector <vector <int>> v(N + 1, vector<int>(N + 1));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> v[i][j];
        }
    }
    
    for(int m = 0;m < N;m++){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(v[i][m] && v[m][j]){
                    v[i][j] = 1;
                }
            }
        }
    }
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cout << v[i][j] << " " ;
        }
        cout << "\n";
    }
    
    return 0;
}
