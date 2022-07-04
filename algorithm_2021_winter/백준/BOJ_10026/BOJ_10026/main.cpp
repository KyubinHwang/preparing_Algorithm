#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<vector <char>> v(101,vector <char>(101));
vector<vector <bool>> check(101, vector <bool>(101));
int N;

void dfs(int n, int m, char RGB){
    
    check[n][m] = true;
    
    if((m + 1) != N && v[n][m + 1] == RGB && check[n][m + 1] == false){
        dfs(n, m + 1, RGB);
    }
    
    if((n + 1) != N && v[n + 1][m] == RGB && check[n + 1][m] == false){
        dfs(n + 1, m, RGB);
    }
    
    if((n - 1) >= 0 && v[n - 1][m] == RGB && check[n - 1][m] == false){
        dfs(n - 1, m, RGB);
    }
    
    if((m - 1) >= 0 && v[n][m - 1] == RGB && check[n][m - 1] == false){
        dfs(n, m - 1, RGB);
    }
    
}

int main(int argc, const char * argv[]) {
    
    int result1 = 0;
    int result2 = 0;
    string s;
    cin >> N;
    
    for(int i = 0;i <N;i++){
        cin >> s;
        for(int j = 0;j < N;j++){
            v[i][j] = s[j];
        }
    }
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(check[i][j] == false){
                dfs(i, j, v[i][j]);
                result1++;
            }
        }
    }
    
    for(int i = 0;i <N;i++){
        for(int j = 0;j < N;j++){
            check[i][j] = false;
        }
    }
    
    for(int i = 0;i <N;i++){
        for(int j = 0;j < N;j++){
            if(v[i][j] == 'G')
                v[i][j] = 'R';
        }
    }
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(check[i][j] == false){
                dfs(i, j, v[i][j]);
                result2++;
            }
        }
    }
    
    cout << result1++ << " " << result2 << "\n";
    
    return 0;
}
